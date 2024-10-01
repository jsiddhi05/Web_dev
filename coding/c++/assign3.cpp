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

    void delete_song(const char *t) {
        if (head == NULL) {
            cout << "The Playlist is empty. No song to delete." << endl;
            return;
        }

        Song *temp = head;
        Song *prev = NULL;

        
        if (strcmp(head->title, t) == 0) {
            head = head->next;
            delete temp;
            cout << "Song '" << t << "' deleted from the playlist." << endl;
            return;
        }

        
        while (temp != NULL && strcmp(temp->title, t) != 0) {
            prev = temp;
            temp = temp->next;
        }

        
        if (temp == NULL) {
            cout << "Song '" << t << "' not found in the playlist." << endl;
            return;
        }

        
        prev->next = temp->next;
        delete temp;
        cout << "Song '" << t << "' deleted from the playlist." << endl;
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
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a Song\n";
        cout << "2. Delete a Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the Song Title: ";
                cin >> title;
                cout << "Enter the Artist: ";
                cin >> artist;
                cout << "Enter the Duration (in mins): ";
                cin >> duration;
                playlist.add_song(title, artist, duration);
                break;
            case 2:
                cout << "Enter the Song Title to delete: ";
                cin >> title;
                playlist.delete_song(title);
                break;
            case 3:
                playlist.display_playlist();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Enter a valid choice!" << endl;
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> cont;

    } while (cont == 'Y' || cont == 'y');

    return 0;
}
