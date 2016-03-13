INSERT INTO login ('B4N','0000');
INSERT INTO login ('MK','0000');
INSERT INTO login ('AN','0000');


INSERT INTO Utilisateur VALUES(1,'Bauer','Lisa','Bauer4nike@gg.com','B4N');
INSERT INTO Utilisateur VALUES(2,'Kobersi','Marina','Mk@gg.com','MK');
INSERT INTO Utilisateur VALUES(3,'Normand','Adeline','AN@gg.com','AN');

INSERT INTO categorie VALUES(1,'Legume');
INSERT INTO categorie VALUES(2,'Frommage');

INSERT INTO Ingredient VALUES(1,'Tomate',1234,25,25,25,1);
INSERT INTO Ingredient VALUES(2,'Mozzarella',1234,25,25,25,2);
INSERT INTO Ingredient VALUES(3,'Ognion',1234,25,25,25,1);

INSERT INTO Recette VALUES (1,'Salade de tomate/Mozza', 'Tres facile',2,1,10,1);

INSERT INTO etape VALUES(1,1,' couper tomate',2);
INSERT INTO etape VALUES(1,2,' couper Mozarella',2);
INSERT INTO etape VALUES(1,3,'MElanger tomate, mozzarella et vinaigrette',0);

INSERT INTO regime VALUES(1,'vegan');
INSERT INTO regime VALUES(2,'Sans gluten');

INSERT INTO planning VALUES(1,'SPORT',2);

INSERT INTO composer VALUES(2,'U',1,1);
INSERT INTO composer VALUES(100,'g',1,2);

INSERT INTO est_interdit(2,1);

INSERT INTO convient_a(1,1);

