#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    string artist;
    float duration;
    Song* next;

    Song() {
        title = "";
        artist = "";
        duration = 0.0;
        next = NULL;
    }

    Song(string t, string a, float d) {
        title = t;
        artist = a;
        duration = d;
        next = NULL;
    }

    void display() {
        cout << "Title: " << title << ", Artist: " << artist << ", Duration: " << duration << " mins" << endl;
    }
};

class Playlist {
    Song* head;

public:
    Playlist() {
        head = NULL;
    }

    // Add song at the start
    void insert_start(string t, string a, float d) {
        Song* new_song = new Song(t, a, d);
        new_song->next = head;
        head = new_song;
    }

    // Add song at the end
    void insert_end(string t, string a, float d) {
        Song* new_song = new Song(t, a, d);
        if (head == NULL) {
            head = new_song;
            return;
        }
        Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_song;
    }

    // Remove a song by title
    void remove_song(string t) {
        if (head == NULL) {
            cout << "The Playlist is empty. No song to remove." << endl;
            return;
        }
        if (head->title == t) {
            Song* to_delete = head;
            head = head->next;
            delete to_delete;
            cout << "Song '" << t << "' removed from the playlist." << endl;
            return;
        }
        Song* temp = head;
        Song* prev = NULL;
        while (temp != NULL && temp->title != t) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Song '" << t << "' not found in the playlist." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Song '" << t << "' removed from the playlist." << endl;
    }

    // Display the entire playlist
    void display_playlist() {
        Song* temp = head;
        if (temp == NULL) {
            cout << "The Playlist is empty." << endl;
            return;
        }
        while (temp != NULL) {
            temp->display();
            temp = temp->next;
        }
    }

    // Play a specific song by title
    void play_song(string t) {
        Song* temp = head;
        while (temp != NULL) {
            if (temp->title == t) {
                cout << "Now playing: " << endl;
                temp->display();
                return;
            }
            temp = temp->next;
        }
        cout << "Song '" << t << "' not found in the playlist." << endl;
    }
};

int main() {
    Playlist playlist;
    char cont = 'Y';
    string title, artist;
    float duration;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a Song at the Start\n";
        cout << "2. Add a Song at the End\n";
        cout << "3. Remove a Song\n";
        cout << "4. Display the Entire Playlist\n";
        cout << "5. Play a Specific Song\n";
        cout << "6. Exit\n";
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
                playlist.insert_start(title, artist, duration);
                break;
            case 2:
                cout << "Enter the Song Title: ";
                cin >> title;
                cout << "Enter the Artist: ";
                cin >> artist;
                cout << "Enter the Duration (in mins): ";
                cin >> duration;
                playlist.insert_end(title, artist, duration);
                break;
            case 3:
                cout << "Enter the Song Title to remove: ";
                cin >> title;
                playlist.remove_song(title);
                break;
            case 4:
                playlist.display_playlist();
                break;
            case 5:
                cout << "Enter the Song Title to play: ";
                cin >> title;
                playlist.play_song(title);
                break;
            case 6:
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
