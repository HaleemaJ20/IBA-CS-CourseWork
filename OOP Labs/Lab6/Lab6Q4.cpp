#include <iostream>
using namespace std;

class MediaFile {
protected:
    string fileName;
    double fileSize;
    string* metaData;

public:
    MediaFile(string name, double size) {
        fileName = name;
        fileSize = size;

        metaData = new string[3];
        metaData[0] = "Unknown Title";
        metaData[1] = "Unknown Artist";
        metaData[2] = "Unknown Genre";

        cout << "MediaFile constructor called for "
             << fileName << endl;
    }

    virtual void play() {
        cout << "Playing " << fileName << endl;
    }

    virtual void displayInfo() {
        cout << "File Name: " << fileName << endl;
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Title: " << metaData[0] << endl;
        cout << "Artist: " << metaData[1] << endl;
        cout << "Genre: " << metaData[2] << endl;
    }

    /*
    PART 1:
    Make this destructor NON-VIRTUAL to observe the issue.
    When deleting a derived object using a base pointer,
    only MediaFile destructor will run.
    Derived destructor will NOT run.
    This causes memory leak because derived dynamic memory
    is never deleted.
    */

    virtual ~MediaFile() {  
        delete[] metaData;
        cout << "MediaFile destructor called for "
             << fileName << endl;
    }
};



//AUDIO FILE
class AudioFile : public MediaFile {
private:
    string* audioFormat;

public:
    AudioFile(string name, double size, string format)
        : MediaFile(name, size)
    {
        audioFormat = new string(format);
        cout << "AudioFile constructor called" << endl;
    }

    void play() override {
        cout << "Playing audio file: "
             << fileName << endl;
    }

    void displayInfo() override {
        MediaFile::displayInfo();
        cout << "Audio Format: " << *audioFormat << endl;
    }

    ~AudioFile() {
        delete audioFormat;
        cout << "AudioFile destructor called" << endl;
    }
};



//VIDEO FILE
class VideoFile : public MediaFile {
private:
    string* resolution;
    int frameRate;

public:
    VideoFile(string name, double size,
              string res, int rate)
        : MediaFile(name, size)
    {
        resolution = new string(res);
        frameRate = rate;
        cout << "VideoFile constructor called" << endl;
    }

    void play() override {
        cout << "Playing video file: "
             << fileName << endl;
    }

    void displayInfo() override {
        MediaFile::displayInfo();
        cout << "Resolution: " << *resolution << endl;
        cout << "Frame Rate: " << frameRate << " fps" << endl;
    }

    ~VideoFile() {
        delete resolution;
        cout << "VideoFile destructor called" << endl;
    }
};

int main() {

    //PART 1: Non-Virtual Destructor Demonstration
    MediaFile* testFile = new AudioFile("song.mp3", 5.2, "MP3");
    delete testFile;

    /*
    If destructor is NON-VIRTUAL:
    Output shows only MediaFile destructor called.
    AudioFile destructor does not run.
    Therefore audioFormat memory is not deleted.
    This leads to memory leak.
    */


    //PART 2: Virtual Destructor Fix
    MediaFile* playlist[2];

    playlist[0] = new AudioFile("music.mp3", 4.5, "MP3");
    playlist[1] = new VideoFile("movie.mp4", 1500, "1080p", 60);

    cout << "\n--- Playing Files ---\n";
    for (int i = 0; i < 2; i++) {
        playlist[i]->play();
    }

    cout << "\n--- Deleting Files ---\n";
    for (int i = 0; i < 2; i++) {
        delete playlist[i];
    }

    /*
    With virtual destructor:
    Derived destructor runs first,
    then base destructor runs.
    All dynamically allocated memory is properly freed.
    This prevents memory leaks.
    */

    return 0;
}
