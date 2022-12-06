
//
// Created by Allissa Hertz on 12/3/22.
//

#include "main.h"

vector<Picture> loadFromFilePictureData() {
    picture_db.Clear();
    string name;
    int year = 0;
    int nominations = 0;
    double rating = 0;
    int duration = 0;
    string genre1;
    string genre2;
    string release;
    int metacritic = 0;
    string synopsis;

    fstream picture_file;
    picture_file.open("../input/pictures.csv");
    vector<Picture> new_picture_vector;
    if(!picture_file){
        cerr<<"File not found\n";
        exit(EXIT_FAILURE);
    } else {
        string line;
        int i = 0;
        while (getline(picture_file, line, '\n')) {
            if (i > 0) { //skipping the first line, because it contains the column names.
                vector<string> temp_picture_record = splitString(line, ',');
                Picture picture(name, year, nominations, rating, duration, genre1, genre2, release, metacritic,synopsis);
                picture.setName(temp_picture_record[0]);
                if (temp_picture_record[1] == "" || temp_picture_record[1] == "-"){
                    picture.setYear(-1);
                }
                else {
                    picture.setYear(stoi(temp_picture_record[1]));
                }
                if (temp_picture_record[2] == "" || temp_picture_record[2] == "-"){
                    picture.setNominations(-1);
                }
                else {
                    picture.setNominations(stoi(temp_picture_record[2]));
                }
                if (temp_picture_record[3] == "" || temp_picture_record[3] == "-"){
                    picture.setRating(-1);
                }
                else {
                    picture.setRating(stod(temp_picture_record[3]));
                }
                if (temp_picture_record[4] == "" || temp_picture_record[4] == "-"){
                    picture.setDuration(-1);
                }
                else {
                    picture.setDuration(stoi(temp_picture_record[4]));
                }
                picture.setGenre1(temp_picture_record[5]);
                picture.setGenre2(temp_picture_record[6]);
                picture.setRelease(temp_picture_record[7]);

                if (temp_picture_record[8] == "" || temp_picture_record[8] == "-"){
                    picture.setMetacritic(-1);
                }
                else {
                    picture.setMetacritic(stoi(temp_picture_record[8]));
                }
                picture.setSynopsis(temp_picture_record[9]);
                //Add all of the objects to a bst
                picture_db.Insert(picture);
                cout << "Data loaded: \n" << picture.print() << endl;
            }
            i++;
        }
    }
    return new_picture_vector;
}

void addPictureRecord() {

    string input_name;
    int input_year;
    int input_nominations;
    double input_rating;
    int input_duration;
    string input_genre1;
    string input_genre2;
    string input_release;
    int input_metacrtic;
    string input_synopsis;

    cout << "What was the name of the film? ";
    cin >> input_name;
    cout << "What year was the award won? Enter a four-digit integer. For example, “1976”.";
    cin >> input_year;
    cout << "How many nominations did the film receive?";
    cin >> input_nominations;
    cout << "What was the rating of the film? Enter a two-digit decimal. For example, “1.4”.";
    cin >> input_rating;
    cout << "What was the duration of the film? Enter a whole number that represents the running time of the film in minutes. For example, “145”.";
    cin >> input_duration;
    cout << "What was the main genre of the film?";
    cin >> input_genre1;
    cout << "What was the secondary genre of the film?";
    cin >> input_genre2;
    cout << "What year was the film released? Enter a two-digit integer to represent the year. For example, “89”.";
    cin >> input_release;
    cout << "What was the metacritic review score? For example, For example, “89”.";
    cin >> input_metacrtic;
    cout << "Please enter a short synopsis of the film.";
    cin >> input_synopsis;

    Picture picture(input_name, input_year, input_nominations, input_rating, input_duration, input_genre1, input_genre2, input_release, input_metacrtic, input_synopsis);
    picture.setName(input_name);
    picture.setYear(input_year);
    picture.setNominations(input_nominations);
    picture.setRating(input_rating);
    picture.setDuration(input_duration);
    picture.setGenre1(input_genre1);
    picture.setGenre2(input_genre2);
    picture.setRelease(input_release);
    picture.setMetacritic(input_metacrtic);
    picture.setSynopsis(input_synopsis);

    picture_db.Insert(picture);
    cout << "Added entry to database: \n" << picture.print() << endl;
}

void searchPicture(){
    //TODO: Requirement is to have an exact and partial search
    string picture_search_input;
    cout << "What would you like to search for? Enter the name of the film";
    cin >> picture_search_input;

    //TODO: find function needs to be added to BST. Henok is going to write this and then we can do picture_db.Find

    //TODO: Once field is found, let them modify if it was the winner or not
    //we don't need to let them modify or delete every field
    //if picture is found modify the winner
    //else return - movie not found

    //TODO: Once field is found, let them delete the entire object

}

void modifyPicture(){
    //TODO: Once field is found, let them modify if it was the winner or not
    //we don't need to let them modify or delete every field -
    //if picture is found modify the winner
    //else return - movie not found

}

void sortPicture() {
    //TODO: Sort by name. You need to sort from left most sub tree to right to get the output

}

void saveCSVPicture() {

    //TODO: Need to save csv to file. This is not fully implemented, I just started some of the logic
}
