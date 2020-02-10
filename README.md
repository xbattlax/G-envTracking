# G-envTracking

G-envTracking
Dossier fonctionnel

Réalisé par
Nathan Metzger 
Andry Monlon

Dans le cadre du cours de projet en environnement graphique.


Sujet choisi :
	L’intelligence artificielle dans sa dimension d’apprentissage automatique (machine learning). L’utilisation de la vidéo pour détecter et reconnaître des sujets avec une intelligence artificielle entraînée.
Table des matières
Énoncé du projet :	1
Diagramme d’activité	2
Les fonctionnalités du logiciel côté caméra	3
Analyse vidéo	3
Capture d’image à intervalles régulières	3
Détection de sujet	3
Ajout de personnes au modèle	3
Ajout possible si système embarqué : suivi du sujet avec la caméra	4
Diagramme de cas d’utilisation	4
Les fonctionnalités du logiciel côté utilisateur	5
Modification des modèles	5
Gestion de la caméra	5
Consultation des enregistrements	5
Les technologies	5
Maquettes de l'application	6
Analyse comparative des technologie	7
Technologies similaires sur le marché	8
Le défi du projet	9
Références	9




Énoncé du projet :

Le projet se présente sous la forme d’un système embarqué avec une caméra et un mini ordinateur contenant un programme de traitement vidéo. Nous traiterons en priorité l’aspect programmation et logiciel avant de mettre en place un système embarqué si le temps nous le permet.
Le programme traitera à des intervalles régulières des images en temps réel afin de détecter d’éventuelles anomalies. L'objectif principal étant d’être adapté à un système de video surveillance. 
La fonctionnalité principale sera de reconnaître une personne dans la vidéo et de déterminer son niveau d’autorisation pour l’accès à la zone dans le champs de vision. Dans le cas négatif, l’application enverra une notification à l'utilisateur par le biais d’un mail, d’un sms ou d’une notification push et lancera un enregistrement.
Diagramme d’activité


Les fonctionnalités du logiciel côté caméra

Notre projet contiendra plusieurs fonctionnalité ( dont certaines nécessaires à l'implémentation du système )
	Analyse vidéo
Le système analysera en temps réel les images de la caméra pour détecter des anomalies. Ces anomalies représentent dans notre cas des visages non connus par le modèle.
Capture d’image à intervalles régulières
Ce système permettra au disque dur sur lesquels seront enregistrées les données de ne pas tourner constamment, pour rappel un disque dur utilisé pour la vidéosurveillance, enregistre et supprime les données au fur et à mesure, ce qui implique une surconsommation électrique comparé à un système ou notre programme est installé ( réduction de l’utilisation disque ). Cela permettrait d’augmenter la durée de vie du disque dur et d’enregistrer des séquences sur de plus grandes périodes. 
Un disque de 6TO permet d’enregistrer 15 jours en 1080p, si prend pour exemple une maison avec un faible passage ( 30 personnes passe devant la maison par jour en 1 min chacune )
Cela permettrait d’enregistrer uniquement 30min par jour ce qui multiplie la capacité d’enregistrement par 48. 
Détection de sujet
Grâce à OpenCv, le  système devrait être capable de reconnaître la présence de visages dans le flux vidéo et de les comparer à des modèles enregistrés.
	Ajout de personnes au modèle
L’utilisateur devant pouvoir ajouter des personnes dans la liste des modèles autorisés, il est important que le système d’apprentissage soit réutilisable pour ajouter des modèles. Pour cela, la caméra devra enregistrer plusieurs séquences de la dites personne et entraîner un algorithme de machine learning pour créer un modèle. La personne devra se placer devant une interface pour permettre au programme de déduire un modèle relationnel fiable ( > 80 ). Cette opération pourra être répétée pour plusieurs personne. 
L’interface donnera plusieurs instruction en temps réel à l’utilisateur (similaire à l’entraînement de FaceId pour l’iPhone). Le model sera sauvegardé dans un fichier XML.
Ajout possible si système embarqué : suivi du sujet avec la caméra
Il serait intéressant d’implémenter un suivi des anomalies par la caméra afin d’améliorer la qualité du cadre des séquences enregistrées. Cette fonctionnalité relevant du système embarqué et de son écosystème, nous ne la mettrons en oeuvre qu’à la fin du projet, si le temps nous le permet.

Diagramme de cas d’utilisation


Les fonctionnalités du logiciel côté utilisateur
	Modification des modèles
L’utilisateur doit pouvoir supprimer des modèles et lancer des phases d’ajout de nouveaux modèle sur le système.
	Gestion de la caméra
La caméra doit pouvoir être désactivée à distance depuis l’interface utilisateur.
	Consultation des enregistrements
Les enregistrements d’anomalies doivent pouvoir êtres téléchargés  et visionner depuis l’interface utilisateur.
Les technologies

Afin de traiter les images pour détecter les sujets, nous choisissons d’utiliser OpenCv. A l’origine il s’agit d’un projet universitaire qui est aujourd’hui  la référence en terme de librairie open source de machine learning et analyse d’images et de vidéos.
OpenCv fonctionne avec trois langages, le python, le c et le c++. Le python est très flexible et le c fiable et efficace. Cependant nous choisissons le c++. En effet l’objectif du cours étant d’apprendre à travers un défi de programmation nous aimerions en profiter pour apprendre ce langage. Pour optimiser le traitement des données, nous utiliserons une version récente de la librairie OpenCv et élaborerons un programme compatible avec les composants informatiques grand public ( ne demandant pas de processeur ou carte graphique inabordable). Les données ne devront pas être trop volumineuses ,pour optimiser le traitement de l’image. Au besoin  nous utiliserons aussi TensorFlow et Keras. TensorFlow est une librairie et une plateforme de machine learning sur laquelle Keras peut se greffer pour utiliser des réseaux de neurones.
Maquettes de l'application

Interface principal de l’application.

Interface d’enregistrement model.
Analyse comparative des technologie 

Il y existe peu de librairies aussi complète et maintenu à jour autres que OpenCv. 

Il existe cependant plusieurs autres librairies libres sur la “computer vision”. Par exemple VLFeat est moins complète que OpenCv car essentiellement orientée sur la reconnaissance d’image et le système SIFT mosaic qui permet de relier automatiquement des images comme montré ci dessous. 

Malheureusement cette librairie n’est plus maintenue depuis 2018 et est un projet de bien moindre ampleur que OpenCv. 

Actuellement, la seule librairie libre capable de concurrencer OpenCv sur le domaine de la “computer vision” est dlib, elle est maintenu et possède un grand nombre de contributeur. 
Avec les recherches que nous avons menées nous en sommes venu à la conclusion que OpenCv était plus simple à utiliser que dlib. Il y a aussi un autre point qui a orienté notre choix, certe dlib est plus rapide sur CPU mais ne permet pas la détection de tête lointaine ( inférieur à 70x70).

Il existe aussi des technologies payantes et propriétaires généralement hébergées dans un cloud. Parmis elles se trouvent Kairos ou Face Recognition API de Lambda Labs. Cependant les librairies payantes ne rentrent pas dans nos critères et elles sont bien souvent basées sur OpenCv. 
Technologies similaires sur le marché

Tout d’abord il convient de différencier la vidéosurveillance de la vidéoprotection. La première représente un système enregistrant des images en continu sous la surveillance d’une personne humaine alors que la deuxième impose un traitement algorithmique sur les images pour ne conserver que celles où  sont détectées des activitées “anormales”. Notre projet se rapproche donc des systèmes de vidéoprotection.
La vidéoprotection est un domaine en pleine expansion avec l’évolution de la recherche en intelligence artificielle. De plus les nombreuses polémiques sur la vidéosurveillance sont évitées  au travers de la vidéoprotection, bien plus respectueuse de la vie privée.

Dans ce secteur se situent des entreprises comme Avedecom, Proteldom ou encore ITQ Security dont les solutions restent très onéreuses pour les entreprises. Les infrastructures sont toujours similaires avec :
Un parc de caméra (le leader dans ce domaine étant Axis)
Un serveur de traitement des données en temps réel (ou bien un service dans le cloud)
Un algorithme de traitement avec une prédéfinition des zones “anormales” et des zones “usuelles” pour les lieux ou des personnes prédéfinies pour les Hommes.

La plupart du temps, les différentes parties de ces systèmes sont d’ailleurs fabriquées par des entreprises différentes puis assemblées et misent en production par des entreprises spécialisées. 
L’ampleur de notre projet restera évidemment bien plus modeste que ceux des entreprises ci-dessus.
Le défi du projet

Le projet devra, à la fin de la session, être en mesure de détecter des visages humains et de lancer des alertes en cas de personnes non connus détectées. Nous sommes une équipe de deux et aucun de nous n’a déjà utilisé OpenCv et le C++. 

Aux travers du projet nous espérons apprendre de nouvelles compétences techniques mais aussi des compétences de travail en équipe. 
Le fonctionnement des techniques de traitement des images, le C++ et la librairies OpenCv devraient être les supports de cette apprentissage.
De plus le C++ étant un langage de plus bas niveau que les langages comme le java, il devrait nous permettent d’élargir le champs de nos connaissances en optimisation de stockage et de performance et en gestion des algorithmes informatiques. 
Par ailleurs nous utiliserons Git afin de versionner le code et de fluidifier le travail en parallèle.

Références

Wiki officiel d’OpenCv : https://github.com/opencv/opencv/wiki
Documentation officiel d’OpenCv : https://docs.opencv.org/
Livre : Learning OpenCv, O'Reilly
Tutoriel OpenCv C++ : https://www.opencv-srf.com/p/introduction.html
Documentation officiel Keras : https://keras.io/
Tutoriel officiel TensorFlow : https://www.tensorflow.org/overview/
