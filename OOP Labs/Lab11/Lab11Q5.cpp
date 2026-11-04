#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;

struct FileNode
{
    string name;
    bool isDirectory;
    long sizeBytes;
    time_t lastModified;
    vector<FileNode *> children;
};

void freeTree(FileNode *root)
{
    if (!root)
        return;
    for (auto child : root->children)
        freeTree(child);
    delete root;
}

string formatTime(time_t t)
{
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&t));
    return string(buffer);
}

void lsList(FileNode *dir)
{
    for (auto child : dir->children)
    {
        cout << setw(6) << left << (child->isDirectory ? "[DIR]" : "[FILE]")
             << setw(15) << left << child->name
             << setw(10) << right << child->sizeBytes << " B  "
             << formatTime(child->lastModified) << endl;
    }
}

void lsSortSize(FileNode *dir)
{
    auto temp = dir->children;
    sort(temp.begin(), temp.end(), [](FileNode *a, FileNode *b)
         { return a->sizeBytes > b->sizeBytes; });

    for (auto c : temp)
    {
        cout << c->name << " " << c->sizeBytes << endl;
    }
}

void lsSortTime(FileNode *dir)
{
    auto temp = dir->children;
    sort(temp.begin(), temp.end(), [](FileNode *a, FileNode *b)
         { return a->lastModified > b->lastModified; });

    for (auto c : temp)
    {
        cout << c->name << " " << formatTime(c->lastModified) << endl;
    }
}

long computeSize(FileNode *node)
{
    if (!node->isDirectory)
        return node->sizeBytes;

    long total = 0;
    for (auto c : node->children)
        total += computeSize(c);

    node->sizeBytes = total;
    return total;
}

void lsRecursive(FileNode *node, int depth)
{
    for (auto c : node->children)
    {
        cout << string(depth * 2, ' ') << c->name << endl;
        if (c->isDirectory)
            lsRecursive(c, depth + 1);
    }
}

int main()
{
    FileNode *root = new FileNode{"/home/student", true, 0, time(nullptr)};

    FileNode *docs = new FileNode{"docs", true, 0, time(nullptr)};
    FileNode *bin = new FileNode{"bin", true, 0, time(nullptr)};
    FileNode *proj = new FileNode{"projects", true, 0, time(nullptr)};

    root->children = {docs, bin, proj};

    root->children.push_back(new FileNode{"README.md", false, 2048, time(nullptr)});
    root->children.push_back(new FileNode{"notes.txt", false, 1024, time(nullptr)});

    docs->children.push_back(new FileNode{"file1.txt", false, 3000, time(nullptr)});
    docs->children.push_back(new FileNode{"file2.txt", false, 5000, time(nullptr)});
    docs->children.push_back(new FileNode{"file3.txt", false, 2000, time(nullptr)});

    cout << "\nls:\n";
    lsList(root);

    cout << "\nls -S:\n";
    lsSortSize(root);

    cout << "\nls -t:\n";
    lsSortTime(root);

    computeSize(root);

    cout << "\nls -R:\n";
    lsRecursive(root, 0);

    freeTree(root);
    return 0;
}