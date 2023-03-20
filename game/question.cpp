#include "question.h"

Question::Question(std::string b, bool r) {
    this->body = b;
    this->result = r;
}

std::string Question::getBody() {
    return this->body;
}

bool Question::getResult() {
    return this->result;
}

void Question::setBody(std::string& b) {
    this->body = b;
}

void Question::setResult(bool& r) {
    this->result = r;
}