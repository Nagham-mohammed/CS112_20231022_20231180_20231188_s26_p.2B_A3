/* authors:Asmaa sayed mohammed --->20231022-->Gray scale,purple filter,detect edges, merge, darken_lighten , menu-->saiedasmaa590@gmail.com
 * Nagham Mohamed Mostafa--->20231188-->Invert Image,frame, blur image, sunny image ,Rotate Image-->mnagham17@gmil.com
 * Menna Mohamed Ashour--->20231180-->Flip Image,samurai(red image),resize image, crop image,Black white-->mm1881569@gmail.com
 */

// the purpose of our program : itis used to edit some photos by getting photos from the directory or from the pc and check if the photo is available or not

// link of diagram:https://docs.google.com/presentation/d/1V64hN-_o0kn6K7GIZJeH_YqVEPEakKdz/edit?usp=sharing&ouid=111393241023154631783&rtpof=true&sd=true

//link of github:https://github.com/Nagham-mohammed/CS112_20231022_20231180_20231188_s26_p.2B_A3




#include "Image_Class.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
string filename, filename2;
string editted;
Image image2, image1;
bool fileExists(const string& filename) {
    return fs::exists(filename);
}
bool fileExists2(const string& filename2) {
    return fs::exists(filename2);
}
void check_validation2(){

    try {
        // Check extension here and throw an exception if it's not valid
        if (filename2.substr(filename2.find_last_of(".") + 1) != "tga" &&
            filename2.substr(filename2.find_last_of(".") + 1) != "bmp" &&
            filename2.substr(filename2.find_last_of(".") + 1) != "jpg" &&
            filename2.substr(filename2.find_last_of(".") + 1) != "jpeg" &&
            filename2.substr(filename2.find_last_of(".") + 1) != "png"){
            throw invalid_argument("Invalid file extension or photo.");
        }
    } catch (const exception &e) {
        cout << "Error: " << e.what()
             << " Please provide a photo with .jpg, .jpeg, or .png extension." << endl;

    }
}
void load_image2() {
    string choice;
    while (true){
        cout << "Where is your photo?" << endl;
        cout << "1) on the pc" << endl;
        cout << "2) in the directory" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == "1") {
            cout << "insert a complete path:";
            getline(cin, filename2);
            for (char& c : filename2) {
                if (isalpha(c)) {
                    c = tolower(c);
                }
            }
            while (!fileExists2(filename2)) {
                cout << "The file does not exist. Please enter a valid filename: ";
                getline(cin, filename2);
            }
            check_validation2();
            break;
        } else if (choice == "2") {
            cout << "insert the name of the photo: ";
            getline(cin, filename2);
            for (char& c : filename2) {
                if (isalpha(c)) {
                    c = tolower(c);
                }
            }
            while (!fileExists2(filename2)) {
                cout << "The file does not exist. Please enter a valid filename: ";
                getline(cin, filename2);
            }
            check_validation2();
            break;
        } else {
            cout << "please insert a valid choice";
        }
    }
}


void check_validation(){

    try {
        // Check extension here and throw an exception if it's not valid
        if (filename.substr(filename.find_last_of(".") + 1) != "tga" &&
            filename.substr(filename.find_last_of(".") + 1) != "bmp" &&
            filename.substr(filename.find_last_of(".") + 1) != "jpg" &&
            filename.substr(filename.find_last_of(".") + 1) != "jpeg" &&
            filename.substr(filename.find_last_of(".") + 1) != "png"){
            throw invalid_argument("Invalid file extension or photo.");
        }
    } catch (const exception &e) {
        cout << "Error: " << e.what()
             << " Please provide a photo with .jpg, .jpeg, or .png extension." << endl;

    }
}
void check_validation3(){

    while (true) {
        cout << "Enter file name with extension: ";
        cin >> editted;

        // Check extension here and throw an exception if it's not valid
        if (editted.substr(editted.find_last_of(".") + 1) == "tga" ||
            editted.substr(editted.find_last_of(".") + 1) == "bmp" ||
            editted.substr(editted.find_last_of(".") + 1) == "jpg" ||
            editted.substr(editted.find_last_of(".") + 1) == "jpeg" ||
            editted.substr(editted.find_last_of(".") + 1) == "png") {
            break; // Valid extension, exit the loop
        } else {
            cout << "Invalid file extension or photo. Please provide a photo with .jpg, .jpeg, .bmp, .tga, or .png extension." << endl;
        }
    }
}
void load_image(){
    string choice;
    while (true){
        // let the user insert the photo from any way
        cout << "Where is your photo?" << endl;
        cout << "1) on the pc" << endl;
        cout << "2) in the directory" << endl;
        cin>>choice;
        cin.ignore();
        if (choice == "1") {
            //to insert the place of the photo and check
            cout << "insert a complete path:";
            getline(cin, filename);
            for (char& c : filename) {
                if (isalpha(c)) {
                    c = tolower(c);
                }
            }
            //check if the photo exists
            while (!fileExists(filename)) {
                cout << "The file does not exist. Please enter a valid filename: ";
                getline(cin, filename);
                for (char& c : filename) {
                    if (isalpha(c)) {
                        c = tolower(c);
                    }
                }
            }
            //check if the name and extension of photo is true
            check_validation();
            break;
        } else if (choice == "2") {
            cout << "insert the name of the photo: ";
            getline(cin, filename);
            for (char& c : filename) {
                if (isalpha(c)) {
                    c = tolower(c);
                }
            }
            //check if the photo exists
            while (!fileExists(filename)) {
                cout << "The file does not exist. Please enter a valid filename: ";
                getline(cin, filename);
                for (char& c : filename) {
                    if (isalpha(c)) {
                        c = tolower(c);
                    }
                }
            }
            //check if the name and extension of photo is true
            check_validation();
            break;
        } else {
            cout << "please insert a valid choice";
        }
    }

}
void menu_3() {
    // menu for 5 filters
    cout << "Please select the type of edit:" << endl;
    cout << "A) Gray edit" << endl;
    cout << "B) Invert edit" << endl;
    cout << "C) Black and white" << endl;
    cout << "D) Flip photo" << endl;
    cout << "E) Rotate the photo" << endl;
    cout << "F) detect edges" << endl;
    cout << "G) merge two photos"<<endl;
    cout << "H) darken_lighten filter" << endl;
    cout << "I) crop photo" << endl;
    cout << "J) resize photo" << endl;
    cout << "K) blur photo" << endl;
    cout << "L) apply frame on the photo" << endl;
    cout << "M) samuray photo" << endl;
    cout << "N) purple photo" << endl;
    cout << "O) sunny filter" << endl;
    cout << "P) save current image" << endl;
    cout << "Q) Exit the program" << endl;
}
void merge() {
    for (int i = 0; i < image1.width; ++i) {
        for (int j = 0; j < image1.height; ++j) {
            for (int k = 0; k < image1.channels; ++k) {
                image1.setPixel(i, j, k, (image1.getPixel(i, j, k) + image2.getPixel(i, j, k))/2);
            }
        }
    }
}
void crop_filter(){
    double x,y,w,h;
    Image image (filename);
    cout<<"enter your center point x: ";
    cin>>x;
    cout<<"enter your center point y: ";
    cin>>y;
    while (true)
    {
        cout<<"enter your dimentions:"<<endl;
        cin>>w>>h;
        if (w<=image.width && h<=image.height)
        {
            break;
        }else{
            cout<<"plaese enter a valid dimensios that are smaller than or equal to the original image"<<endl;
        }

    }
    Image image2(w,h);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j< h; j++)
        {

            for (int k= 0; k < 3; k++)
            {
                image2(i,j,k)=image(i+x,j+y,k);
            }
        }

    }
    string choice;
    while (true) {
        cout << "How do you want to save the image?" << endl;
        cout << "1) Overwrite the original photo" << endl;
        cout << "2) Save as a new photo" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == "1") {
            // let the editted photo equal to the main photo
            image2.saveImage(filename);
            cout << "The image has been processed and saved successfully." << endl;
            break;
        } else if (choice == "2") {
            //editted photo is a new photo
            cout << "Please insert the name of the new photo: ";
            getline(cin, editted);
            for (char& c : editted) {
                if (isalpha(c)) {
                    c = tolower(c);
                }
            }
            //check if the name and extension of photo is true
            check_validation3();
            image2.saveImage(editted);
            cout << "The image has been processed and saved successfully." << endl;
            // Update filename to the new edited image filename
            filename = editted;

            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
void resize_filter(){
    Image image(filename);
    double x,y;
    cout<<"enter your dimention: ";
    cin>>x>>y;
    Image image2(x,y);
    double sr=image.width/x;
    double sc=image.height/y;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image2(i,j,k)=round(image(i*sr,j*sc,k));
            }

        }

    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image2.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image2.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void save_image() {
    while (true) {
        cout << "Do you want to save this photo?" << endl;
        cout << "1) Yes." << endl;
        cout << "2) No." << endl;
        cout << "insert your choice here:" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") {
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    image1.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    check_validation3();
                    image1.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choice == "2") {
            cout << "OK, it doesn't save" << endl;
            break;
        } else {
            cout << "insert a valid choice (1 or 2)" << endl;
        }
    }
}

void red_filter(){
    Image image(filename);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image(i,j,0)=255;
                int s=image(i,j,1);
                image(i,j,1)=255-image(i,j,2);
                image(i,j,2)=255-s;
            }

        }

    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}

void robertEdgeDetection(Image& image1, Image& outputImage) {
    // Robert's masks
    int robert_mask_x[2][2] = {{1, 0}, {0, -1}};
    int robert_mask_y[2][2] = {{0, 1}, {-1, 0}};

    for (int y = 0; y < image1.height - 1; ++y) {
        for (int x = 0; x < image1.width - 1; ++x) {
            // Calculate gradients in x and y directions using Robert's masks
            int gradient_x = 0, gradient_y = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    gradient_x += image1.getPixel(x + i, y + j, 0) * robert_mask_x[i][j];
                    gradient_y += image1.getPixel(x + i, y + j, 0) * robert_mask_y[i][j];
                }
            }

            // Calculate gradient magnitude
            int gradient_magnitude = sqrt(gradient_x * gradient_x + gradient_y * gradient_y);

            // Thresholding: If gradient magnitude is above a certain value, it's an edge
            if (gradient_magnitude > 100) { // Adjust this threshold as needed
                //  set the pixel to black (0)
                for (int k = 0; k < 3; ++k) {
                    outputImage.setPixel(x, y, k, 0);
                }
            } else {
                //Otherwise, Set the pixel to white (255) to highlight the edge
                for (int k = 0; k < 3; ++k) {
                    outputImage.setPixel(x, y, k, 255);
                }
            }
        }
    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    outputImage.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    outputImage.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void blur(string filename){
    Image image(filename);//inserting the image
    for (int h = 0; h < image.width; ++h) {
        for (int y = 0; y < image.height; ++y) {
            unsigned int result[3] = {0};
            unsigned int pixels = 0;//to get the number of pixels we iterate on
            for (int i = 0; i <9; ++i) {//to loop over a square and collect its average
                for (int j = 0; j < 9; ++j) {//we choose 9 to get a high blur
                    if (h + i >= 0 && h + i < image.width && y + j >= 0 && y + j < image.height) {
                        //to check the bounded range
                        for (int k = 0;k < image.channels; ++k) {
                            result[k] += image(h + i, y + j,k);
                        }//to  collect the average of the colors too
                        pixels++;
                    }
                }
            }//to put the average in on pixel
            for (int k = 0; k < image.channels; ++k) {
                image(h, y, k) = result[k] / pixels;
            }
        }
    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}


void merge_photo() {
    try {
        image1.loadNewImage(filename);
    } catch (const std::exception &e) {
        cout << "Error loading image: " << e.what() << endl;
    }
    load_image2();
    try {
        image2.loadNewImage(filename2);
    } catch (const std::exception &e) {
        cout << "Error loading image: " << e.what() << endl;
    }
    if ((image1.width == image2.width) && (image1.height == image2.height)) {
        merge();
        save_image();
    } else if (image1.width != image2.width || image1.height != image2.height) {
        cout << " do you want to resize or crop the photo or no thing?" << endl;
        cout << "A)resize the photo" << endl;
        cout << "B)crop the photo" << endl;
        string choice;
        cout << "Insert your choice here: ";
        cin >> choice;
        while (true) {
            if (choice == "A") {
                double x, y;
                x = max(image1.width, image2.width);
                y = max(image1.height, image2.height);
                Image image3(x, y);
                Image image4(x, y);
                double sr = image1.width / x;
                double sc = image1.height / y;
                double sr2 = image2.width / x;
                double sc2 = image2.height / y;
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        for (int k = 0; k < 3; k++) {
                            image3(i, j, k) = round(image1(i * sr, j * sc, k));
                        }
                    }
                }
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        for (int k = 0; k < 3; k++) {
                            image4(i, j, k) = round(image2(i * sr2, j * sc2, k));
                        }
                    }
                }
                for (int i = 0; i < image3.width; ++i) {
                    for (int j = 0; j < image3.height; ++j) {
                        for (int k = 0; k < image3.channels; ++k) {
                            image3.setPixel(i, j, k, (image3.getPixel(i, j, k) + image4.getPixel(i, j, k)) / 2);
                        }
                    }
                }
                while (true) {
                    cout << "How do you want to save the image?" << endl;
                    cout << "1) Overwrite the original photo" << endl;
                    cout << "2) Save as a new photo" << endl;
                    cout << "Please enter your choice: ";
                    cin >> choice;
                    cin.ignore();

                    if (choice == "1") {
                        image3.saveImage(filename);
                        cout << "The image has been processed and saved successfully." << endl;
                        break;
                    } else if (choice == "2") {
                        cout << "Please insert the name of the new photo: ";
                        getline(cin, editted);
                        for (char& c : editted) {
                            if (isalpha(c)) {
                                c = tolower(c);
                            }
                        }
                        check_validation3();
                        image3.saveImage(editted);
                        cout << "The image has been processed and saved successfully." << endl;
                        filename = editted;
                        break;
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                }
                break;
            } else if (choice == "B") {
                double x, y;
                x = 0, y = 0;
                double a = min(image1.width, image2.width);
                double b = min(image1.height, image2.height);
                Image image3(a, b);
                Image image4(a, b);

                for (int i = 0; i < a; i++) {
                    for (int j = 0; j < b; j++) {
                        for (int k = 0; k < 3; k++) {
                            image3(i, j, k) = image1(i + x, j + y, k);
                        }
                    }
                }

                for (int i = 0; i < a; i++) {
                    for (int j = 0; j < b; j++) {
                        for (int k = 0; k < 3; k++) {
                            image4(i, j, k) = image2(i + x, j + y, k);
                        }
                    }
                }
                for (int i = 0; i < image3.width; ++i) {
                    for (int j = 0; j < image3.height; ++j) {
                        for (int k = 0; k < image3.channels; ++k) {
                            image3.setPixel(i, j, k, (image3.getPixel(i, j, k) + image4.getPixel(i, j, k)) / 2);
                        }
                    }
                }
                while (true) {
                    cout << "How do you want to save the image?" << endl;
                    cout << "1) Overwrite the original photo" << endl;
                    cout << "2) Save as a new photo" << endl;
                    cout << "Please enter your choice: ";
                    cin >> choice;
                    cin.ignore();

                    if (choice == "1") {
                        image3.saveImage(filename);
                        cout << "The image has been processed and saved successfully." << endl;
                        break;
                    } else if (choice == "2") {
                        cout << "Please insert the name of the new photo: ";
                        getline(cin, editted);
                        for (char& c : editted) {
                            if (isalpha(c)) {
                                c = tolower(c);
                            }
                        }
                        check_validation3();
                        image3.saveImage(editted);
                        cout << "The image has been processed and saved successfully." << endl;
                        filename = editted;
                        break;
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                }
                break;
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
                cin >> choice;
            }
        }
    }
}

void darken_lighten() {
    Image image;
    // Attempt to load an image file with the name specified by the 'filename' variable
    try {
        image.loadNewImage(filename);
    } catch (const std::exception& e) {
        // If loading the image fails due to an exception being thrown...
        cout << "Error loading image: " << e.what() << endl; // Print the error message
        return; // Exit the function early
    }
    string choice2;
    while (true)
    {
        cout << "what do you want to do?" << endl;
        cout << "A) decrease the brightness " << endl;
        cout << "B) increase the brightness " << endl;
        cout << "insert your choice here:";
        cin >> choice2;
        if (choice2 == "A")
        {
            //nested loops for looping on every pixel
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    // use unsigned because if the number is less than 0 let it more than  0


                    for (int k = 0; k < 3; ++k) {
                        image(i, j, 0) /= 1.5;
                        image(i, j, 1) /= 1.5;
                        image(i, j, 2) /= 1.5;
                    }
                }
            }
            break;
        }
        else if (choice2 == "B")
        {
            // Nested loops for looping over every pixel
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    // Loop through each color channel (R, G, B)
                    for (int k = 0; k < 3; ++k) {
                        // Increase the value of each color channel
                        // Ensure the value doesn't exceed 255
                        image(i, j, k) = min(static_cast<int>(image(i, j, k) * 1.5), 255);

                    }
                }
            }
            break;
        }
        else
        {
            cout << "invalid choice please insert (A or B) ,note the they are capital letters" << endl;
        }
    }

    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void purple_photo() {
    Image image;
    // Attempt to load an image file with the name specified by the 'filename' variable
    try {
        image.loadNewImage(filename);
    } catch (const std::exception &e) {
        // If loading the image fails due to an exception being thrown...
        cout << "Error loading image: " << e.what() << endl; // Print the error message
        return; // Exit the function early
    }

//nested loops for looping on every pixel
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // use unsigned because if the number is less than 0 let it more than  0


            for (int k = 0; k < 3; ++k) {
                image(i, j, 0) *= 0.87;
                image(i, j, 2) *= 0.87;
                image(i, j, 1) *= 0.75;
            }
        }
    }
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Loop through each color channel (R, G, B)
            for (int k = 0; k < 3; ++k) {
                // Increase the value of each color channel
                // Ensure the value doesn't exceed 255
                image(i, j, k) = min(static_cast<int>(image(i, j, k) * 2), 255);

            }
        }
    }
    // to save the photo
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void GRAY_PHOTO() {
    Image image;
    // Attempt to load an image file with the name specified by the 'filename' variable
    try {
        image.loadNewImage(filename);
    } catch (const std::exception& e) {
        // If loading the image fails due to an exception being thrown...
        cout << "Error loading image: " << e.what() << endl; // Print the error message
        return; // Exit the function early
    }

//nested loops for looping on every pixel
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // use unsigned because if the number is less than 0 let it more than  0
            unsigned int avg = 0;

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            // use unsigned because if the number is less than 0 let it more than  0
            // compute the average of channels
            unsigned int total_avg = (avg) / 3;
//let every pixel has a degree of gray
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = total_avg;
            }
        }
    }
    // to save the photo
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void Black_White(){
    Image image (filename);
    for (int i = 0; i < image.width; i++)
    {
        unsigned int avg=0;
        for (int j = 0; j< image.height; j++)
        {
            for (int k= 0; k<3; k++)
            {
                avg+=image(i,j,k);
            }
            avg=avg/3;

            for (int  k= 0; k < 3; k++)
            {
                if (avg<200)
                {
                    image(i,j,k)=0;
                }else if (avg>200)
                {
                    image(i,j,k)=255;
                }
            }


        }

    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
Image invert_image(string filename) {
    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                unsigned int res = image(i, j, k);
                unsigned int new_image = 255 - res;
                image(i, j, k) = new_image;
            }
        }
    }

    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void Flip_up_down(){
    Image image (filename);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j< image.height/2; j++)
        {

            for (int k= 0; k < 3; k++)
            {
                int s=image(i,j,k);
                image(i,j,k)=image(i,image.height-1-j,k);
                image(i,image.height-1-j,k)=s;
            }
        }

    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void Flip_right_left(){

    Image image (filename);
    for (int i = 0; i < image.width/2; i++)
    {
        for (int j = 0; j< image.height; j++)
        {

            for (int k= 0; k < 3; k++)
            {
                int s=image(i,j,k);
                image(i,j,k)=image(image.width-1-i,j,k);
                image(image.width-1-i,j,k)=s;
            }
        }

    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void options(){
    while (true) {
        string option;
        cout << "1: if you want flipping up_down(vertical) " << endl;
        cout << "2: if you want flipping right_left (Horizontal) " << endl;
        cout << "please enter your option from this menu";
        cin >> option;
        cin.ignore();
        if (option == "1") {
            Flip_up_down();
            break;
        } else if (option == "2") {
            Flip_right_left();
            break;
        } else {
            cout << "please enter a valid option only 1 or 2" << endl;
        }
    }
}

Image rotate_270(string filename){
    Image edit(filename);//insert the image we will edit
    Image image(edit.height,edit.width);
    for (int i = 0; i < edit.width; ++i) {//loop in the width of the image
        for (int j = 0; j < edit.height; ++j) {//loop in the height of the image
            for (int k = 0; k < edit.channels; ++k) {//we can replace the channels with 3
                image(j,i,k)=edit(edit.width-1-i,j,k);

            }

        }
    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    //check if the name and extension of photo is true
                    check_validation3();
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
    return image;
}

Image rotate_90_degree(string filename){
    Image edit(filename);//insert the image we will edit
    Image image(edit.height,edit.width);
    for (int i = 0; i < edit.width; ++i) {//loop in the width of the image
        for (int j = 0; j < edit.height; ++j) {//loop in the height of the image
            for (int k = 0; k < edit.channels; ++k) {//we can replace the channels with 3
                image(j,i,k)=edit(i,edit.height-1-j,k);

            }

        }
    }

    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
    return image;
}

Image rotate_180_degree(string filename) {

    Image image(filename);//insert the image we will edit

    for (int i = 0; i < image.width; ++i) {//loop in the width of the image
        for (int j = 0; j < image.height / 2; ++j) {//loop in the half  height of the image
            for (int k = 0; k < image.channels; ++k) {//we can replace the channels with 3
                unsigned int s = image(i, j, k);
                image(i, j, k) = image(i, image.height - 1 - j,
                                       k);//we swap each horizontal row with its respective one to get an up_down flipped photo
                image(i, image.height - 1 - j, k) = s;

            }

        }
    }

    for (int i = 0; i < image.width / 2; ++i) {//loop in the half  width of the image
        for (int j = 0; j < image.height; ++j) {//loop in the height of the image
            for (int k = 0; k < image.channels; ++k) {//we can replace the channels with 3
                unsigned int s = image(i, j, k);
                image(i, j, k) = image(image.width - 1 - i, j, k);
                image(image.width - 1 - i, j,
                      k) = s;//we swap each vertical column row with its respective one to get an right_left flipped photo

            }

        }
    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
    return image;
}
void options_2() {
    while (true) {
        string option;
        cout << "1) Rotate 90 degree " << endl;
        cout << "2) Rotate 180 degree " << endl;
        cout << "3) Rotate 270 degree" << endl;

        cout << "please enter your option from this menu";
        cin >> option;
        cin.ignore();

        if (option == "1") {
            rotate_90_degree(filename);
            break;
        }

        else if (option == "2") {
            rotate_180_degree(filename);
            break;
        }

        else if (option == "3") {
            rotate_270(filename);
            break;
        }

        else {
            cout << "please enter a valid option only 1 or 2 or 3" << endl;
        }
    }
}
void sunlight(string filename){

    Image image(filename);//inserting the image
    //to make the upper frame
    for (int i = 0; i< image.width; ++i) { //looping on each pixel
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,0)=image(i,j,0);
                image(i,j,1)=image(i,j,1);
                image(i,j,2)=image(i,j,2)*(0.87);//decreasing the color to get a yellow shade

            }
        }
    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }

}
void Fancy_frame(string filename){

    Image image(filename);//inserting the image
    string choice;//defining our choice
    bool temp=true;

    while(temp){//to verify the choice
        cout<<"Welcome to our program\n";//welcome messages
        cout<<"choose the color of the frame\n";//the menu of colors
        cout<<"1)Red frame \n";
        cout<<"2)Blue frame \n";
        cout<<"3)Black frame \n";
        cout<<"4)Green frame \n";
        cout<<"5)White frame \n";

        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"\n";

        if(choice=="1"||choice=="2"||choice=="3"||choice=="4"||choice=="5"){//to check if it is a true choice or not
            temp=false;
        }
    }
    for (int h = 0; h < image.width; ++h) {
        for (int i = 0; i < 10; ++i) {
            for (int k = 0; k < image.channels; ++k) {

                if(choice=="2"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 255;//make a blue upper border
                }

                else if(choice=="1"){
                    image(h, i, 0) = 255;//make a red upper border
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="3"){//make a black upper border
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="4"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 225;//make a green upper border
                    image(h, i, 2) =0;
                }

                else if(choice=="5"){//make a white upper border
                    image(h, i, 0) = 255;
                    image(h, i, 1) = 255;
                    image(h, i, 2) = 255;
                }
            }

            for (int h = 0; h < image.width; ++h) {
                for (int i = 15; i <20; ++i) {//here i loop on a line in the upper border to make it white
                    for (int k = 0; k < image.channels; ++k) {
                        image(h, i, k) =255;//make the pixels pigmented by white color

                    }
                }
            }

        }
    }

    //make the left side boarder
    for (int h = image.width; h>image.width-10 ; --h) {//to get the left side without affecting the photo
        for (int i = 0; i < image.height; ++i) {
            for (int k = 0; k < image.channels; ++k) {

                if(choice=="2"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 255;//make a blue left sided border
                }

                else if(choice=="1"){
                    image(h, i, 0) = 255;//make a red left sided border
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="3"){//make a black bottom border
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="4"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 225;//make a green left sided border
                    image(h, i, 2) =0;
                }

                else if(choice=="5"){//make a white left border
                    image(h, i, 0) = 255;
                    image(h, i, 1) = 255;
                    image(h, i, 2) = 255;
                }

                for (int h =image.width-15; h > image.width-20; --h) {//here i loop on a line in the left border to make it white,so i loop from the image width after the blue frame as an example  to the width of the white line
                    for (int i = 10; i < image.height-10;++i) {
                        for (int k = 0; k < image.channels; ++k) {
                            image(h, i, k) = 255;//make the pixels pigmented by white color

                        }
                    }
                }

            }
        }

    }
    //to get the right border
    for (int h = 0; h<10 ; ++h) {
        for (int i = 0; i < image.height; ++i) {
            for (int k = 0; k < image.channels; ++k) {

                if(choice=="2"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 255;//make a blue right border
                }

                else if(choice=="1"){
                    image(h, i, 0) = 255;//make a red right border
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="3"){//make a black right border
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="4"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 225;//make a green right border
                    image(h, i, 2) =0;
                }

                else if(choice=="5"){//make a white right border
                    image(h, i, 0) = 255;
                    image(h, i, 1) = 255;
                    image(h, i, 2) = 255;
                }

                for (int h =15; h < 20; ++h) {
                    for (int i = 10; i < image.height-10; ++i) {//loop on a line in the right border
                        for (int k = 0; k < image.channels; ++k) {
                            image(h, i, k) = 255;//make the pixels pigmented by white color

                        }
                    }
                }
            }
        }

    }
    cout<<"image is processing\n";

    for (int h = 0; h < image.width; ++h) { // to reach and access the bottom border
        for (int i = image.height - 10; i < image.height; ++i) {
            for (int k = 0; k < image.channels; ++k) {

                if(choice=="2"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 255;//make a blue bottom border
                }

                else if(choice=="1"){
                    image(h, i, 0) = 255;//make a red bottom border
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="3"){//make a black bottom border
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="4"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 225;//make a green bottom border
                    image(h, i, 2) =0;
                }

                else if(choice=="5"){//make a white bottom border
                    image(h, i, 0) = 255;
                    image(h, i, 1) = 255;
                    image(h, i, 2) = 255;
                }

                for (int h =10; h < image.width-10; ++h) {
                    for (int i = image.height-15; i > image.height-20;--i) {//here i loop on a line in the bottom border to make it white,so i loop from the image height after the blue frame to the width of the white line
                        for (int k = 0; k < image.channels; ++k) {
                            image(h, i, k) = 255;//make the pixels pigmented by white color

                        }
                    }
                }


            }
        }
    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void simple_frame(string filename){

    Image image(filename);//inserting the image
    string choice;//defining our choice
    bool temp=true;

    while(temp){//to verify the choice
        cout<<"Welcome to our program\n";//welcome messages
        cout<<"choose the color of the frame\n";//the menu of colors
        cout<<"1)Red frame \n";
        cout<<"2)Blue frame \n";
        cout<<"3)Black frame \n";
        cout<<"4)Green frame \n";
        cout<<"5)White frame \n";

        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice=="1"||choice=="2"||choice=="3"||choice=="4"||choice=="5"){//to check if it is a true choice or not
            temp=false;
        }
    }

    for (int h = 0; h < image.width; ++h) {
        for (int i = 0; i < 10; ++i) {
            for (int k = 0; k < image.channels; ++k) {
                if(choice=="2"){//making a blur frame
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 255;//make a blue upper border
                }

                else if(choice=="1"){
                    image(h, i, 0) = 255;//make a red upper border
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="3"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;//make a black upper border
                }

                else if(choice=="4"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 225;//make green upper border
                    image(h, i, 2) =0;
                }

                else if(choice=="5"){//make a white upper border
                    image(h, i, 0) = 255;
                    image(h, i, 1) = 255;
                    image(h, i, 2) = 255;
                }

            }
        }

    }
    //make the left side boarder
    for (int h = image.width; h>image.width-10 ; --h) {//to get the left side without affecting the photo
        for (int i = 0; i < image.height; ++i) {
            for (int k = 0; k < image.channels; ++k) {
                if(choice=="2"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 255;//make a blue left side border
                }
                else if(choice=="1"){
                    image(h, i, 0) = 255;//make a red left side border
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }
                else if(choice=="3"){//make a black left side border
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }
                else if(choice=="4"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 225;//make a green left side border
                    image(h, i, 2) =0;
                }
                else if(choice=="5"){//make a white left side border
                    image(h, i, 0) = 255;
                    image(h, i, 1) = 255;
                    image(h, i, 2) = 255;
                }

            }
        }

    }
    //to get the right border
    for (int h = 0; h<10 ; ++h) {
        for (int i = 0; i < image.height; ++i) {
            for (int k = 0; k < image.channels; ++k) {

                if(choice=="2"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 255;//make a blue right border
                }
                else if(choice=="1"){
                    image(h, i, 0) = 255;//make a red right border
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }
                else if(choice=="3"){//make a black right border
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="4"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 225;//make a green right border
                    image(h, i, 2) =0;
                }

                else if(choice=="5"){//make a white right border
                    image(h, i, 0) = 255;
                    image(h, i, 1) = 255;
                    image(h, i, 2) = 255;
                }

            }

        }

    }
    for (int h = 0; h < image.width; ++h) { // to reach and access the bottom border
        for (int i = image.height - 10; i < image.height; ++i) {
            for (int k = 0; k < image.channels; ++k) {

                if(choice=="2"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 255;//make a blue bottom border
                }

                else if(choice=="1"){
                    image(h, i, 0) = 255;//make a red bottom border
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="3"){//make a black bottom border
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 0;
                    image(h, i, 2) = 0;
                }

                else if(choice=="4"){
                    image(h, i, 0) = 0;
                    image(h, i, 1) = 225;//make a green bottom border
                    image(h, i, 2) =0;
                }

                else if(choice=="5"){//make a white bottom border
                    image(h, i, 0) = 255;
                    image(h, i, 1) = 255;
                    image(h, i, 2) = 255;
                }

            }
        }
    }
    while (true) {
        cout << "Do you want to save photo?";
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "insert your choice here:";
        string choose;
        cin >> choose;
        if (choose == "1") {
            string choice;
            while (true) {
                cout << "How do you want to save the image?" << endl;
                cout << "1) Overwrite the original photo" << endl;
                cout << "2) Save as a new photo" << endl;
                cout << "Please enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == "1") {
                    // let the editted photo equal to the main photo
                    image.saveImage(filename);
                    cout << "The image has been processed and saved successfully." << endl;
                    break;
                } else if (choice == "2") {
                    //editted photo is a new photo
                    cout << "Please insert the name of the new photo: ";
                    getline(cin, editted);
                    for (char& c : editted) {
                        if (isalpha(c)) {
                            c = tolower(c);
                        }
                    }
                    //check if the name and extension of photo is true
                    check_validation3();
                    image.saveImage(editted);
                    cout << "The image has been processed and saved successfully." << endl;
                    // Update filename to the new edited image filename
                    filename = editted;
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        } else if (choose == "2") {
            cout << "ok it doesn't save";
            break;
        } else {
            cout << "invalid choice please insert a valid choice ( 1 or 2)";
        }
    }
}
void program() {

    string choice;
    Image image, image1;

    while (image.loadNewImage(filename) && image.channels == 3) {
        menu_3();

        cout << "Insert your choice here: ";
        cin >> choice;

        if (choice == "A") {
            GRAY_PHOTO();
            break;
        }
        else if (choice == "B") {
            invert_image(filename);
            break;
        }
        else if (choice == "C") {
            Black_White();
            break;
        }
        else if (choice == "D") {
            options();
            break;
        }
        else if (choice == "E") {
            options_2();
            break;
        }
        else if (choice == "F") {
            Image image1(filename);
            Image outputImage(image1.width, image1.height);
            try {
                image1.loadNewImage(filename);
            } catch (const std::exception &e) {
                // If loading the image fails due to an exception being thrown...
                cout << "Error loading image: " << e.what() << endl; // Print the error message
            }
            robertEdgeDetection(image1, outputImage);
            break;
        }
        else if (choice == "G") {
            merge_photo();
            break;
        }
        else if (choice == "H") {
            darken_lighten();
            break;
        }
        else if (choice == "I") {
            crop_filter();
            break;
        }
        else if (choice == "J") {
            resize_filter();
            break;
        }
        else if (choice == "K") {
            blur(filename);
            break;
        }
        else if (choice == "L") {
            while (true){
                cout << "Which type of frame do you want?" << endl;
                cout << "1) simple frame" << endl;
                cout << "2) Fancy frame" << endl;
                cout << "insert your choice here:" << endl;
                string option;
                cin >> option;
                if (option == "1"){
                    simple_frame(filename);
                    break;
                }
                else if (option == "2"){
                    Fancy_frame(filename);
                    break;
                }
                else{
                    cout << "invalid choice please insert only '1' or '2'." << endl;
                }
            }
            break;
        }
        else if (choice == "M") {
            red_filter();
            break;
        }
        else if (choice == "N") {
            purple_photo();
            break;
        }
        else if (choice == "O"){
            sunlight(filename);
            break;
        }
        else if (choice == "P"){
            while (true) {
                cout << "Do you want to save photo?";
                cout << "1) Yes" << endl;
                cout << "2) No" << endl;
                cout << "insert your choice here:";
                string choose;
                cin >> choose;
                if (choose == "1") {
                    string choice;
                    while (true) {
                        cout << "How do you want to save the image?" << endl;
                        cout << "1) Overwrite the original photo" << endl;
                        cout << "2) Save as a new photo" << endl;
                        cout << "Please enter your choice: ";
                        cin >> choice;
                        cin.ignore();

                        if (choice == "1") {
                            // let the editted photo equal to the main photo
                            image.saveImage(filename);
                            cout << "The image has been processed and saved successfully." << endl;
                            break;
                        } else if (choice == "2") {
                            //editted photo is a new photo
                            cout << "Please insert the name of the new photo: ";
                            getline(cin, editted);
                            //check if the name and extension of photo is true
                            check_validation();
                            image.saveImage(editted);
                            cout << "The image has been processed and saved successfully." << endl;
                            // Update filename to the new edited image filename
                            filename = editted;
                            break;
                        } else {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                    break;
                } else if (choose == "2") {
                    cout << "ok it doesn't save";
                    break;
                } else {
                    cout << "invalid choice please insert a valid choice ( 1 or 2)";
                }
            }
        }
        else if (choice == "Q"){
            while (true) {
                cout << "Do you want to save photo?";
                cout << "1) Yes" << endl;
                cout << "2) No" << endl;
                cout << "insert your choice here:";
                string choose;
                cin >> choose;
                if (choose == "1") {
                    string choice;
                    while (true) {
                        cout << "How do you want to save the image?" << endl;
                        cout << "1) Overwrite the original photo" << endl;
                        cout << "2) Save as a new photo" << endl;
                        cout << "Please enter your choice: ";
                        cin >> choice;
                        cin.ignore();

                        if (choice == "1") {
                            // let the editted photo equal to the main photo
                            image.saveImage(filename);
                            cout << "The image has been processed and saved successfully." << endl;
                            break;
                        } else if (choice == "2") {
                            //editted photo is a new photo
                            cout << "Please insert the name of the new photo: ";
                            getline(cin, editted);
                            //check if the name and extension of photo is true
                            check_validation();
                            image.saveImage(editted);
                            cout << "The image has been processed and saved successfully." << endl;
                            // Update filename to the new edited image filename
                            filename = editted;
                            break;
                        } else {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                    break;
                } else if (choose == "2") {
                    cout << "ok it doesn't save";
                    break;
                } else {
                    cout << "invalid choice please insert a valid choice ( 1 or 2)";
                }
            }
            cout << "Thank you fo use my program" << endl;
            exit(0);
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            cout << "please insert only capital alphabets from 'A' to 'O' " << endl;
        }
    }
}
int main() {
    Image image;
    cout << "Welcome to our program" << endl;
    while (true) {
        load_image();
        try {
            image.loadNewImage(filename);
        } catch (const std::exception& e) {
            cout << "Error loading image: " << e.what() << endl;
            continue; // Skip the rest of the loop and start over
        }

        program(); // Perform the editing operations

        // Ask the user if they want to continue editing or end the program
        cout << "Do you want to continue editing this photo? (yes/no): ";
        string continueEditing;
        cin >> continueEditing;
        if (continueEditing == "no") {
            cout << "Thank you for using our program" << endl;
            break; // Exit the loop and end the program
        } else if (continueEditing == "yes") {
            // Ask for the edited filename
            cout << "Please insert the name of the edited photo: " << endl;
            getline(cin, editted);
            // Perform any additional operations with the edited filename if needed
        } else {
            cout << "Invalid choice. Please enter 'yes' or 'no'." << endl;
        }
    }
    return 0;
}
