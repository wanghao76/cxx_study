#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream& infile) : file(std::make_shared<std::vector<std::string>>())
{
    std::string text;
    std::istringstream record;
    std::string word;

    while (std::getline(infile, text)) {
        file->push_back(text);
        record.clear();
        record.str(text); 
        while (record >> word) {
            auto& lines = word_lines_ptr[word];
            if (!lines) {
                lines.reset(new std::set<line_num>);
            }
            lines->insert(file->size() - 1);
        }

    }
} 

QueryResult TextQuery::query(const std::string& sought) const
{
    static auto nodata = std::make_shared<std::set<line_num>>();
    auto loc = word_lines_ptr.find(sought);
    if (loc != word_lines_ptr.end()) {
        return QueryResult(sought, loc->second, file);
    } else {
        return QueryResult(sought, nodata, file);
    }
}

std::string make_plural(size_t ctr, const std::string& word, 
                                    const std::string& ending)
{
    return ctr > 1 ? word + ending : word;
}

std::ostream& print(std::ostream& os, const QueryResult& qs)
{
    os << qs.sought << " occurs " << qs.lines->size() << " " 
    << make_plural(qs.lines->size(), "time", "s") << std::endl;

    for (auto num : *qs.lines) {
        os << "\t(line " << num + 1 << ") "
        << *(qs.file->begin() + num) << std::endl;
    }

    return os;
}
