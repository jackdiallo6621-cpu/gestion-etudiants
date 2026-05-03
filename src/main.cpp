#include <iostream>
#include <string>
using namespace std;

struct Etudiant {
    int matricule;
    string nom;
    string prenom;
    float moyenne;
    string mention;
};

Etudiant tab[50];
int nb = 0;

// Fonction pour calculer la moyenne
float calculMoyenne() {
    float note, somme = 0;
    int n = 0;

    cout << "Entrez les notes (note negative pour arreter) : " << endl;
    cin >> note;

    while(note >= 0) {
        somme += note;
        n++;
        cin >> note;
    }

    if(n == 0) return 0;
    return somme / n;
}

// Fonction pour attribuer la mention
string getMention(float m) {
    if(m < 5) return "mediocre";
    else if(m < 6) return "passable";
    else if(m < 7) return "assez bien";
    else if(m < 8) return "bien";
    else return "excellente";
}

// Ajouter étudiant
void ajouter() {
    if(nb >= 50) {
        cout << "Liste pleine !" << endl;
        return;
    }

    cout << "Matricule : ";
    cin >> tab[nb].matricule;

    cout << "Nom : ";
    cin >> tab[nb].nom;

    cout << "Prenom : ";
    cin >> tab[nb].prenom;

    tab[nb].moyenne = calculMoyenne();
    tab[nb].mention = getMention(tab[nb].moyenne);

    nb++;
    cout << "Etudiant ajoute !" << endl;
}

// Affichage
void afficher() {
    if(nb == 0) {
        cout << "Aucun etudiant." << endl;
        return;
    }

    for(int i = 0; i < nb; i++) {
        cout << "\nMatricule: " << tab[i].matricule << endl;
        cout << "Nom: " << tab[i].nom << endl;
        cout << "Prenom: " << tab[i].prenom << endl;
        cout << "Moyenne: " << tab[i].moyenne << endl;
        cout << "Mention: " << tab[i].mention << endl;
    }
}

// Menu principal
int main() {
    int choix;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Ajouter un etudiant" << endl;
        cout << "2. Afficher les etudiants" << endl;
        cout << "3. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch(choix) {
            case 1: ajouter(); break;
            case 2: afficher(); break;
            case 3: cout << "Au revoir !" << endl; break;
            default: cout << "Choix invalide !" << endl;
        }

    } while(choix != 3);

    return 0;
}
