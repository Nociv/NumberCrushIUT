void DisplayGridCreator(unsigned & i, vector <string> & StockDeVar, unsigned & GridSize)
{
    ClearScreen();
    cout << "Entrez la ligne " << i+1 << " sur "<< GridSize <<" chiffres avec un 0 pour les cases ordinaires et" << endl << "un 1 pour les murs (ils peuvent tomber)" << endl << endl;
    if(i != 0)
    {
        for(unsigned j = 0; j < i ; ++j)
        {
            for(unsigned k = 0; k < StockDeVar.size() ; ++k)
            {
                cout << StockDeVar[4+j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool TestValeurDansString(string & Str, unsigned & GridSize)
{
    if(Str.size() != GridSize) return false;
    for(unsigned i=0;i < Str.size(); ++i)
    {
        if(Str[i] != '0' && Str[i] != '1')
        {
                return false;
        }
    }
    return true;
}// TestValeurDansString ()

void LevelCreator() {
    cout << "Choisissez un nom pour votre niveau (max 20 caracteres et ne pas utiliser deux fois le meme nom ou ne rien saisir)" << endl << endl;
    string NomLevel; // rajouter le test d'existence du fichier
    while(true) {
        bool NoSlash=true;
        NomLevel="reset";
        getline(cin,NomLevel);
        if(NomLevel.size() > 20 || NomLevel.size() == 0) {
            ClearScreen();
            cout << "Choisissez un nom pour votre niveau (max 20 caracteres et ne pas utiliser deux fois le meme nom ou ne rien saisir)" << endl << endl;
            cout << "Respectez les consignes !!!" << endl << endl;
            continue;
        }
        for(unsigned i=0; i < NomLevel.size(); ++i) {
            if(NomLevel[i]=='/') {
                ClearScreen();
                cout << "Choisissez un nom pour votre niveau (max 20 caracteres et ne pas utiliser deux fois le meme nom ou ne rien saisir)" << endl << endl;
                cout << "Les / sont interdits dans les noms de fichier sous linux" << endl << endl;
                NoSlash=false;
                break;
            }
        }
        if(NoSlash)break;
    }
    ClearScreen();
    cout << "Entrez la taille de la grille" << endl << endl;
    unsigned GridSize;
    while(true) {
        cin >> GridSize;
        if(cin.fail() || GridSize >= 20) {
            ClearBuf();
            ClearScreen();
            cout << "Entrez la taille de la grille" << endl << endl;
            cout << "Entrez un nombre positif strictement inferieur a 20 (faut pas abuser quand meme)" << endl << endl;
            continue;
        }
        break;
    }
    ClearScreen();
    cout << "Entrez le score a atteindre pour reussir le niveau (max 9998)" << endl << endl;
    unsigned ScoreToWin;
    while(true) {
        cin >> ScoreToWin;
        if(cin.fail() || ScoreToWin > 9998) {
            ClearBuf();
            ClearScreen();
            cout << "Entrez le score a atteindre pour reussir le niveau (max 9998)" << endl << endl;
            cout << "Entrez un nombre positif inferieur a 9998" << endl << endl;
            continue;
        }
        break;
    }
    ClearScreen();
    cout << "Entrez le nombre de valeurs que les cases de la grille peuvent adopter" << endl << endl;
    unsigned NbKandies;
    while(true) {
        cin >> NbKandies;
        if(cin.fail() || NbKandies > 7 || NbKandies == 0) {
            ClearBuf();
            ClearScreen();
            cout << "Entrez le nombre de valeurs que les cases de la grille peuvent adopter" << endl << endl;
            cout << "Entrez un nombre strictement positif et strictement inferieur à 8 car le terminal ne nous donne acces qu'a 8 couleurs et qu'il y a des murs ! ;{" << endl << endl;
            continue;
        }
        break;
    }
    ClearScreen();
    cout << "Entrez le nombre de coups possibles" << endl << endl;
    unsigned Coups;
    while(true) {
        cin >> Coups;
        if(cin.fail()) {
            ClearBuf();
            ClearScreen();
            cout << "Entrez le nombre de coups possibles" << endl << endl;
            cout << "Entrez un nombre positif !" << endl << endl;
            continue;
        }
        break;
    }
    vector <string> StockDeVar;
    StockDeVar.resize(GridSize+4);
    StockDeVar[0]=to_string(GridSize);
    StockDeVar[1]=to_string(NbKandies);
    StockDeVar[2]=to_string(Coups);
    StockDeVar[3]=to_string(ScoreToWin);
    string LigneTmp;
    ClearBuf();
    for(unsigned i=0; i < GridSize; ++i) {
        DisplayGridCreator(i,StockDeVar,GridSize);
        while(true) {
            getline(cin, LigneTmp);
            if(!TestValeurDansString(LigneTmp, GridSize)) {
                ClearScreen();
                DisplayGridCreator(i,StockDeVar,GridSize);
                cout << "Veuillez respecter les indications donnees !" << endl << endl;
                continue;
            }
            ClearScreen();
            break;
        }
    StockDeVar[i+4]=LigneTmp;
    }
    ofstream ofs(NomLevel);
    for(unsigned i=0; i < StockDeVar.size(); ++i) {
        ofs << StockDeVar[i] << endl;
    }
    cout << "Bravo, votre niveau a ete cree avec succes !" << endl;
} // LevelCreator ()