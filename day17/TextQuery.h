#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

using line_num = std::vector<std::string>::size_type;
class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream& infile); 
    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::unordered_map<std::string, std::shared_ptr<std::set<line_num>>> word_lines_ptr;
};

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, 
                std::shared_ptr<std::set<line_num>> p, 
                std::shared_ptr<std::vector<std::string>> f) :
                sought(s), lines(p), file(f) { }
    
    std::set<line_num>::const_iterator begin() const { return lines->begin(); }
    std::set<line_num>::const_iterator end() const { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
    
private:
    std::string sought;
    std::shared_ptr<std::set<line_num>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


#endif

