#include <iostream>

class Document {
public:
    virtual void printDocument() = 0;
};

class PDFDocument : public Document {
public:
    void printDocument() override {
        cout << "Printing PDF document." << endl;
    }
};

class WordDocument : public Document {
public:
    void printDocument() override {
        cout << "Printing Word document." << endl;
    }
};

void printDocument(Document* doc) {
    doc->printDocument();
}

int main() {
    PDFDocument* p = new PDFDocument();
    WordDocument* w = new WordDocument();

    printDocument(p);
    printDocument(w);

    return 0;
}

