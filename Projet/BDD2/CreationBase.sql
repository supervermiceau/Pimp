#------------------------------------------------------------
#          Creation Gestion recette
#------------------------------------------------------------


#------------------------------------------------------------
# Table: Recette
#------------------------------------------------------------

CREATE TABLE Recette(
        id_Recette  Int NOT NULL ,
        Descriptif  Varchar (25) ,
        difficulte  Int ,
        nb_personne Int default 0,
        Image       Varchar (25) ,
        videos      Varchar (25) ,
        prix        Int ,
        duree       Int ,
        id_etape    Int ,
        PRIMARY KEY (id_Recette )
);


#------------------------------------------------------------
# Table: Etape
#------------------------------------------------------------

CREATE TABLE Etape(
        id_etape   Int NOT NULL ,
        descriptif Varchar (500) ,
        duree      Int ,
        PRIMARY KEY (id_etape )
);


#------------------------------------------------------------
# Table: Ingredient
#------------------------------------------------------------

CREATE TABLE Ingredient(
        id_ingredient Int NOT NULL ,
        nom           Varchar (25) ,
        calorie       Int ,
        glucide       Int ,
        lipide        Int ,
        protide       Int ,
        PRIMARY KEY (id_ingredient )
);


#------------------------------------------------------------
# Table: Categorie
#------------------------------------------------------------

CREATE TABLE Categorie(
        id_categorie  Int NOT NULL ,
        Nom           Varchar (25) ,
        id_ingredient Int ,
        PRIMARY KEY (id_categorie )
);


#------------------------------------------------------------
# Table: Regime
#------------------------------------------------------------

CREATE TABLE Regime(
        id_regime  Int NOT NULL ,
        nom_regime Varchar (25) ,
        PRIMARY KEY (id_regime )
);


#------------------------------------------------------------
# Table: utilisateur
#------------------------------------------------------------

CREATE TABLE utilisateur(
        id_utilisateur Int NOT NULL ,
        Nom            Varchar (20) ,
        Prenom         Varchar (20) ,
        email          Varchar (30) ,
        Login          Varchar (25) ,
        id_planning    Int ,
        id_Recette     Int ,
        PRIMARY KEY (id_utilisateur )
);


#------------------------------------------------------------
# Table: Login
#------------------------------------------------------------

CREATE TABLE Login(
        Login          Varchar (25) NOT NULL ,
        mdp            Varchar (25) ,
        PRIMARY KEY (Login )
);


#------------------------------------------------------------
# Table: Planning
#------------------------------------------------------------

CREATE TABLE Planning(
        id_planning Int NOT NULL ,
        nom         Varchar (25) ,
        PRIMARY KEY (id_planning )
);


#------------------------------------------------------------
# Table: Archive planning
#------------------------------------------------------------

CREATE TABLE Archive_planning(
        id_planning Int NOT NULL ,
        Nom         Varchar (20) NOT NULL ,
        jour        Varchar (25) NOT NULL ,
        repas       Varchar (25) NOT NULL ,
        id_Recette  Int NOT NULL,
        PRIMARY KEY (id_planning )
);


#------------------------------------------------------------
# Table: Archives liste achat
#------------------------------------------------------------

CREATE TABLE Archives_liste_achat(
        id_planning Int NOT NULL ,
        id_Recette  Int NOT NULL ,
        PRIMARY KEY (id_planning ,id_Recette )
);


#------------------------------------------------------------
# Table: Composer
#------------------------------------------------------------

CREATE TABLE Composer(
        quantite      Int ,
        unite         Varchar (2) ,
        id_Recette    Int NOT NULL ,
        id_ingredient Int NOT NULL ,
        PRIMARY KEY (id_Recette ,id_ingredient )
);


#------------------------------------------------------------
# Table: Est interdit
#------------------------------------------------------------

CREATE TABLE Est_interdit(
        id_ingredient Int NOT NULL ,
        id_regime     Int NOT NULL ,
        PRIMARY KEY (id_ingredient ,id_regime )
);


#------------------------------------------------------------
# Table: Possede
#------------------------------------------------------------

CREATE TABLE Possede(
        Quantite       Int ,
        unite          Int ,
        id_utilisateur Int NOT NULL ,
        id_ingredient  Int NOT NULL ,
        PRIMARY KEY (id_utilisateur ,id_ingredient )
);


#------------------------------------------------------------
# Table: Creer liste
#------------------------------------------------------------

CREATE TABLE Creer_liste(
        jour        Varchar (25) ,
        repas       Varchar (25) ,
        id_Recette  Int NOT NULL ,
        id_planning Int NOT NULL ,
        PRIMARY KEY (id_Recette ,id_planning )
);


#------------------------------------------------------------
# Table: convient à
#------------------------------------------------------------

CREATE TABLE convient_a(
        id_regime  Int NOT NULL ,
        id_Recette Int NOT NULL ,
        PRIMARY KEY (id_regime ,id_Recette )
);

#------------------------------------------------------------
#        Contrainte
#------------------------------------------------------------

ALTER TABLE Recette ADD CONSTRAINT FK_Recette_id_etape FOREIGN KEY (id_etape) REFERENCES Etape(id_etape);
ALTER TABLE Recette ADD CONSTRAINT CK_Recette_difficulte check (difficulte in ('1', '2', '3', '4', '5')); 
ALTER TABLE Recette ADD CONSTRAINT CK_Recette_prix check (prix in ('1', '2', '3', '4', '5')); 

ALTER TABLE Categorie ADD CONSTRAINT FK_Categorie_id_ingredient FOREIGN KEY (id_ingredient) REFERENCES Ingredient(id_ingredient);

ALTER TABLE utilisateur ADD CONSTRAINT FK_utilisateur_Login FOREIGN KEY (Login) REFERENCES Login(Login);
ALTER TABLE utilisateur ADD CONSTRAINT FK_utilisateur_id_planning FOREIGN KEY (id_planning) REFERENCES Planning(id_planning);
ALTER TABLE utilisateur ADD CONSTRAINT FK_utilisateur_id_Recette FOREIGN KEY (id_Recette) REFERENCES Recette(id_Recette);

ALTER TABLE Login ADD CONSTRAINT FK_Login_id_utilisateur FOREIGN KEY (id_utilisateur) REFERENCES utilisateur(id_utilisateur);

ALTER TABLE Composer ADD CONSTRAINT FK_Composer_id_Recette FOREIGN KEY (id_Recette) REFERENCES Recette(id_Recette);
ALTER TABLE Composer ADD CONSTRAINT FK_Composer_id_ingredient FOREIGN KEY (id_ingredient) REFERENCES Ingredient(id_ingredient);
ALTER TABLE Composer ADD CONSTRAINT CK_Composer_unite check (unite in ('U', 'g')); 


ALTER TABLE Est_interdit ADD CONSTRAINT FK_Est_interdit_id_ingredient FOREIGN KEY (id_ingredient) REFERENCES Ingredient(id_ingredient);
ALTER TABLE Est_interdit ADD CONSTRAINT FK_Est_interdit_id_regime FOREIGN KEY (id_regime) REFERENCES Regime(id_regime);

ALTER TABLE Possede ADD CONSTRAINT FK_Possede_id_utilisateur FOREIGN KEY (id_utilisateur) REFERENCES utilisateur(id_utilisateur);
ALTER TABLE Possede ADD CONSTRAINT FK_Possede_id_ingredient FOREIGN KEY (id_ingredient) REFERENCES Ingredient(id_ingredient);
ALTER TABLE Possede ADD CONSTRAINT CK_Possede_unite check (unite in ('U', 'g')); 

ALTER TABLE Creer_liste ADD CONSTRAINT FK_Creer_liste_id_Recette FOREIGN KEY (id_Recette) REFERENCES Recette(id_Recette);
ALTER TABLE Creer_liste ADD CONSTRAINT FK_Creer_liste_id_planning FOREIGN KEY (id_planning) REFERENCES Planning(id_planning);
ALTER TABLE Creer_liste ADD CONSTRAINT CK_Creer_liste_jour check (jour in ('Lundi', 'Mardi', 'Mercredi', 'Jeudi','Vendredi', 'Samedi', 'Dimanche')); 
ALTER TABLE Creer_liste ADD CONSTRAINT CK_Creer_liste_repas check (repas in ('Petit dejeuner', 'Dejeuner', 'Diner')); 

ALTER TABLE convient_a ADD CONSTRAINT FK_convient_a_id_regime FOREIGN KEY (id_regime) REFERENCES Regime(id_regime);
ALTER TABLE convient_a ADD CONSTRAINT FK_convient_a_id_Recette FOREIGN KEY (id_Recette) REFERENCES Recette(id_Recette);
