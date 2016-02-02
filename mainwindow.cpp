#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vec_individus = readIndividuFromFile("../../../../tp3/individus.txt");
    char individuAge[21]; // enough to hold all numbers up to 64-bits
    sprintf(individuAge, "%d", vec_individus.at(vectorIndex).getAge());
    std::string individuInformationString = vec_individus.at(vectorIndex).getNom() + " " + vec_individus.at(vectorIndex).getPrenom() + " à " + individuAge + " ans.";
    ui->personnalNameTextLabel->setText(QString::fromStdString(individuInformationString));

    char vectorSize[21]; // enough to hold all numbers up to 64-bits
    sprintf(vectorSize, "%d", vec_individus.size());
    ui->vectorSizeTextLabel->setText("Vector Size : " + QString::fromStdString(vectorSize));

    QPixmap pixmapSrc;
    bool loadPixmap = pixmapSrc.load("../../../../tp3/flou.png");
    ui->imageLabel->setPixmap(pixmapSrc);

    char individuImage[21]; // enough to hold all numbers up to 64-bits
    sprintf(individuImage, "%d", vectorIndex + 1);
    std::string individuImageString = individuImage;
    QPixmap personImagePixmapSrc;
    bool personImageLoadPixmap = personImagePixmapSrc.load("../../../../tp3/image"+ QString::fromStdString(individuImageString) +".jpg");
    ui->imagePersonLabel->setPixmap(personImagePixmapSrc);
}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<Individu> MainWindow::readIndividuFromFile(const string filename)
{
    vector<Individu> vec; //creation du vecteur ‡ renvoyer. Sa taille est nulle
    ifstream fichier(filename.c_str(), ios::in);  //ouverture du fichier en lecture
    if (fichier) {
        string nom, prenom, age;
        while(!fichier.eof()) {  //tant qu'on est pas a la fin du fichier
            fichier >> nom >> prenom >> age; //on lit les donnees de chaque ligne
            //vec.push_back(Individu(prenom,nom,std::stoi(age))); // visual studio ok
            vec.push_back(Individu(prenom,nom,std::atoi(age.c_str()))); // mingw
        }
        fichier.close();
    } else
        cerr << "Erreur d'ouverture de fichier (mauvais nom?)" << endl;
    return vec; //on retourne un vecteur quoiqu'il arrive
}



void MainWindow::on_previousButton_clicked()
{
    if (vectorIndex > 0 && vectorIndex < vec_individus.size()) {
        vectorIndex--;
    } else if ( vectorIndex == 0) {
        vectorIndex = vec_individus.size()-1;
    }

    char numstr[21]; // enough to hold all numbers up to 64-bits
    sprintf(numstr, "%d", vec_individus.at(vectorIndex).getAge());
    std::string result = vec_individus.at(vectorIndex).getNom() + " " + vec_individus.at(vectorIndex).getPrenom() + " à " + numstr + " ans.";
    ui->personnalNameTextLabel->setText(QString::fromStdString(result));

    char individuImage[21]; // enough to hold all numbers up to 64-bits
    sprintf(individuImage, "%d", vectorIndex + 1);
    std::string individuImageString = individuImage;
    QPixmap personImagePixmapSrc;
    bool personImageLoadPixmap = personImagePixmapSrc.load("../../../../tp3/image"+ QString::fromStdString(individuImageString) +".jpg");
    ui->imagePersonLabel->setPixmap(personImagePixmapSrc);
}

void MainWindow::on_nextButton_clicked()
{
    if (vectorIndex > -1 && vectorIndex < vec_individus.size() - 1) {
        vectorIndex++;
    } else if ( vectorIndex == vec_individus.size() - 1) {
        vectorIndex = 0;
    }

    char numstr[21]; // enough to hold all numbers up to 64-bits
    sprintf(numstr, "%d", vec_individus.at(vectorIndex).getAge());
    std::string result = vec_individus.at(vectorIndex).getNom() + " " + vec_individus.at(vectorIndex).getPrenom() + " à " + numstr + " ans.";
    ui->personnalNameTextLabel->setText(QString::fromStdString(result));

    char individuImage[21]; // enough to hold all numbers up to 64-bits
    sprintf(individuImage, "%d", vectorIndex + 1);
    std::string individuImageString = individuImage;
    QPixmap personImagePixmapSrc;
    bool personImageLoadPixmap = personImagePixmapSrc.load("../../../../tp3/image"+ QString::fromStdString(individuImageString) +".jpg");
    ui->imagePersonLabel->setPixmap(personImagePixmapSrc);
}
