#include<iostream>
#include<cstring>
using namespace std;

class Song {
public:
    char title[100];
    char artist[50];
    float duration;
    Song *next;

    Song() {
        strcpy(title, "");
        strcpy(artist, "");
        duration = 0.0;
        next = NULL;
    }

    Song(const char *t, const char *a, float d) {
        strcpy(title, t);
        strcpy(artist, a);
        duration = d;
        next = NULL;
    }

    void display() {
        cout << "Title: " << title << ", Artist: " << artist << ", Duration: " << duration << " mins" << endl;
    }
};

class Playlist {
    Song *head;

public:
    Playlist() {
        head = NULL;
    }

    void add_song(const char *t, const char *a, float d) {
        Song *new_song = new Song(t, a, d);
        if (head == NULL) {
            head = new_song;
        } else {
            Song *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_song;
        }
    }

    void display_playlist() {
        Song *temp = head;
        if (temp == NULL) {
            cout << "The Playlist is empty." << endl;
            return;
        }
        while (temp != NULL) {
            temp->display();
            temp = temp->next;
        }
    }
};

int main() {
    Playlist playlist;
    char cont = 'Y';
    char title[100], artist[50];
    float duration;

    while (cont == 'Y' || cont == 'y') {
        cout << "Enter the Song Title: ";
        cin.ignore();
        cin.getline(title, 100);
        cout << "Enter the Artist: ";
        cin.getline(artist, 50);
        cout << "Enter the Duration (in mins): ";
        cin >> duration;

        playlist.add_song(title, artist, duration);

        cout << "Do you want to add another song (Y/N)? ";
        cin >> cont;
    }

    cout << "\nCurrent Playlist:\n";
    playlist.display_playlist();

    return 0;
}
