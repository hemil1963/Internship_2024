
#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    virtual void display() = 0;
};

class RealImage : public Image {
private:
    string filename;

public:
    RealImage(const string& filename) : filename(filename) {
        loadImageFromDisk();
    }

    void display() override {
        cout << "Displaying image: " << filename << endl;
    }

    void loadImageFromDisk() {
        cout << "Loading image from disk: " << filename << endl;
    }
};

class ProxyImage : public Image {
private:
    RealImage* realImage;
    string filename;

public:
    ProxyImage(const string& filename) : realImage(nullptr), filename(filename) {}

    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main() {
    Image* image1 = new ProxyImage("image1.jpg");
    Image* image2 = new ProxyImage("image2.jpg");

    image1->display();
    image1->display();

    image2->display();

    delete image1;
    delete image2;

    return 0;
}
