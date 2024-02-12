# INFO-F303 : Introduction au Réseaux
${TOC}
# Chapitre 1 : Réseaux d'ordinateurs et Internet
## 1.1 : Qu'est ce qu'internet
### Internet : La vue matérielle 
Internet peut être vu comme un ensemble de machines interconnectées. Les hôtes sont les machines exécutants des applications en bordure de réseaux. A cela il faut ajouter des routeurs et des *switches* (commutateurs) permettant l'envoi et la réception de paquets (morceaux de données), le tout reliés aux hôtes à l'aide de câbles, fibres, etc.
Un ensemble de machines reliées entre elles et gérées par une même instance / organisation est appelé réseaux. En résumé, internet est un réseaux de réseaux.
Pour facilité la communication entre toutes ces machines il existe un ensemble de protocoles opérant à différents niveaux (Par exemple : HTTP, HTTPS ,  TCP, IP, WiFi, etc. ). Pour éviter que chaque constructeurs imposes ses propres idées et rends plus difficile la gestion d'un réseaux, l'***Internet Engineering Task Force*** (**IETF**) se charge d'établir des standards de communication appelés **RFC** (*request for comments*).
<center>
<img src="https://i.imgur.com/DX5FMbJ.png" width=250></img>
</center>

### Internet : La vue service
En ajoutant un certain niveau d'abstraction , internet peut être vu comme une infrastructure qui apporte des services à un ensemble d'applications. Ces services comprennent par exemple le Web, le streaming de vidéos, la gestion de mails etc. Concrètement, il s'agit de "crochets" permettant à des application de communiquer par envoi et réception de message via un service de transport fourni.
<center>
<img src="https://i.imgur.com/33ShwTy.png" width=300></img>
</center>

### Qu'est ce qu'un protocole ?
Un protocole est un ensemble de règles qui définissent la manière dont les messages sont envoyés et reçu parmi les entités d'un réseaux après formatages et organisation.
<center>
<img src="https://i.imgur.com/Pdl063f.png" width=300></img>
</center>

## 1.2 : Bordure du réseaux
### Une vue plus détaillées de la structure d'internet
Comme énoncés précédemment, on retrouve en bordure de réseaux les hôtes. Un hôte est soit un client soit un serveur. De manière générale, les serveurs se trouvent dans des *data centers*.
Les hôtes ont généralement accès physiquement au réseaux via une connexion câblée ou sans fil. 
On différencie généralement :
- les accès résidentiels : DSL, accès par cables
- les accès institutionnels : écoles, compagnies, etc.
- les accès réseaux mobile : WiFi, 4G, 5G, etc.

## 1.3 : Cœur du réseaux
Le cœur d'un réseaux est le plus souvent un ensemble de routeurs interconnectés.
On défini la **commutation de paquets** comme le fait que les hôtes décomposent les messages de la couche applications en paquets (morceaux d'information). Les paquets sont envoyés d'un routeur à un autre via un chemin (de liens) d'une source à une destination.

### Commutation de paquets
Lors du transfert de paquet, plusieurs notions sont à prendre en compte :
- **Le délais de transmission**: Transmettre un paquet de L-bits via un lient ayant un taux de transfert à R bps (bits par secondes (b/s)) prends $L/R$ secondes. (cf. exemple)
- **Stocke et transfert** : Lors qu'un paquet arrive au sein d'un routeur, il doit être absolument complet avant de pouvoir être transféré au routeur suivant.
- **Le délais *end to end***: Est le délais d'envoi d'un paquet d'une machine source à une machine de destination. Dans l'exemple, si le délai de propagation (voir plus loin) est nul, alors le délais *end to end * est de $2L/R$.

<img src="https://i.imgur.com/lEHGxBM.png" width=500></img>
- La mise en file d'attentes et la perte de paquets : Si le taux d'arrivée (en bps) sur le lien entrant dépasse le taux de transmission du lien de sortie sur une période de temps, les paquets serons mis dans une file d'attente au sein du routeur (on parlera de *buffer* / tampon). Si la mémoire tampon du buffer est pleine, les nouveaux paquets arrivants seront abandonné et perdus. 

<img src="https://i.imgur.com/EUbDfO2.png" width=500></img>

### Deux notions clés sur le réseaux
Au sein du réseaux, il faut différencier :
- **Le transfert (*forwarding*)** : Est une action dite locale à un routeur. Les paquets arrivent au routeur via un lien entrant et sont redirigés vers un lien de sortie approprié.
- **Le routage (*routing*)** : Est une action dite globale à un ensemble de routeur. Il s'agit de déterminer le chemin pris par les paquets de la source à la destination de manière optimale. 

### Structure d'internet : Un réseau de réseaux
Un hôte se connecte à internet via un fournisseur d'accès à internet (**ISP**: *Internet Service Provider*). Il peut s'agir d'une entreprise (compagnie, université, commercial) ou  un résidentiel. 
En toute logique, les ISPs doivent être interconnectés pour permettre la communication entre deux hôtes.
De tels agencements implique une structure complexe qui prend cependant tout son sens d'un point de vue économique. En effet, si nous avons des millions d'hôtes les relier chacun entre eux impliquerait une augmentation de connexions en $O(N^2)$ (voir schéma). Une solution serait de connecté un ensemble défini de machine à un ensemble d'ISP.
<center>
<img src="https://i.imgur.com/IxliLcm.png" width=300></img>
<img src="https://i.imgur.com/eWnT6nJ.png" width=300></img>
</center>

Cet ensemble ISPs veulent potentiellement être interconnectés. Cela est possible à l'aide de lien de peering mais aussi à des IXPs (*Internet Exchanges Point*). Il est même possible que certaines grosses entreprise tel que Google lance leurs propres réseaux pour apporter un service aux utilisateurs. On parle alors de *Content Provider Network*.
<img src="https://i.imgur.com/s5MLbyz.png" width=500></img>

### Content Provider Network vs ISPs
- **ISPs commercial de niveau 1** :  Il s'agit de fournisseurs qui permettent une couverture réseaux nationale voir internationale. On y retrouve par exemple Sprint, AT&T, Orange, etc.
- **Content Provider Network** : Il s'agit le plus souvent de réseaux privés qui connectent un data center  à internet, en évitant parfois les ISPs mais sans accepter de trafique transitoires.

<img src="https://i.imgur.com/yCFrRGu.png" width=500></img>

## 1.4 : Délai, pertes et débits au sein d'un réseaux
### Comment se produit une perte de paquets et un délais ?
Comme décrit précédemment, les paquets sont des morceaux d'informations envoyés par une machine source à une machine destinataire. Ceux-ci transitent le plus souvent par un ensemble de routeurs à l'aide de liens (câblés ou non). 
Comme la vitesse de transmission peut varier d'un lien à un autre, il y a nécessité pour un routeur d'avoir une mémoire tampon (*buffer*) dans lequel les paquets attendent. Ce stockage temporaire de paquets peut donc conduire à un délais supplémentaire (il existe cependant d'autre sources de délais).
Lorsque le taux de transmission d'un lien entrant excède le taux de transmission d'un lien de sortie, la mémoire tampon se remplie. Si ce taux entrant reste plus important que le taux de sortie, la mémoire peut se voir totalement remplie (ne pouvant plus accepter de nouveaux paquet) et dès lors les nouveaux paquets arrivant sont perdus. Parfois les paquets perdu sont retournés à l'envoyeur mais cela n'est pas tout le temps garanti.

### Délais de paquets : Quatre sources <a id=delay></a>
Le délais total peut être déterminé comme suis:
$$
d_{nodal} = d_{proc} + d_{queue} + d_{trans} + d_{prop}
$$

- **$d_{proc}$ - Traitement nodal** : Ce délais est induit au sein d'un routeur par la vérification d'erreurs et  la détermination du lien de sortie. Il est généralement sous la milliseconde. 
- **$d_{queue}$ - Délais de file d'attente**: Ce délais est induit au sein d'un routeur par le temps d'attente d'un lien de sortie pour une transmission. Ce délais dépends entièrement du niveau de congestion du routeur.
- **$d_{trans}$ - Délais de transmission** : Ce délais est induit au sein d'un routeur par sa rapidité de transmission (d'écriture sur un lien). Pour un paquet de $L$ bits et un routeur ayant un taux de transmission de $R$ bps, $d_{trans}=L/R$.
- **$d_{prop}$ - Délais de propagation** : Ce délais est induit au sein d'un lien et dépend du taux de propagation de ce dernier (notion physique dépendant de la *'matière'* du lien). Pour un camble de longueur $d$ et de vitesse de propagation $s$ (généralement $~2\times10^8$ m/sec pour la fibre optique), $d_{prop}=d/s$

<img src="https://i.imgur.com/t841pyv.png" width=500></img>

### Délais réel d'internet et routes 
Le programme *traceroute* est un programme qui permet de mesurer le délais total d'une source à une destination sur internet. Pour tout routeur $k$ sur le chemins, le programme va envoyer trois paquets qui vont atteindre les routeurs $k$ sur le chemin de la destination. Le routeur $k$ va retourner ces trois paquets et le programme envoyeur va mesurer le temps d'intervalle entre chacune des transmission puis répondre.

###  Débit
Le débit est le taux en bps d'envois des bits d'une source à une destination. On parle de débit instantané quand on cherche le taux à un instant précis et on parle de débit moyen sur une période de temps.
On défini le *bottleneck* (engorgement) comme un lien sur le chemin qui contrains le débit d'un envoyeur à un receveur.

## 1.5 : Les couches de protocole et les modèles de services
Comme décrits précédemment, les réseaux sont assez complexes. En effet, ceux-ci sont composé de beaucoup d'élément :
- Les hôtes
- Les routeurs
- Les liens de différents médias
- Les applications
- Les protocoles
- Le matériel et le logiciel

Pour organiser tout cela, une norme à décidé d'utiliser une structure en couche permettant par exemple l'identification / la relation de différentes pièces du système ainsi qu'une facilitation de maintenance / mise-à-jour .
Nous parlons le plus souvent du modèle OSI (développé par ISO) en 7 couches (modèle originel et traditionnel) cependant dans le cadre de ce cours nous parlerons du modèle internet en 5 couches.

### Modèle internet 
Comme décrit précédemment, ce modèles est disposé en 5 couches :
- La couche **application** : Niveau des applications réseaux, on y retrouve les normes HTTP, FTP, SMTP, ...
- La couche **transport** : Transfert de données de processus à processus, on y retrouve les normes TCP, UDP, ...
- La couche **réseaux** : Routage des paquets d'une sources à une destination, on y retrouve les normes IP, et protocole de routage
- La couche **lien** : Transfert de données d'élément réseaux voisins (inter routeur, entre routeur et switch , etc.), on y retrouve les norme Ethernet, Wi-Fi, ... 
- La couche **physique**: Encodage / Décodage des bits

### Modèle OSI
Le modèles OSI est très semblable au modèle internet et rajoute deux couches entre la couche application et transport :
- La couche **présentation** : permet aux application d'interpréter les données via l'encryptions, la compression, les conventions propres aux machines 
- La couche **session** : gère la synchronisation, la récupération et l'échange de données.

### L'encapsulation selon le modèle internet 
<img src="https://i.imgur.com/NUGFtig.png" title="source: imgur.com" width=500/>

# Chapitre 2 : La couche Application
Ce chapitre a pour but  l'implémentation conceptuelle des aspects de la couche application tel que le paradigme du client-serveur, le paradigme du pair à pair, les protocoles tel que HTTP et DNS et la programmation d'application réseaux via API de socket.
## 2.1 : Principes de la couche application
###  Application réseaux et architecture d'application
Les application réseaux sont des applications exécutés sur différents *end systems* et qui communiquent via réseaux (par exemple un serveur web qui communique avec un navigateur). Lors de l'implémentation d'une application réseaux, il n'y a aucun besoin d'implémenter du code pour le cœur du réseaux. 
Les applications sont cependant implémentée avec une structure prédéfinie tel que :
- L'architecture **client-serveur** : Une machine qui communique avec un serveur (voir chapitre suivant).
- L'architecture **Pair à pair** (P2P): Deux machines qui communique entre elles (voit chapitres suivants)

#### Paradigme Client - Serveur
Dans ce paradigme nous définissons deux entités ;
- Le serveur : Il s'agit d'un hôte 'toujours actifs' (sauf si maintenance, erreur, etc.)  ayant une adresse IP fixée et permanente se trouvant le plus souvent dans des *data center*
- Les clients : Il s'agit d'un hôte qui à pour tendance de contacter un serveur en se connectant par intermittence. Le plus souvent ce genre de machine ont des adresses IP non fixées et ne communiquent pas entre elles.

Le paradigme Client-Serveur est présent dans les normes HTTP, IMAP, et FTP.

<img src="https://i.imgur.com/vwVHfhd.png" title="source: imgur.com" width=250/>

#### Paradigme Pair à pair (P2P)
Contrairement au paradigme client-serveur, la communication ne se fait plus entre un hôte et un serveur mais deux hôtes directement. Dans ce paradigme un premier pair demande un service à un second pair qui en retour demande un service. Les pairs sont interconnectés de manières intermittente avec des adresses IP variables.

Le paradigme P2P est utilisé par exemple dans le téléchargemnt de fichier via P2P.
<img src="https://i.imgur.com/5hRb79R.png" title="source: imgur.com" width=250/>
#### Hybride des paradigmes P2P et Client-Server
- Skype
-  Text Messaging
-  BitTorrent

### Communication de processus
On défini un processus comme un programme qui s'exécute au sein d'un hôte. 
Comme vu au cours de Systèmes d'exploitation (INFO-F201), l'OS met à disposition plusieurs option de communication inter processus au sein d'une même machine. Il existe aussi de la communication inter processus entre des machines différentes à l'aide de *sockets* et permettant le paradigme Client-Serveur.

#### Les sockets
Les processus envoient / reçoivent des message vers / de leurs sockets. 
Nous pouvons faire un parallèle entre les *socket* et une porte : 
- Le processus d'envois dirige le message vers la porte.
- Le processus d'envoi s'appuie sur l'infrastructure de transport de l'autre côté de la porte pour transmettre le message au processus de réception.
- Deux *sockets* sont impliqué dans la relation.

### Processus d'adressage
Pour recevoir /envoyer des messages, une machine doit pouvoir être identifiable. Cela se fait à l'aide d'une adresse IP et d'un port associé à un processus de l'hôte.

### Protocole de la couche application
Un protocole de la couche application défini : 
- **Le type de message échangé** : Requête ou réponse.
- **La syntaxe du message** : Quels champs dans les messages et comment les champs
sont délimités.
- **La sémantique du message** : Quel sens prend l'information dans un champs.
- **Les règles** : Pour quand et comment un processus envoi et répond à un message.
- **Protocoles ouverts** :  Défini dans les RFCs, tout le monde à accès a la définition du protocole. Permet l'interopérabilité. Par exemple HTTP, SMTP, etc.

### Service requis par une application
- **Intégrité de données** : Certaines applications ont absolument besoin d'un transfert de données sans pertes (transfert de fichiers , transactions web, etc.). Cependant d'autre applications ne nécessitent pas une telle consistance. Par exemple les application de type audio peuvent se permettre de perdre des informations au niveau des fréquences plus élevées.
- **Débit** : Certaines applications ont besoin d'un minimum de débit  pour être considérées comme effective. Il s'agit des application à tendance multimédia (Appel visiomatique etc.). Cependant d'autre applications dite 'élastiques' utilisent le débit disponible.
- **Timing**: Certaines applications ont besoin un délais très cours pour être considérée comme efficace.
- **Sécurité**: Il faut pouvoir garantir une sécurité de bout en bout en mettant en place de l’encryptions ou de l'intégrité de données.

### Services de la couche transport d'internet
- **Protocole TCP** :
	- Transport consistant entre le processus d'envois et de réception.
	- Contrôle de flot : L'envoyeur n'inondera pas le receveur de message.
	- Contrôle de congestion : Quand le réseaux est surchargé, l'envoyeur est restreint
	- ⚠️ :  Ce protocole ne fournis pas de garantie de timing minimum, de notion de timing et de sécurité.
	- Il s'agit d'un protocole dit 'orienté connexion' utilisé et généralement requis par un client et un serveur pour communiquer.
- **Protocole UDP**:
	-	Transport de donnée inconsistant entre le processus d'envois et de réception
	-	⚠️ : Ce protocole ne garantis pas de contrôle de flot, de consistances, de timing , de garantie de débit, de sécurité.
	-	Même si ce protocole ne garanti pas grand choses, il est le plus souvent utilisé pour des raisons de performances pour la téléphonie internet, dans les DNS et des jeux interactifs.

### Sécurisation de TCP
Il est important de noter que les protocoles TCP et UDP ne garantissent aucune encryptions de données . C'est à dire que lors d'une communication (par exemple l'envois d'un mot de passe), le message est envoyé en texte dit clair.

Il existe donc se qu'on appelle la TLS (*transport layer security*) qui fourni une connexion encryptée de TCP. Cette sécurité est implémentée au niveau de la couche application entre les applications et TCP. De manière générale, les application utilisent des librairies TLS qui à leurs tours utilisent TCP via l'API de socket TLS. Le contenu dis *clear text* est envoyé dans un socket qui l'envoi sur internet de manière cryptée.

## 2.2 Web et HTTP
Une page web est constituée d'objets qui peuvent être stocké dans différents serveurs web. Ces objet peuvent prendre des formats différents tel quel de fichier HTML, des image JPEG , des fichier audio, des application Java ect.
Une page web consiste généralement d'un fichier de base en HTML qui référence plusieurs objets, tous adressable par un URL (*Universal Ressource Locator*).
Par exemple :

<img src="https://i.imgur.com/ocXdONc.png" width=500 />

### Vue d'ensemble HTTP (*HyperTextTransfer Protocol*)

Il s'agit du protocole de la couche d'application du web. Il est basé sur le modèle client-serveur où :
- **Le client** utilise un navigateur qui requête, reçois (via le protocole HTTP) et affiche des objets Web
- **Le serveur** web envoi des objets en réponse à une requête


<img src="https://i.imgur.com/gCnzW0J.png" width=250 />

Le protocole HTTP utilise TCP :
- Le client initialise une connexion TCP (via socket) vers un serveur sur le port 80.
- Le serveur accepte la connexion TCP du client .
- Des messages HTTP sont échangés entre le le navigateur (client HTTP) et le serveur Web (serveur HTTP).
- Une fois la communication finie, la connexion TCP est fermée.

On dit que le protocole HTTP est sans état ('*stateless*') car il ne maintient aucune information au niveau des requêtes client passées.
Les protocoles qui maintiennent des états sont généralement plus complexe de part le maintient nécessaire en cas de crash serveur ou client (L'état doit être réconcilié et à jours entre le client et le serveur).

### Connexion HTTP : deux types
On défini deux types de connexion HTTP :
- **Les connexions non persistantes** : La connexion TCP est ouverte, au moins un objet est envoyés via la connexion TCP et enfin la connexion TCP est fermée. Dans le cas du téléchargement de plusieurs objets, plusieurs connexions sont requises.
- **Les connexions persistantes** : La connexion TCP est ouverte, plusieurs objets sont échangé entre le client et le serveur via une même connexion TCP et enfin la connexion est fermée.

#### Exemple de connexion non persistante
<a id="nonpers"></a>
Un utilisateur rentre l'URL suivant contenant du texte et des références vers 10 images jpeg:
```c
www.someSchool.edu/someDepartement/home.index
```

1. Le client HTTP initie une connexion TCP vers un serveur HTTP à l'adresse `www.someSchool.edu` sur le port 80.
2. Le serveur HTTP sur l'hôte référencée par l'adresse `www.someSchool.edu` attends une connexion TCP sur son port 80, accepte une connexion et notifie le client.
3.  Le client HTTP envoi un message requête HTTP via le socket  de connexion TCP. Ce message indique que le client veut un objet `someDepartement/home.index`.
4.  Le serveur HTTP reçoit le message requête, forme un message réponse contenant l'objet de la requête et envoi le message via son socket. 
5.  Le serveur HTTP ferme la connexion TCP.
6.  Le client HTTP reçoit un message réponse contenant un fichier HTML, et l'affiche. Enfin il passe en revue le fichier HTML et trouve 10 références vers des objets jpeg.
7.  Les étapes 1 à 6 sont répétées pour chacun des 10 objets.

#### HTTP non persistant : Temps de réponse 

On défini le RTT (*Round Trip Time*) comme le temps pour un petit paquet pour voyager d'un client à un serveur et vice-versa.

Le temps de réponse par objet de HTTP non persistant correspond donc à un ensemble de RTT :
- Un RTT pour initier la connexion TCP
- Un RTT pour la requête HTTP et les quelques bytes de la réponse 
- Le temps de transmission d'un objet / fichier

<img src="https://i.imgur.com/ts0IIR5.png" width=250 />

> ⚠️ On peut donc définir le temps de réponse de HTTP non persistant comme : 2RTT + temps de transmission d'un objet

#### HTTP persistent (HTTP 1.1)

Le protocole HTTP non persistent est problématique dans le sens où il nécessite 2 RTT par objet qui implique un *overhead* pour chaque connexions TCP. De plus le navigateur parallélise souvent les connexion TCP pour permettre de récupérer les objets référencés.

Le protocole HTTP 1.1 permet au serveur de laisser une connexion ouverte après l'envois d'une réponse. Cela permet aux message suivant entre le même client / serveur d'être envoyé via la même connexion. Les clients envoi de nouvelles requêtes dès qu'il rencontre un objet référencé. En terme de temps de réponse, cela se traduit par un RTT pour tous les objets référencés quand les requêtes sont pipelinés (*pipelined*) divisant le temps de réponse initial par deux.

### Message HTTP

Le protocole HTTP différencie deux types de messages :
- **Les requêtes**.
- **Les réponses**.

#### Les requêtes 
Les messages requêtes de HTTP sont écrit en caractère ASCII (lisible par l'être humain) et composé d'une structure suivante :
- La ligne de requête (GET, POST, HEAD, etc.)
- Les lignes d'en-tête
- Le retour à la ligne indiquant la fin de l'en-tête

<center>
<img src="https://i.imgur.com/psWlBVF.png" width=350 />
<img src="https://i.imgur.com/vS3GEMg.png" width=200 />
</center>

#### Autres messages de requêtes 

- **Méthode POST** : Les page web incluent souvent une forme d'entrée, les entrée de l'utilisateur envoyée par un client vers un serveur se retrouvent dans le corps de la requête HTTP POST. Généralement, les requête POST envoient des données vers un objet distant spécifié dans le champs de l'URL.
- **Méthode GET** : Il s'agit d'une autre méthode pour envoyer les données vers un serveurs. Ces requêtes incluent les données utilisateurs dans le champ de l'URL  (souvent suivie du caractère '?')
- **Méthode HEAD** : Requête une en-tête qui aurait été retourné si l'URL spécifié a été demandé avec une méthode GET
- **Méthode PUT** : Permet l'envoi de nouveau objets vers le serveur et remplace complètement les fichiers/objets qui existe à un URL spécifié.

#### Les réponses

<img src="https://i.imgur.com/KyIevmQ.png" width=500 />

#### Codes de statu des réponses HTTP
Les codes de statu apparaissent dans la première ligne de la réponse "serveur vers client".
On retrouve communément :
- **200 OK** : requête effectuée avec succès, l'objet demandé est présent plus loin dans le message
- **301 Moved Permanently** : L'objet demandé à été déplacé, le nouveau chemin d'accès est disponible dans la suite du message
- **400 Bad Request** : Message non compris par le serveur
- **505 HTTP Version Not Supported**

### Maintenir l'état serveur / utilisateur : cookies
En temps normal, les interactions HTTP GET/réponse sont dites sans états. Cela signifie qu'il n'y a pas de notion d'échange de messages HTTP en plusieurs étapes pour compléter une transaction web (c.f. [Exemple HTTP non persistant](#nonpers) ). Il n'y à dont pas besoins pour un client ou un serveur de maintenir un état lors de cet échange en plusieurs étapes. Caque requête HTTP est indépendante.

Cependant les sites web et les navigateurs utilisateur utilisent des cookies pour maintenir certains états durant une transaction. On retrouve généralement 4 composante dans un cookie : 
1. La ligne d'en-tête du cookie du message de réponse de HTTP.
2. La ligne d'en-tête du cookie dans la prochaine requêtes HTTP.
3. Le fichier cookie est gardé sur la machine utilisateur et est géré par le navigateur de l'utilisateur.
4. La base de donnée *back-end* au niveau du site web.
Par exemple :
- Un client utilise sont navigateur pour visiter un site de vente en ligne pour la première fois.
- A l'arrivée de requête HTTP initiale sur le site, le site créé :
	- Un ID unique sous forme de cookie
	- Une entrée dans la base de donnée
- Les requêtes suivantes faites depuis le client sur ce site vont contenir les cookies contenant eux même l'ID permettant d'identifier le client.

<img src="https://i.imgur.com/7OjERbT.png" width=500 />

#### Commentaires :
Les cookies peuvent être utilisés dans :
- des autorisations.
- magasin de ventes en lignes.
- des recommandations publicitaires.
- des sessions utilisateur (maintient de la connexion pour un mail par exemple).

La notion de cookies et de vie privée sont souvent mise en commun pour diverses raison. Comme dit précédemment, un cookie permet par exemple de collecter un nombre de données sur un utilisateur. Il existe des cookies persistant qui ont pour but de tracer et d'identifier un utilisateur au seins de divers sites web.

### Caches web et serveur proxy
Le but du cache web est de satisfaire les requêtes d'un client sans faire appel au serveur d'origine.
Le principe est simple ; un utilisateur configure son navigateur pour pointer vers un cache web. Le navigateur envoi toutes les requêtes HTTP vers le cache. Si l'objet requête est présent, le cache retourne l'objet au client. Sinon, le cache effectue une requêtes au serveur d'origine, reçoit l'objet et ensuite retourne l'objet au client.

Ce cache fait office à la fois de client ainsi que de serveur en fonction des communications. Dans un premier cas , il fait office de serveur en communicant avec un proxy, dans un autre il effectue des requêtes vers un serveur comme un client classique.
De manière générale, un serveur proxy est installé par les ISPs (universités, compagnies, etc.)

Cette structure de proxy à pour avantage de réduire le temps de réponse pour un client puisque dans le réseaux , le cache est plus proche du client. De plus il permet de réduire le trafique au niveau des lien d'accès d'institutions et de réduire la charge du serveur.
Cette mise en cache du web permet en plus à des *services providers* moins performant de rester efficace.

<img src="https://i.imgur.com/ZLTWi1U.png" width=500 />

#### Exemple de mise en cache

#### Cas de base
<img src="https://i.imgur.com/6fBJ3lb.png" width=250 />

**Details** :
- Le lien d'accès possède un taux de 1.54 Mbps
- Un RTT d'un routeur d'une institution vers un réseaux est d'environ 2 s
- On dispose d'un objet web de 100K bits
- Le taux de requêtes moyen du navigateur vers un serveurs est de 15 / s (taux de données moyen de 1.50 Mbps)

En terme de performance , cela implique :
- Une utilisation lan de .0015
- Une utilisation du lien d'accès de .97
- Un délais final de : Délai internet + délais lien d'accès + délais LAN  = 2s + minutes + $\mu$ s

#### Meilleur lien d'accès

<img src="https://i.imgur.com/CCVYyNB.png" width=250 />

**Details** :
- Le lien d'accès possède un taux de 154 Mbps
- Un RTT d'un routeur d'une institution vers un réseaux est d'environ 2 s
- On dispose d'un objet web de 100K bits
- Le taux de requêtes moyen du navigateur vers un serveurs est de 15 / s (taux de données moyen de 1.50 Mbps)

En terme de performance , cela implique :
- Une utilisation lan de .0015
- Une utilisation du lien d'accès de .0097
- Un délais final de : Délai internet + délais lien d'accès + délais LAN  = 2s + ms + $\mu$ s

Cela permet un meilleur délais au final mais avec un coût certain?

#### Installation d'un cache web

<img src="https://i.imgur.com/YsNhDpG.png" width=250 />

**Details** :
- Le lien d'accès possède un taux de 154 Mbps
- Un RTT d'un routeur d'une institution vers un réseaux est d'environ 2 s
- On dispose d'un objet web de 100K bits
- Le taux de requêtes moyen du navigateur vers un serveurs est de 15 / s (taux de données moyen de 1.50 Mbps)

En terme de performance , cela implique :
- Une utilisation lan : ?
- Une utilisation du lien d'accès de ?
- Un délais final de : ?

#### Calcul du taux d'utilisation du lien d'accès et du délais avec cache

- Supposons que le taux de cache est de 0.4: 40% des requête sont donc satisfaites car présentes en cache tandis que 60% des requêtes sont satisfaites en demandant à l'origine.
- Au niveau du lien d'accès : 60% des requêtes utilisent donc ce lien d'accès soit  $= 0.6 * 1.50 Mbps = 0.9 Mbps$
- utilisation $=0.9/1.54 = 0.58$
- délais moyen *end-end* : 0.6 * délais du serveur d'origine + 0.4 * délais du serveur proxy = 0.6 * 2.01 + 0.4 * (ms) = ~1.2 s

Cela permet un délais en moyenne plus bas avec une solution moins chère.

#### GET conditionnel

Le but du GET conditionnel est d'envoyé un objet seulement si le cache ne le possède pas. Pour se faire , le cache spécifie une date de la copie lors de sa requête vers le serveur. Si le serveur constate que la date de la requête est la plus à jours, alors il envoi une réponse avec aucun objet?
<center>
<img src="https://i.imgur.com/3lPSt30.png" width=250 />
</center>

### HTTP/2
Cette version de HTTP a pour but de réduire le délais des requêtes HTTP multi objets. 

#### Rappel HTTP1.1
Comme décrit précédemment, HTTP1.1 a introduit la notion de plusieurs méthode GET pipelinées (*pipelined*) sur une seule connexion TCP.
Le serveur se contente de répondre dans l'ordre des requêtes reçues (FCFS  :*first come first served*). Cette méthode à pour désavantage de faire parfois attendre des objets plus petits en taille derrière de plus gros objets (on parle alors de *HOL (head of line) blocking)*. De plus, la récupération de perte de paquets interromps la transmission des objets suivants.

#### HTTP1.1 : *HOL blocking* <a id=hol></a>

Prenons l'exemple d'un client dont le navigateurs requête un objet large (une vidéo) suivi de 3 objets plus petits.

<img src="https://i.imgur.com/9k1QeSu.png" width=500 />

> Comme la méthode de réponse suis un FCFS, les objets sont reçu par ordre demandé et les objets $O_2,O_3,O_4$ attendent derrière $O_1$

#### Ajout de HTTP/2
HTTP/2 augmente la flexibilité du serveur au niveau de l'envoi d'objets vers le client. Les méthodes, codes de statu et en-tête sont toujours les même comparés  à HTTP1.1 mais l'ordre de transmission des objets requêtés sont basé sur une priorité d'objet établis par le client. Les objets sont aussi divisés en cadres/ trames (*frames*), ces cadres sont ordonnancé de telle sorte à atténuer le *HOL blocking*.

#### HTTP/2 : *Hol blocking*
Selon le cas de figure formulé [ici](#hol), voici comment HTTP/2 gère les objets divisées en frame

<img src="https://i.imgur.com/oYeJZFu.png" width=500 />

> On remarque que les objets $O_2,O_3,O_4$ sont reçu plus rapidement par le client tandis que l'objet $O_1$ est légèrement retardé comparé à HTTP1.
> ⚠️ La méthode de traitement des *frames* semble être du *round-robin* (c.f. Introduction aux Systèmes d'Exploitation)

### HTTP/2 vers HTTP/3

Certain des problèmes avancé sur HTTP1.1 sont toujours présents avec HTTP/2 sur une simple connexion TCP :
- La récupération de pertes de paquets atténue toujours la transmission d'objets.
- Comme dans HTTP1.1 , les navigateurs sont incités à ouvrir de multiples connexion TCP en parallèle pour éviter le décrochage. Cette manière de faire augmente le débit total.
- Pas de sécurité sur une connexion TCP classique

HTTP/3 ajoute une sécurité, des erreurs par objet et un contrôle de congestion sur UDP.

## 2.3  : Système de nom de domaine (DNS : *domain name system*)
Les hôtes internet et les routeurs possède plusieurs identifiants. Cela peut aller de la simple adresse IP codée sur 32 bits jusqu'au nom de domaine utilisé par les être humains. Cependant il faut pouvoir traduire une adresse IP en nom et vice-versa. Cette tache est effectuée par le DNS.

De manière plus concrète un DNS est une base de donnée distribuée implémentée dans la hiérarchie de plusieurs serveurs de noms. 
Il s'agit d'un protocole de la couche application. Les hôtes , nom de serveurs communiquent avec la base de donnée pour trouver un nom / une adresse.

### DNS : Services et structure

Les services fourni par un DNS sont :
- La traduction de nom de domaine vers adresse IP.
- L'alias d'hôte
- L'alias de serveur mail
- La distribution de charge : Dupliqua de serveurs web, beaucoup d'adresses IP correspondent en fait à un seul et même nom.

L'idée de centraliser un DNS est pas faisable de par le volume du trafique (Comcast enregistre environs 600 milliard de requêtes par jours !), la centralisation distante d'une base de donnée et la maintenance.

### DNS : Une base de donnée distribuée et hiérarchique
Soit un client qui cherche l'adresse IP pour le site `www.amazon.com`, une première approximation est faite par le serveur DNS :
- Le client effectue une requête au niveau de la racine pour déterminer le serveur DNS gérant les adresses `.com` .
- Le client effectue une requête au niveau de du serveurs DNS gérant les adresses `.com` pour déterminer le serveur gérant les adresses `amazon.com`.
- Le client effectue une requête au niveau de du serveurs DNS gérant les adresses `amazon.com` pour déterminer l'IP de ' `www.amazon.com`.

<img src="https://i.imgur.com/Cc2cVND.png" width=500 />

### DNS : Serveur Racine
Comme énoncé précédemment, le DNS est important pour le bon fonctionnement d'internet. Dans le cas ou une serveur de nom de peut déduire le nom / l'adresse, il existe  des contacts officiels de dernier recours, les serveurs racines.

### TDL et serveurs faisant autorité  <a id=auto></a>
Les TDL (*top-level domain*) sont des serveurs responsables des domaines .com, .org, .net, .edu, .jobs, et les domaine de pays tel que .be, .fr etc. Les solutions réseaux maintiennent les serveur TDL pour .com et .net.

On différencie les serveur DNS autoritaire qui sont les serveurs DNS propre à une organisation permettant le mappage des nom d'hôte.

### Serveur de nom DNS local
Ce sont des serveurs DNS qui appartiennent pas fortement une à une hiérarchie. Chaque ISP (résidentielle, compagnie, université) possède son propre DNS appelé nom de serveur par défaut (*"default name server"*). Quand un hôte fait une requête DNS, cette dernière est envoyé au serveur DNS local qui possède un cache local avec les traduction récente des noms vers adresses. Ce cache fait effet de serveur proxy qui envoi la requête dans la hiérarchie.

### Résolution de noms via DNS : requêtes itératives
Soit un hôte dont l'adresse est  `engineering.nyu.edu` cherchant une adresse pour `gaia.cs.umass.edu`
Après l'envoi d'une requête itérative (*iterated query*)  :
- Le serveur contacté répons avec le nom du serveur à contacter.
- Une fois le nom récupéré, ce dernier est stocké dans le cache permettant ainsi d'éviter quelques étapes

<img src="https://i.imgur.com/4WEk6NL.png" title="source: imgur.com" width=500 />


### Résolution de noms via DNS : requêtes récursive
Soit un hôte dont l'adresse est  `engineering.nyu.edu` cherchant une adresse pour `gaia.cs.umass.edu`

La requête itérative :
- Met la charge de la résolution du nom sur le serveur de nom contacté.

<img src="https://i.imgur.com/tmxAs1p.png" width=500 />

### Mettre en cache et mettre à jours les enregistrements DNS
Une fois que le serveur de noms a appris le mappage, il met en cache le mappage. Les entrées du caches disparaissent après un certains temps (appelé TTL), on parle alors de timeout. Les serveurs TLD sont typiquement mis en cache dans les serveurs de noms locaux.
Une entrée de cache peut cependant être obsolète (*out of date*), cela arrive quand un hôte change d'adresse IP. Si rien n'est fait, il est possible donc qu'un site internet disparaisse jusqu'à se que tous les TLL expirent. Pour éviter cela, les DNS dit dynamiques adoptent un mécanisme de notification / mise à jours  (RFC 2136).

### Enregistrement DNS
Comme expliqué précédemment, un DNS est une base de donnée gardant des enregistrement de dossiers de ressources (*resource record* = RR). Il faut donc se mettre d'accord sur un format de stockage de RR :
```c
RR format :(name,value, type, ttl)
```
-  **Type** = A ou AAAA : 
	-  **name** : est le nom d'hôte
	-  **value** : est une adresse IPv4 ou IPv6
-  **Type** = NS:
	-  **name** : est alors un domaine, une zone DNS (par exemple `amazon.com`)
	-  **value** : est un nom d'hôte ou un nom de [serveur de nom autoritaire](#auto)
	-  ⚠️ : Nom de domaine $\ne$ nom d'hôte
-  **Type** = CNAME : 
	-  **name** : est un nom d'alias pour des noms dis canoniques (réels). Par exemple `www.ibm.com` est en réalité `servereast.backup2.ibm.com`
	-  **value** : est donc un nom canonique
-  **Type** = MX :
	-  **value** : est le nom d'un serveur mail associé avec le nom de domaine

### Messages du protocole DNS
Les messages requêtes et réponse de DNS possède le même format de message, envoyé le plus souvent via UDP :
<img src="https://i.imgur.com/JHdKF1o.png" width=250 />

**En-tête de message** : 
- **identification** : nombre sur 16 bits, la réponse utilise le même nombre
- **flags** : 
	- requête ou réponse ?
	- récursion désirée ? 
 	- récursion disponible ?
 	- réponse de type autoritaire ?

**Question** :
 Nom, type de champs pour une requête
 
 **Réponse** :
RR en réponse à la requête.

**Autorité** :
Enregistrements pour les serveurs autoritaires

**Information additionnelle** : 
Information additionnelle utile qui peut être utilisé.

### Insérer des enregistrements dans le DNS
Si par exemple une nouvelle entreprise du nom de "Network Utopia" est créée et les fondateurs aimeraient enregistrer l'URL `networkutopia.com` chez DNS registrar. Il faut :

- Fournir les noms, adresses IP des serveurs de noms autoritaires (primaires et secondaires)
- Registrar insère deux RR dans le serveur TLD gérant les adresses .com :
	- (`networkutopia.com`, dns1.networkutopia.com, NS)
	- (dn1.networkutopia.com, 212.212.212.1, A)
- Créer un serveur autoritaire local avec l'adresse IP 212.212.212.1 :
	- Type A pour `www.networkutopia.com`
	- Type MX pour `networkutopia.com`

## 2.4 Programmation de socket avec UPD et TCP <a id=protocol></a>
La programmation de socket à pour but de construire des application client/serveur qui communiquent à l'aide de sockets. 
Un socket peut être vu comme une porte entre un processus et un protocole de transport de bout en bout.
Au sein de l'OS, il existe deux types de sockets pour deux services de transports : 
- **UDP** : Datagramme peu fiable.
- **TCP** : Orienté flux de bits, fiable.

<img src="https://i.imgur.com/1XZeA8h.png" width=500 />

### Programmation socket avec UDP
Avec UDP, une connexion est pas fortement établie entre les processus d'un client et d'un serveur. Cela implique :
- Pas de 'serrage de main' (*handshaking*) avant l'envoi de données.
- Le processus envoyeur attache explicitement l'adresse IP de destination et le numéro de port pour chaque unité de données (on parle de datagramme).
- Le processus receveur extrait l'adresse IP de l'envoyeur et le numéro de port du datagramme reçu.

Les datagrammes alors transmis peuvent être perdu ou être reçu dans le désordre. D'un point de vue de l'application, UDP fourni un transfert de datagramme peu fiable entre un client et un serveur.

#### Interaction client/serveur via UDP
<img src="https://i.imgur.com/UvNNUzM.png" width=500 />

On remarque que : 
- Le client et le serveur utilisent le même `DatagramSocket`.
- Les adresses IP de destination et le numéro de port sont explicitement attachés au datagramme par le processus client et le processus serveur quand ce dernier est envoyer via le socket.
- L'adresse IP de la source et le numéro de port sont découvert par le client / le serveur dès la réception d'un datagramme. (Une communication avec plusieurs serveurs est possible si plusieurs socket)

### Programmation socket avec TCP

Avec TCP, le client doit dans un premier temps contacter le serveur : 
- Le processus du serveur doit donc être lancé.
- Le serveur doit avoir initialisé un socket pour accepter un contacte provenant d'un client (Socket de bienvenue (*welcoming socket*)).

Par la suite le client contacte le serveur en :
- Créant un socket TCP qui spécifie l'adresse IP, le numéro de port du processus du serveur
- Une fois le socket créé, le client TCP établis une connexion au serveur TCP
- Une fois contacté par le client, le serveur TCP crée un nouveau socket pour permettre au processus serveur de communiqué avec ce client en particulier. Cela permet au serveur de communiquer avec plusieurs clients puisque l'IP et le numéro de port est utilisé pour distinguer les différents clients.

D'un point de vue d'application, TCP fourni un service fiable entre un client et un serveur. TCP utilise un transfert en ordre par flux de bits.

#### Interaction client/serveur via TCP

<img src="https://i.imgur.com/zwxPTdc.png" title="source: imgur.com" />

On remarque que :
- Il existe deux types de socket : `ServerSocket` et `Socket`.
- Quand le client 'toque' sur le socket de bienvenue du serveur, le serveur crée un socket de connexion dédié et complète la connexion TCP.
- L'adresse IP de destination et le numéro de port ne sont pas explicitement attaché aux données d'application envoyées et reçue par le client / le serveur .
- Plusieurs clients peuvent utiliser le serveurs (un socket par client)

# Chapitre 3 : La couche de Transport <a id=chap3></a>

## 3.1 Services de la couche transport 

### Services de transport et protocoles 
La couche transport fourni une communication logique entre des processus d'applications s'exécutant sur des hôtes différents.
Il existe deux protocole de transport disponible pour les applications internet :
- **TCP**
- **UDP**

#### Actions de la couche transport <a id=action></a>

Du point de vue de l'envoyeur :
- Un message de la couche application est passé à la couche transport
- La couche transport détermine les valeurs de l'en-tête 
- La couche transport créer le segment (message + en-tête)
- La couche transport passe le segment à la couche réseaux / IP

Du point de vue du récepteur :
- Un segment de la couche réseaux / IP est reçu par la couche de transport
- La couche transport vérifie les valeurs d'en-tête du segment
- La couche transport extrait le message du segment.
- La couche transport dé-multiplexe le message ([voir plus loin](#demultiplex)) et le transmet a a couche application via le socket.

#### Différence entre la couche de transport et la couche réseaux
La couche  réseaux / IP est la communication logique entre plusieurs hôtes.
La couche de transport (TCP ou UDP) est la communication logique entre plusieurs processus. Cette couche dépend des services de la couche réseaux / IP

(c.f analogie du bureaux et de la poste)

#### TCP et UDP
Pour plus de détail voir [le chaptitre précédent](#protocol).

- **TCP** (*Transmition control protocol*) :
	- Fiable, livraison à temps.
	- Contrôle de congestion
	- Contrôle de flot
	- Mise en place de connexion
- **UDP** (*User Datagram Protocol*):
	- peu fiable et livraison en désordre.
	- extension sans fioritures de l'IP "meilleur effort"(*best effort* IP)

## 3.2 Multiplexage et démultiplexage <a id=demultiplex></a>

Soit une architecture réseaux où deux clients sont connectés à un même serveur, chacun exécutant une tâche différente. 
Lorsque le serveur envoi un paquet vers le client, les en-têtes de la couche réseaux ($H_n$) et transport ($H_t$) sont ajoutés au message devenant ainsi un segment. Le segment est envoyé au client ([c.f. Action de la couche transport](#action)).

Cependant le serveur gère plusieurs clients et doit s'assurer d'envoyer le bon paquets au bon client. Du côté du client, on doit donc s'assurer que le bon message aille à la bonne application.

<img src="https://i.imgur.com/1Y3fyEu.png" width=500 />

> On différencie les processus P1, P2, P3, P4. Chacun de ces processus possède son propre socket. La communication se fait entre P1-P3 et P2-P4.

La couche transport multiplexe les deux messages des processus P1, P2 vers la couche réseaux et garde la trace des paquets en associant un numéro de port pour les différencier. Ce numéro de port est donc inscrit dans l'en-tête du segment pour permettre la redirection du paquet vers le bon processus (il s'agit du démultiplexage).

### Fonctionnement du démultiplexage. 
Pour rappel, l'hôte reçoit des paquets IP de la couche d'en dessous. 
Chaque paquet IP possède une adresse IP source et destination, ainsi qu'un segment de la couche transport. Chaque segment TCP / UDP possède un numéro de port source et destination.

L'hôte utilise les adresses IP de l'en-tête de la couche réseaux ($H_n$) et le numéro de port de l'en-tête de la couche transport ($H_t$) pour diriger le segment vers le socket approprié
<center>
<img src="https://i.imgur.com/hHEPU5A.png" width=250 />
</center>

### Démultiplexage sans connexion (démultiplexage UDP)

Pour rappel, quand un socket UDP est créé, l'application doit spécifier le numéro de port d'hôte local (par exemple `DatagramSocket mySocket = new DatagramSocket(12534)`).

Lors de la création d'un datagramme à envoyer dans un socket UDP, l'application doit spécifier l'identifiant du processus distant. C'est à dire l'adresse IP de destination et le numéro de port de destination.
Quand l'hôte reçoit un segment UDP de la couche inférieure, il vérifier le numéro de port du segment et dirige le segment UDP vers le socket de numéro de port correspondant.
Les paquets IP contenant les charges utiles (*payloads*) UDP avec le même numéro de port de destination mais avec des adresses IP sources et / ou des numéro de port source différent vont être redirigés vers le même socket que l'hôte receveur.

### Exemple de démultiplexage UDP

<img src="https://i.imgur.com/luVCQMy.png" width=500 />

### Démultiplexage orienté connexion (démultiplexage TCP)

Pour rappel, les serveurs web ont différents sockets TCP pour chaque client qui se connectent.  Les requête HTTP non persistante auront des socket différents pour chaque requêtes. Ces différents socket TCP simultanés possèdent tous le même numéro de port. Donc le numéro de port est pas suffisant pour dirigé correctement un segment vers son socket approprié.

Chaque TCP socket est associé à une seule et unique connexion TCP. Cela implique que chaque socket TCP doit être identifier par un id de connexion qui consiste en un tuple de 4 informations : 
- Adresse IP source.
- Numéro de port source.
- Adresse IP de destination.
- Numéro de port de destination.

Quand TCP reçoit un segment de la couche inférieure, il utilise les 4 valeurs pour dirigé le segment vers le socket approprié.


### Exemple de démultiplexage TCP

<img src="https://i.imgur.com/9lWtqU9.png" width=500 />

### En résumé
Le multiplexage / démultiplexage se base sur les valeurs d'en-têtes des segments et paquets.
Dans le cas de UDP, le démultiplexage utilise l'adresse IP de destination et un numéro de port tandis.
Dans le cas de TCP, le démultiplexage utilise un tuple de 4 valeur ; IP source, IP destination, numéro de port source et numéro de port de destination.
Il existe plusieurs forme de multiplexage / démultiplexage à différent niveaux du modèle OSI.

## 3.3 Transport sans connexion : UDP
Protocole de transport internet dit "sans fioritures" avec un service "meilleur effort" puisqu'un segment UDP peut être perdu ou délivré dans le désordre.
On dit que TCP est sans connexion puisqu'aucun serrage de main *(handshaking)* est requis entre un envoyeur et un receveur UDP. Chaque segment UDP est dont géré indépendamment des autres.

L'implémentation d'un tel protocole peut sembler étrange cependant quelques avantages sont à noter : 
-  Pas de mise en place de connexion pouvant impliquer du délais sous forme de RTT.
-  Simple d'utilisation , pas d'état de connexion au niveau de l'envoyeur et du receveur.
-  Taille d'en-tête relativement petite, réduisant la taille des paquets.
-  Pas de contrôle de congestion. UDP peut envoyer aussi rapidement que désiré et peut fonctionner en cas de congestion.

On retrouve UDP dans :
- La téléphonie internet
- Les application de streaming multimédia
- DNS
- SNMP - *Simple Network Management Protocol*
- HTTP/3

Si un transfert fiable est requis pour UDP, ce dernier peut être ajouter au niveau de la couche application. De plus, un contrôle de congestion et un contrôle de flot peut être ajouté au niveau de la couche application.

### UDP : Actions au niveau de la couche transport
Soit un client et un serveur DNS arrangé comme suis :

<img src="https://i.imgur.com/TAFMIVC.png" width=500 />

**Actions côté envoyeur** : 
- Un message  ainsi qu'un identifiant de processus distant est passé par la couche application.
- Une en-tête de segment UDP est déterminé à la couche de transport.
- Cette en-tête est attachée au segment et passé à la couche réseaux / IP.

**Actions côtes receveur** : 
- Un segment est réceptionné à la couche réseaux.
- La couche transport vérifie la somme de contrôle (*checksum*) de l'en-tête et extrait le message du segment ainsi que l'identifiant de processus source.
- Le message est ainsi démultiplexé pour être envoyé à la couche application via le bon socket.

### En-tête de segment UDP
<img src="https://i.imgur.com/myEUuvR.png" width=350 />

### Checksum UDP

Une somme de contrôle ou checksum est une suite de bits envoyé avec un paquet UDP pour détecter les erreurs provenant de canaux bruités.

Au niveau de l'envoyeur, un traitement est effectué sur un segment UDP (incluant donc l'en-tête) pour déterminer une séquence d'entier sur 16bits. Cette séquence est ensuite additionnée pour former la somme de contrôle qui sera ajouter au champ checksum du segment UDP.

Au niveau du receveur, la somme est déterminée de la même manière que pour l'envoyeur puis comparée avec le champ checksum du segment UDP. Si la somme calculée et le checksum ne correspondent pas, alors une erreur est détectée.
> Il se peut qu'aucune erreur soit détectée mais pourtant qu'elle soit présente.

## 3.4 Principles de transfert de données fiables.

<center>
<img src="https://i.imgur.com/CUbvuLf.png" width=300 />
<img src="https://i.imgur.com/bQdp0ug.png" width=300 />
</center>

La figure n°1 explicite une abstraction d'un service fiable. Une communication est exécutée entre deux processus distants via un canal fiable. Cependant, la notion de canal fiable est peu réaliste (bruitage du canal, etc.).
La figure n°2 présente donc l'implémentation d'un service fiable de communication. Puisque le canal ne peut être considéré comme fiable, les données doivent pouvoir ce genre de canal.
La complexité d'un protocole de transfert de donnée va dépendre fortement des caractéristiques du canal peu fiable.

L'envoyeur et le récepteur ne connaissent pas l'état de chacun (par exemple si un message à bien été reçu.) sauf si communiqué par un message.

### Protocole de transfert de donnée fiable (RDT) : Les interfaces

- `rdt_send()` : Appelé par au dessus (par exemple une application). Les données sont transmises pour être livrées au récepteur à la couche supérieure.
- `udt_send()` : Appelé par RDT pour transmettre un paquet à un receveur via un canal peu fiable.
- `rdt_rcv()` : Appelé quand un paquet arrive du côté receveur du canal.
- `deliver_data()` :  Appelé par RDT pour délivrer les données aux couches supérieures.

### RDT : Pour commencer
Dans les points à suivre, nous allons développer de manière incrémentales les parties du protocole de transfère de données fiable (*reliable data transfert protocol* ou RDT). Nous ne considérerons uniquement les transfert de données unidirectionnels  (avec le contrôle d'information qui circule dans les deux directions). Nous utiliserons aussi un ensemble fini d'état machine (FSM) pour spécifier l'envoyeur et le receveur.

<img src="https://i.imgur.com/E3Kq032.png" width=500 />

> Type de graphe utilisé pour nos représentations

#### RDT 1.0 : Transfert fiable sur un canal fiable
Dans ce cas de figure, le canal utilisé est parfaitement fiable. Cela implique pas de perte de paquets et pas d'erreur de bit.
IL y a aussi une séparation entres les FSM de l'envoyeur et du receveur. L'envoyeur envoi les données via le canal et le receveur lis les données reçue par le canal.

<img src="https://i.imgur.com/m3Xspby.png" width=500 />

> Le graphe est plutôt simple, nous avons deux états reliés à eux-même. 
> Les seuls événements et actions prises par chacun sont l'envoit / la réceptions des paquet via les fonctions vue précédemment. 

#### RDT 2.0 : Canal avec erreur de bits
Dans ce cas de figure, le canal est peu fiable et peut engendre un échange de bit (*bit flip*).

Pour faire fasse à ces erreurs, les deux partis mettent en place un système de 'prise en connaissance' ou *acknowledgements* (ACKs) avec une notion de 'stop et attends'. Cela signifie que l'envoyeur envoi un paquet et attends un ACK du receveur. Tant que le ACK n'est pas reçu, l'envoyeur attends. Dans le cas où une erreur est détectée au niveau du checksum,  un NAK (*not acknoledged*) est envoyé du receveur vers l'envoyeur. Dans le cas où un receveur reçoit un NAK, il ré-envoi le dernier paquets.


<img src="https://i.imgur.com/mgLcYis.png" width=250 />


<img src="https://i.imgur.com/0041URV.png" width=500 />

> 🍏 : Opération sans erreurs


<img src="https://i.imgur.com/TUBDI3D.png" width=500 />

> 🔴 : Opérations avec erreurs


> ⚠️ "L'état" du receveur (savoir si un receveur à reçu correctement le message) n'est pas connu de l'envoyeur tant que le receveur ne lui communique pas.


Cependant il existe une faille majeure avec ce genre d'approche. Que faire quand le paquet NAK ou ACK à été corrompu par un bit flip ?.
Les paquets NAK et ACK sont aussi soumis à un système de checksum, cependant une fois qu'un ACK / NACK à été corrompu il n'est plus pris en compte. Comme le receveur ne sais pas si son ACK est bien arrivé à destination, cela peut conduire à des duplicatas de paquets.
Pour éviter les duplicatas, l'envoyeur ajoute un numéro de séquence à chaque paquet. Ainsi les paquets dupliqués peuvent être évités.

#### RDT 2.1 : Gestion par l'envoyeur des ACKs/NAKs corrompus

<img src="https://i.imgur.com/Qj4STp7.png" width=500 />

<img src="https://i.imgur.com/lZTNGfx.png" width=500 />

Du point de vue de l'envoyeur,  un numéro de séquence est ajouté aux différents paquets. Théoriquement, juste deux numéros de séquences ($0$ et $1$) sont suffisants pour différencier les paquets puisque ces derniers sont envoyés dans l'ordre avec une attente avant chaque ACK.
Il est obligatoire de vérifier si les ACKs /  reçu soient vérifiés par checksum. Cela implique deux fois plus d'états.

Du point de vue du receveur, il est obligatoire de vérifier si les paquets reçus sont des duplicatas via le numéro $1$ ou $0$.

#### RDT 3.0 : Canal avec erreurs et pertes

Dans ce cas de figure, le canal à la possibilité de perdre un paquet en plus d'intervertir des bit de manière aléatoire. Dès lors, les systèmes de checksum, de numéro de séquence et de retransmission ne sont plus suffisant pour contrebalancer les erreurs de canaux.

Une approche est donc de faire en sorte que l'envoyeur attends un temps raisonnable le prochain ACK / NAK. Si aucun ACK à été reçu dans le temps impartis, le dernier paquets est ré-envoyé. SI jamais le ACK à juste été retardé, cela implique de la duplication au niveau du receveur mais cela est déjà traitable par RDT 2.1

<img src="https://i.imgur.com/MwU2hDr.png" width=500 />

#### RDT 3.1 : NAKs ? Pour quoi faire ?

Puisque un  *timer* a été ajouté dans RDT 3.0, les NAKs ne sont plus nécessaire. Cela n'améliore pas le temps de récupération , mais cela n'est pas l'objectif.

<img src="https://i.imgur.com/MlTI7EZ.png" width=500 />

Cependant, il existe une faille dans RDT 3.1 quand un paquet ou un ACK est retardé, la retransmission va être dupliquée mais l'utilisation des numéros de séquences s'occupent déjà de ce problème. 
Il existe pourtant des conditions de "courses" entre de ACK reçu et le paquet transmit.

<img src="https://i.imgur.com/CUce1we.png" width=250 />

#### RDT 3.2 : Ajout de numéro de séquences au sein des ACK
L'idée est simple, le receveur doit spécifier un numéro de séquence de paquet pris en considération (ACK) 

<img src="https://i.imgur.com/oUzYzYI.png" width=250 />

#### RDT 3.2 : Protocole de l'alternance de bits (1969)
Il existe 4 cas de figures possible lors de l'utilisation de RDT 3.2

- **1. Pas de perte de paquets** : Les paquets ne sont pas perdu, l'envoyeur et le receveur communiquent à l'aide de paquets et de  classiques.

<center>
<img src="https://i.imgur.com/YeGo5Wq.png" width=250 />
</center>

- **2. Perte de paquets** : Un paquet est perdu lors de son envoi, après un temps défini l'envoyeur n'ayant pas reçu de ACK renvoi son paquet.

<center>
<img src="https://i.imgur.com/YSREnuf.png	" width=250 />
</center>

- **3. Perte de ACKs** : Un ACK est perdu et pas reçu par l'envoyeur, nous retrouvons le cas n°2 impliquant que le même paquet est renvoyé.

<center>
<img src="https://i.imgur.com/ezL40XD.png" width=250 />
</center>

- **4. Timeout prémature ou ACK retardé** : Le ACK n'est pas reçu dans les temps et provoque donc un Timeout prématuré. Puisque le Timeout est écoulé, l'envoyeur renvoi le même paquet qui sera donc un duplicata du coté receveur. Le receveur détecte le duplicata, le supprime et renvoi le ACK originellement retardé. Entre temps l'envoyeur à reçu le ACK original et se contente d'ignorer le duplicata de ACK.

<center>
<img src="https://i.imgur.com/sypZK0l.png" width=250 />
</center>

#### RDT 3.3 : Amélioration de la police des ACK

Plutôt que d'envoyer des paquets avec le mauvais numéro, le receveur envoi des ACK pour le dernier paquet reçu. 
La réception d'un duplicata de ACK provoque la même réaction que la réception d'un NAK du coté envoyeur ; renvoyer le paquet actuel.
Amélioration des performances avec des paquet retransmis plus tôt

#### RDT 3.3 : Faille
Avec RDT 3.2/3.3 il existe encore une faille majeur qui subvient dans les cas où un paquet est tellement retardé qui arrive après son paquet censé le succédé. Dès lors la détection de duplicata est pas possible puisque le receveur pense avoir reçu un nouveau paquet.
Une solution possible est soit d'étendre le temps avant un timeout soit d'étendre l'espace de numéro de séquençage (meilleure solution). 

<img src="https://i.imgur.com/eocEbN4.png" width=250 />

### Performances de RDT 3.2/3.3

Soit :
$U_{\text{sender}}$ : Utilisation $-$ fraction du temps où l'expéditeur est occupé à envoyer.

Par exemple : 
- Un lien de 1Gbps, avec 15 ms de [délais de propagation](#delay) et un paquet de taille 8000 bit?

Le délais de transmission d'un paquet dans un canal est de :
$$
D_{\text{trans}} = \frac{L}{R} = \frac {8000 \text{bits}}{10^9 \text{bits/sec}} = 8 \mu s
$$

#### RDT 3.2/3.3 : Opération *stop-and-wait* <a id=timerdt></a>

Cette opération se passe entre un envoyeur et un receveur. On défini le RTT (*round trip time*) comme le temps écoulé entre **le dernier bit transmit au canal depuis l'envoyeur** et **le premier bit du prochain paquet à envoyer par l'envoyeur.**.
Il faut prendre dès lors en considération le temps de propagation de l'information dans le canal qui doit être ajouté au RTT. Dès lors on considère l'instant $t$ comme :
$$
t = RTT + L/R
$$

Enfin nous pouvons donc calculer $U_{\text{sender}} = \frac{L/R}{t}$ :
$$
U_{\text{sender}} = \frac{L/R}{RTT + L/R} = \frac{.008}{30.008} = 0.00027
$$
> Rappel : Taux d'utilisation = transfert / temps écoulé

<center>
<img src="https://i.imgur.com/qBc1ovC.png" width=250 />
</center>

### Protocoles mis en pipeline (*pipelined protocols*)

Le principe de mise en pipeline permet à un envoyeur d'envoyer plusieurs paquet la suite qui doivent être ACK par le receveur (ACK aussi mis en pipeline). Cette manière de faire implique une augmentation de la portée des numéro d	e séquence ainsi qu'une mise en tampon au sein de l'envoyeur et du receveur.

#### Mise en pipeline  : augmentation de l'utilisation

Soit l'exemple présenté pour déterminer le temps de transfert de l'envoyeur de [RDT 3.2/3.3](#timerdt). Dans ce cas de figure l'envoyeur envoi 3 paquets l'un à la suite de l'autre.
Comme précédemment la définition du RTT ne change pas.  Dès lors le premier paquet est transmit à $t=0$ puis $t=L/R$ ect.

Nous pouvons donc facilement déterminer le taux d'utilisation par 
$$
U_{\text{sender}} = \frac{3L/R}{RTT + L/R} = \frac{.024}{30.008} = 0.00081
$$
> En toute logique, la mise en pipeline de 3 paquet augmente l'utilisation par un facteur 3

<img src="https://i.imgur.com/4hTwjrP.png" width=500 />

#### Mise en pipeline : Formes génériques <a id=pipeline></a>
Il existe deux formes générique pour la mise en pipeline :
- **Le Go-Back-N** ou (GBN)  : 
	-  L'envoyeur peut avoir jusqu'à $N$ paquets sans ACK en pipeline.
	- Le receveur peut seulement envoyer des ACK cumulatif, il ne peut pas ACK un paquet suivant un paquet déclaré manquant
	- Le timer de l'envoyeur est basé sur le plus vieux paquets sans ACK. Quand le timeout expire, alors tout les paquets sont renvoyé.
- **Le Selective Repeat** ou (SR) :
	-  L'envoyeur peut avoir jusqu'à $N$ paquets sans ACK en pipeline.
	-  Le receveur envoi un ACK individuel pour chaque paquet
	-  L'envoyeur maintient un timer spécifique pour chaque paquet sans ACK, lors d'un timeout le paquet spécifié est renvoyé.

#### Le Go-Back-N

Au niveau de l'envoyeur, on défini une fenêtre qui correspond à $N$ paquets transmit sans ACK. Cela implique un numéro de séquence sur $k$ bits dans l'en-tête du paquet. 

<img src="https://i.imgur.com/4sBZpli.png" width=500 />

La méthode du Go-Back-N utilise des ACK cumulatifs. Cela signifie que pour un ACK(n) reçu, tout les paquets de numéro de séquences au plus $n$ ont été reçu par le receveur. Puisque tout les paquets jusqu'à un numéro $n$ ont été reçu, la fenêtre se déplace pour commencer à $n+1$.
Comme énoncé précédemment, un seul timer est maintenu pour le plus vieux paquets pas encore ACK.  Une fois le timeout atteins, les paquets allant de $n$ jusqu'à la fin de la fenêtre sont renvoyés.

#### Go-Back-N : FSM de l'envoyeur

<img src="https://i.imgur.com/mqHADEE.png" width=500 />

#### Go-Back-N en action

<img src="https://i.imgur.com/sSail7Z.png" width=500 />

#### Selective Repeat
Dans ce contexte, le receveur envoi un ACK individuel par paquet correctement reçu. Les paquets sont parfois mis en zone tampon pour une livraison éventuelle vers une couche supérieure dans un ordre précis.
Comme énoncé précédemment, chaque paquets sans ACK possède sont timer associé. Lors qu'un timeout survient, les paquets mal envoyés sont renvoyés.
Du coté de l'envoyeur, une fenêtre de taille $N$ est toujours maintenue limitant ainsi les paquets sans ACK. Les numéros de séquences $s$ sont toujours des entiers de $0$ à $N$.

<img src="https://i.imgur.com/cufJ32Z.png" width=500 />

#### Selective Repeat : Envoyeur et receveur

Du point de vue de l'envoyeur :
- Lorsqu'un paquet est reçu de la couche supérieure , si le prochain numéro de séquences de la fenêtre est disponible le paquet est envoyé. 
- Lorsque le temps attribué à la réception d'un ACK d'un paquet, un timeout est exécuté et le paquet est renvoyé. (Le timer est remis à 0)
-  Un ACK(n) apparient à un ensemble $\{b, b+N-1\}$ avec $b$ la base de la fenêtre et $N$ la taille de la fenêtre. La réception d'un ACK(n) implique que le paquet n à bien été reçu. Lorsque $n$ paquets n'ont pas encore été ACK, alors la base de la fenêtre est déplacée au prochain paquets sans ACK.

Du point de vue du receveur :
- Un paquet $n$ est reçu. Ce paquet apparient à l'ensemble $\{b, b+N-1\}$ avec $b$ la base de la fenêtre de réception de taille N. Une fois le paquet reçu, un ACK est envoyé. 
- Si le système de livraison des paquets est défini comme "sans ordre" (*out-of-order*) alors un tampon est utilisé. Si le système de livraison des paquets est défini avec ordre, un tampon est aussi utilisé mais la fenêtre déplace sa base sur le prochain paquet pas encore reçu.

#### Selective Repeat en action

<img src="https://i.imgur.com/O1e6loM.png" width=500 />

#### Selective Repeat : Un dilemme
Soit des numéros de séquences allant de 0 à 3 et une fenêtre de taille 3.
Il existe un problème ou un paquets est acceptable si la fenêtre de réception possède le même numéro de séquence (voir figure 2)
<center>
<img src="https://i.imgur.com/O1e6loM.png" width=250 />
<img src="https://i.imgur.com/O1e6loM.png" width=250 />
</center>

#### Taille de fenêtre maximale avec SR

// TODO 

## 3.5 Transport orienté connexion : TCP
Pour rappel, TCP est :
- **défini comme "point à point"** : Il existe un envoyeur et un receveur
- **fiable et avec flux de bytes en ordre** : Pas de "frontière" au niveau des messaes
- **défini comme "données en duplex intégrale"** : Il y a un flux de données bidirectionnel entre l'envoyeur et le receveur. Le MSS est défini comme la taille maximale de segment.
- **ACK cumulatifs** : [c.f pipeline](#pipeline)
- **mis en pipeline** : Contrôle de congestion et de flots avec une taille de fenêtre fixe.
- **orienté connexion** : "Serrage de main", initialisation de l'envoyeur avant un quelconque échange de données.
- **contrôlé au niveau du flot** : L'envoyeur ne va pas surcharger le receveur

### Structure de segment TCP :

<img src="https://i.imgur.com/nWcgj4z.png" width=500 />

### Numéro de séquence et ACKs en TCP

Comme pour le GBN et le SR, on défini un numéro de séquence comme un numéro attribué à un segment de données.
Les ACKs sont strictement pareils, il s'agit du numéro de séquence perçu par le receveur. Un paquet est donc envoyé vers l'envoyeur avec ce numéro pour confirmer sa réception.
<img src="https://i.imgur.com/fZNeNDD.png" width=500 />

### TCP : L'envoyeur
Du point de vue de l'envoyeur, on distingue trois événements : 
- **Données reçue par la couche application** :  Un segment est crée avec un numéro de séquence, ce numéro de séquence est le numéro de flux du premier byte de données. Un timer est démarré s'il n'est pas actuellement lancé.
- **Timeout** : Le timer est écoulé, le segment qui à causé le timeout est retransmis et le timer redémarré.
- **Réception d'un ACK** : Mise à jour de se qui est considéré comme ACK et démarre un timer s'il reste des segments sans ACK.

<img src="https://i.imgur.com/v7JIn4W.png" width=500 />

#### Scénario de retransmission
<center>
<img src="https://i.imgur.com/K5gitAM.png" width=300 />
<img src="https://i.imgur.com/bgSsFWJ.png" width=120 />
</center>

#### TCP : retransmission rapide

SI un envoyeur reçois 3 ACK additionnels pour le même segment, il renvoit le segment sans ACK de plus petit numéro de séquence.

<img src="https://i.imgur.com/A2h4FDk.png" width=300 />

#### Génération de ACK au niveau du Receveur
|Evènement au niveau du receveur | Action du receveur TCP|
|:-|:-|
|Arrivée d'un segment en ordre avec un numéro de séquence attendu. Toutes les données jusqu'à un certain numéro de séquence sont déjà ACK.|ACK retardé. Attends jusqu'à 500 ms pour le prochain segment. Si pas de segment envoi un ACK|
|Arrivée d'un segment en ordre avec un numéro de séquence attendu. Un autre segment à un ACK en attente.| Envoi directement un seul ACK cumulatif qui a pour but de ACK les deux segment en ordre|
|Arrivée d'un segment pas en ordre, avec un numéro de séquence plus grand que celui espéré.| Envoi immédiatement un ACK dupliqué indiquant le numéro de séquence du prochain segment espéré.|
|Arrivée d'un segment qui remplis complètement ou partiellement le trou.| Envoi immédiatement un ACK, à condition que le segment commence à l'extrémité inférieure de l'écart.|

### Contrôle de flot
Le contrôle de flot occure dans les cas où la couche réseaux livre des données plus vites que la couche application les supprimes de sont buffer.
Ce contrôle à pour but de donner un certain niveau de pouvoir au receveur pour contrôler le l'envoyeur et éviter ainsi tout débordement de buffer.

Le receveur TCP annonce la place disponible dans son buffer à l'aide d'un champ disponible dans l'en-tête TCP appelé **rwnd**. La taille de `RcvBuffer` est définie via les option du socket mais est généralement de 4096 octets. Cependant , beaucoup de systèmes d'exploitations ajustent automatiquement cette taille.
L'expéditeur, quand à lui, limite la quantité de données sans ACK à la réception du **rwnd**. Cela permet de garantir que le tampon du receveur ne débordera pas.

#### Trois amélioration du contrôle de flot.

1. **Utilisation d'une fenêtre plus large :** Le débit TCP ne sais pas excéder le rwnd et le RTT. 16 bits sont requis au sein de l'en-tête TCP pour inscrire ce rwnd. Cela implique un rwnd max de $2^16$ octets limitant donc le débit TCP à 64Ko par RTT. TCP dispose cependant d'une option qui permet d'augmenter la taille de la fenêtre par un facteur $2^k$ pour $k \le 14$ et donc impliquant un rwnd max de $2^{30}$octets.
2. Réduire le coût total en groupant les octets quand l'application d'envoi écrit un seul octet à la fois dans le socket. (voir [point suivant](#nagle))
3. Syndrome de la fenêtre stupide (*silly window*) : Réduire le coût total quand l'application de réception  lis un seul octet à la fois sur le socket. (voir [points suivants](#silly))

#### Algorithme de l'ongle (*Nagle algorithm*) <a id=nagle></a>

Quand TCP reçoit des données d'un socket octet par octet (ou plus généralement des unité plus petites que le MSS de TCP (*maximum segment size*), des petits paquets sont envoyés immédiatement tandis que les autres sont mis en buffer jusqu'à ACK des petits paquets.
Quand tous les octets précédents ont été ACK, les segments traditionnels sont envoyés.

<img src="https://i.imgur.com/7P70Jn4.png" width=250 />

#### Syndrome de la fenêtre stupide (*silly window syndrome*) <a id=silly></a>
Malgré l'implémentation de l'algorithme *nagle*, il existe toujours un problème de performance quand une application lis un seul bit à la fois.
La solution employée est que le receveur envoi une mise à jour de fenêtre uniquement si son buffer est à moitié remplis ou si un segment peut être totalement reçu.

<img src="https://i.imgur.com/T7Y3lRS.png" width=250 />

### Gestion de connexion

Avant n'importe quel échange de données, le receveur et l'envoyeur effectuent se qu'on appelle une poignée de main (*'handshake'*).
Cette poignée de main vise à établir deux choses :
- Accord de connexion entre les deux participants.
- Accord des paramètres de connexions (numéro de séquence initial, MSS, options ,etc.)

#### Accord d'établissement de connexion
Plusieurs problématique sont a prendre en compte pour le bon fonctionnement de la poignée de main : 
- Les délais peuvent varier.
- Retransmission de message à cause de messages perdus
- Remise en ordre des messages
- Chaque parti ne connait pas le statu de l'autre.

#### Scénarios possibles

- **Poignée de main fonctionnelle** : 

<center><img src="https://i.imgur.com/WyWax1U.png" width=250 /></center>

- **Connexion à moitié ouverte** :  Le serveur n'accepte pas assez vite la demande de l'envoyeur. L'envoyeur renvoi une demande. Entre temps, la demande initiale à été validée, et le client se termine. Cependant la seconde demande du client est à nouveau validée par le serveur et une connexion est à moitié établie.

<center><img src="https://i.imgur.com/oQSODMl.png" width=250 /></center>

- **Données dupliquées** :  Le serveur n'accepte pas assez vite la demande de l'envoyeur. L'envoyeur renvoi une demande. Entre temps, la demande initiale à été validée par les deux partis et un premier  échange de donné est effectué. Cependant la seconde demande du client est à nouveau validée par le serveur, le client renvoi la même donnée, une connexion est a moitié établie avec en plus un duplicata.
<center><img src="https://i.imgur.com/yM9ncaD.png" width=250 /></center>

### TCP poignée de main à trois (*3-way handshake*)

<img src="https://i.imgur.com/gP4MmaO.png" width=500 />

Notation : 
- `SYN(x)` : SYNbit = 1 et Seq = x
- `SYN(y,x)` : SYNbit = 1, Seq = x, ACKbit = 1 et  ACKnum  = x
- `ACK(y)` : ACKbit = 1 et ACKnum = y

<img src="https://i.imgur.com/iT8XMVo.png" width=500 />

#### Choix des 32 bits initiaux du numéro de séquence

Comme vu précédemment, il faut choisir les valeurs initiale pour $x$ et $y$.
Cependant nous avons en contrainte que les valeurs de $x$ et $y$ ne doivent pas avoir été utilisées récemment par ce client spécifique et ce serveur spécifique (identification via numéro de port et adresse IP).
Nous pouvons définir le principe de 'récemment' via le MSL ou *TCP maximum segment lifetime*.
En pratique, TCP sélectionne $x$ et $y$ de manière aléatoire.

#### FSM de la poignée de main à trois

<img src="https://i.imgur.com/8LebfNZ.png" width=500 />

### Fermeture d'une connexion TCP

Le client et le serveur doivent chacun fermé leurs connexion de leur côté. Cela est fait à l'aide d'un champ dans le segment TCP appelé FIN (il s'agit d'un bit qui est mis à 1 quand la connexion est finie).Cette action est faite par les deux partis.
Pour garantir une bonne fermeture, les FIN sont pris en compte par des ACK (qui peut lui même se combiner avec un FIN).

<img src="https://i.imgur.com/WTb5WHC.png" width=500 />

#### FSM de la fermeture d'une connexion

<img src="https://i.imgur.com/Rp6f4oO.png" width=500 />

## 3.6 Contrôle de congestion de TCP

De manière informelle, la congestion occurre quand trop de sources envoient trop de données trop vites pour un réseaux. Cela se traduit généralement par de long délais (le temps de mettre en tampon pour les buffer) et des pertes de paquets (du au dépassement de ces tampons).
Pour rappel, la congestion est différentes du contrôle de flot. Le contrôle de flot se passe dans un contexte où un seul envoyeur est trop rapide pour un seul receveur.

### Approche en matière de contrôle de congestion
Dans le cas de **congestion de bout en bout**, il n'existe pas de retour explicite du réseaux décrétant un cas de congestion. La congestion peu uniquement être supposée lorsque des pertes et des délais se produisent de par le fait qu'aucun élément du réseaux est au courant de l'état de tout autres éléments.  Cette approche est employée par TCP.

Dans le cas de **contrôle de congestion assisté par le réseau**, les routeurs fournissent un retour direct sur les hôtes envoyeurs / receveurs dont le flux est congestionné. Ce genre de méthode peu indiquer aussi un niveau de congestion voire même définir le taux d'envoi. Cette approche est employée par TCP ECN, ATM, les protocoles de DECbit mais n'est pas étudiés dans ce cours.

### Contrôle de congestion TCP  : AIMD
Dans ce cas de figure, l'envoyeur peut augmenter sont taux d'envois jusqu'à se qu'une perte de paquet occurre. Dès qu'une perte de paquet est détectée, le taux d'envois est réduit. On remarque alors un comportement en dent de scie.
On parle alors de :
-  <span style="color:lime">**Incrément additif**</span> : Augmente le taux d'envois de 1 MSS (*'maximum segment size'*) chaque RTT (*'round trip time'*) jusqu'à détection d'une perte.
- <span style="color:red">**Décrément multiplicatif**</span> : Coupe le taux d'envois par deux à chaque perte de paquet via détection par triple ACK dupliqué (congestion légère). Coupe le taux d'envois par un MSS quand une perte est détectée via timeout (congestion plus sévère).

<img src="https://i.imgur.com/6XDaBNC.png" width=500 />

AIMD est un algorithme asynchrone distribué qui permet d'optimiser les taux de flux congestionnés sur un réseaux entier en plus d'avoir des propriétés stables.

### Fenêtre de congestion de TCP (**cwnd**):

Le comportement adopté par TCP en matière d'envois est le suivant : 

- Envoi des octets cwnd, attends un RTT pour des ACKs, enfin envois plus d'octets (taux d'environ ; $\frac{\text{cwnd}}{\text{RTT}}$bps)

La limite de transmission de l'envoyeur est donc : $\text{Dernier bit Envoyé} - \text{Dernier bit ACK} \le \text{cwnd}$. 
cwnd est donc dynamiquement ajuté en réponse à un réseaux congestionné.

<img src="https://i.imgur.com/un3Gx0c.png" width=300 />

### TCP : Démarrage lent

Quand la connexion commence, le taux augmente de manière exponentielle jusqu'à la première perte. Initialement cwnd est d'1 MSS et cwnd et cwnd est diybké à chaque RTT. Le taux initial est donc lent mais augmente de manière exponentielle.

Cependant un tel comportement est risqué car il peut provoqué de la congestion sur les réseaux. Il faut donc que TCP passe d'un comportement exponentielle à linéaire en matière de taux d'envois.
Ce passage vers un comportement linéaire se produit quand cwnd arrive à la moitié de sa valeur avant un timeout. Cependant comme un timeout est imprédictible, une variable `sstresh` est maintenue contenant la dernière valeur de cwnd divisé par deux avant une perte.
Dès lors la croissance linéaire est décrite comme $\text{cwnd} =\text{cwnd} + (\text{MSS} / \text{cwnd})MSS$ pour chaque ACK reçu.

### FSM du contrôle de congestion TCP:
<img src="https://i.imgur.com/ELx83aH.png" width=500 />


### Débit du TCP en régime permanent
On défini le débit utile comme le débit utilisé pour une réelle transmission de données importante (on ne considère par les en-tête, les duplicata, les octets retransmit etc. ).

Un régime permanent par du principe qu'il y a un niveau stable de congestion sur le réseaux.

Nous pouvons déterminer le débit utile moyen de TCP en tant que fonction de la taille de la fenêtre en fonction des RTT : 
- $W$ est la taille de fenêtre (mesuré en MSS) quand une perte occurre.
- Quand la taille de fenêtre est $W$ alors le débit utile est $W/ \text{RTT}$.
- Juste après une perte lors de congestion légère, le débit utile est $0.5W/ \text{RTT}$
- La moyenne est donc $0.75W/ \text{RTT}$

- La taille moyenne de fenêtre = $3W/4$
- Le nombre de MSS par cycles =  $3W/4 . W/2 = 3W^2/8$
- Si l'on suppose  une perte de paquet par cycle, on a $p=1 / (3W^2/8)$ (ratio de perte de paquets)

Donc $W = \sqrt(8/3p)$

Le débit utile moyen de TCP est donc  (en bps) = $\sqrt{3/2} \frac{\text{MSS}}{\text{RTT}\sqrt p}$

### Future de TCP : TCP via de gros et long tuyaux
Exemple ; Nous disposons de segments de 1500 octets, d'un RTT de 100ms et nous voulons un débit utile de 10 Gbps

La taille moyenne de la fenêtre doit donc être de $W=83333$ segments.

Si nous considérons le débit moyen utile de TCP :  $1.22 \frac{\text{MSS}}{\text{RTT}\sqrt p}$ nous aurions besoins d'un taux de pertes de paquets de l'ordre de $2 . 10^{10}$ soit un nombre très petit. Il nous faut donc forcément une nouvelle version de TCP.

### Equitabilité de TCP

Le principe d'équitabilité en réseaux est plutôt simple. Si $k$ sessions TCP sont ouvertes et partagent le même lien de capacité $R$ alors le taux de chacun devrais être de $R/k$

<center>
<img src="https://i.imgur.com/A0V1h6X.png" width=300 />
</center>

TCP st considéré comme équitable dans des cas idéalisés où les RTT sont les même et le nombre de sessions est fixe.

<center>
<img src="https://i.imgur.com/JOaIRu2.png" width=400 />
</center>

Quand les deux RTT sont différents (par exemple l'un deux fois plus grand que l'autre), la connexion initiale s'intensifie deux fois plus vite. Il 'agit d'un comportement inversement proportionnel au RTT

<center>
<img src="https://i.imgur.com/6MvhN54.png" width=400 />
</center>

### Equitabilité : Réel  besoin d'être équitable ?

- **Du point de vue UDP**: 
	- Les applications multimédia utilisent rarement TCP ( pas de taux de transfert limité par un contrôle de congestion)
	- Les paquets sont envoyés à un taux constant et les pertes sont autorisées. On dis alors que UDP n'est pas amical avec TCP (*TCP friendly*) 
	- Il n'y à pas de réelle régulation en matière de congestion sur internet.
- **Du point de vue TCP**: 
	- Les applications peuvent ouvrir de multiples connexions TCP entre deux hôtes (par exemple les navigateurs web)

## 3.7 Evolution des fonctionnalités de la couche transport
TCP et UDP sont les principaux protocoles de transport depuis 40 ans. Différentes version de TCP ont été développé pour des scénario spécifiques :

|Scénario|Enjeux|
|:-:|:-:|
|Gros transfert de données| Beaucoup de paquet transféré, une perte ferme le pipeline|
|Transport sans fil| Pertes due à des canaux bruités, mobilité. TCP traite cela comme de la perte de congestion|
|Lien avec long délais| RTT extrêmement long|
|Réseaux de centre de données| Sensible à la latence|
|Flux de trafic en arrière plan| Priorité faible|

Certains protocoles ont déplacés des fonctionnalités de la couche transport au niveau de la couche application au dessus de l'UDP. C'est le cas de HTTP/3 avec QUIC.

### QUIC : '*Quick UDP internet connection*'
Comme énoncé précédemment, il s'agit d'un protocole de la couche application qui s'ajoute à UDP. Il permet une amélioration de performance de HTTP et est déployé sur beaucoup de serveurs google.

<img src="https://i.imgur.com/Xs9PRd7.png" width=400 />

#### QUIC : Etablissement d'une connexion

Contrairement à TCP qui effectue deux poignée de main en série (TCP (fiabilité , état du contrôle de congestion) + TLS(authentification)) , QUIC effectue une unique poignée de main qui reprends les points de fiabilités, contrôle de congestion, authentification.

#### QUIC : Flux, parallélisme et pas de blocage HOL 

<img src="https://i.imgur.com/kCN7wGE.png" width=500 />


# Chapitre 4 : La couche de Réseaux - Le plan de données

## 4.1 Couche Réseaux : vue d'ensemble

### Protocoles et services de la couche réseau
Le principe de la couche de réseaux est de transporter un segment d'un hôte envoyeur à un hôte receveur. L'envoyeur encapsule le segment dans un paquet qui est à son tour donné à la couche lien. Le receveur à l'opposé livre les segments à la couche de transport.

On retrouve les protocoles réseaux dans tous les dispositifs Internet ; hôte et routeurs.

Un routeur est un dispositif qui examine les champs d'en-tête de chaque paquet IP passant par ce dernier. En fonction de cette en-tête, il redirige le paquet vers un port de sortie pour permettre l'acheminement de ce dernier sur le réseaux.
<center>
<img src="https://i.imgur.com/Zkg93Oc.png" width=350 />
</center>

### Deux fonctions clés de la couche réseau

- **La redirection** (ou *forwarding*) : déplace un paquet du lien d'entrée d'un routeur vers le lien de lien de sortie approprié du routeur.
- **Le routage** (ou *routing*) : détermine la route prise par un paquet de la source à la destination.

### Couche réseaux : Plan de donnée et plan de contrôle

- **Plan de donnée** : Fonction locale, par routeur dont le but est de déterminer comment les paquet arrivent sur le port d'entrée du routeur doivent être redirigées sur le port du sortie du même routeur.
- **Plan de contrôle** : Logique sur l'ensemble du réseaux dont le but est de déterminer comment un paquet est dirigé parmi les routeurs d'un chemin allant d'un hôte source à un hôte de destinations. On retrouve deux approches vis à vis de cette logique ;
	- Un algorithme de routage traditionnel implémenté au sein d'un routeur
	- Un réseau défini par logiciel implémenté dans un serveur (parfois distant).

### Plan de contrôle par routeur
Les composants individuels de l'algorithme de routage dans chaque routeur interagissent dans le plan de contrôle.

<img src="https://i.imgur.com/itDgjNq.png" width=500 />

### Réseau défini par logiciel (SDN)
Un contrôleur distant détermines et installe les tables de redirections (*forwarding tables*) dans les routeurs en interagissant avec les agents de contrôle des routeurs.

<img src="https://i.imgur.com/8JWePVg.png" width=500 />

### Modèle de service de la couche réseau

Le modèle de service de internet est celui du meilleur effort, c'est à dire aucune garantie sur :
- Le succès de livraison de paquet à une destination.
- La livraisons dans l'ordre et dans les temps.
- La disponibilité de la bande passante lors du flux end-end.


<img src="https://i.imgur.com/gOo5biT.png" width=500 />

## 4.2 Le protocole internet  IP (*internet protocol*)

### Couche réseaux  : internet

Fonctionnalité de la couche réseaux au sein d'un hôte / d'un routeur : 
- **Algorithme de sélection de chemin** : Implémenté dans les protocoles de routage (OSPF, BGP) et le contrôleur SDN. Il permet de déterminer la table de redirection.
- **Protocole IP** : Format du paquet, adressage et conventions de gestion de paquets
- **Protocole ICMP** : Rapport d'erreur et signalement du routeur

### Adressage IP : Introduction

Une adresse IP est un identifiant sur 32-bit associé à chaque hôte et chaque interface de routeur.
Une interface est une connexion entre un hôte/routeur et un lien physique. Les routeurs ont généralement plusieurs interfaces et un hôte une seule (parfois multiple dans le cas de différences de types de connexion : câblé et wifi). Une adresse IP est donc associée à une interface.

Une adresse IP est représentée comme 32-bit séparé en 4 décimale sur 8bit par un point :
```c
223.1.1.1 = 11011111.00000001.00000001.00000001
```
<center>
<img src="https://i.imgur.com/ExsfKKs.png" width=350 />
</center>

#### Sous-réseaux (*subnet*)
Un sous-réseaux est un ensemble d'interfaces de compostant qui peuvent s'atteindre physiquement sans passer par un routeur.
Les adresses IP possèdent une structure : 
- La partie sous-réseaux ou le préfixe d'adresse : les composants d'un même sous réseaux possède les même bits d'ordre élevé
- La partie hôte : Les bits d'ordre bas restant.

L'illustration au point précédent démontre un réseaux à 3 sous-réseaux.

Pour déterminer un sous-réseaux, il suffit de détacher chaque interface de son hôte/routeur créant ainsi un réseaux isolé.

Le plus souvent une adresse IP est représenté avec un maque de sous-réseaux :
```c
223.1.1.0/24
```

Ce masque indique que les 24 bits d'ordre élevé représente la partie sous réseaux de l'adresse IP, c'est à dire :
```c
223.1.1.0 = 11011111.00000001.00000001.00000000

```
Les 24 premiers bits étant : 
```c
223.1.1
```

### Classe d'adresses obsolète

Dans le passé, les préfixe réseaux était contraints à 8, 16 ou 24 bits en longueur, respectivement pour les classes A, B, et C. Cela était pas des plus pratiques puisque la classe C par exemple était trop petite pour plusieurs organisations se qui conduisait rapidement à un épuisement des adresses de classes B. Cependant la classe B était trop large et impliquait une mauvaise assignation d'adresses.


- **Classe A** : $0$ + 8bits de réseaux + 23 bits d'hôtes $\to$ maximum de 256 sous-réseaux de $2^{23}$ hôtes (+8M). Adresse de `1.0.0.0` jusqu'à `127.255.255.255`.
- **Classe B** : $10$ + 16bits de réseaux + 14 bits d'hôtes $\to$ maximum de $2^16$  sous-réseaux (+65K) de $2^14$ hôtes (+16K) . Adresse de `128.0.0.0` jusqu'à `191.255.255.255`.
- **Classe C** : $110$ + 24bits de réseaux + 5 bits d'hôtes $\to$ maximum de $2^{24}$  sous-réseaux (+1M) de $2^5 = 32$ hôtes. Adresses de `192.0.0.0` à `223.255.255.255`.
- **Classe D** : $1110$ + 28bits d'adresses multicast. Adresse de `224.0.0.0` à `239.255.255.255`
- **Classe E** : $1111$ + 28bits d'adresse réservée pour utilisation future. Adresse de `240.0.0.0` à `255.255.255.255`

### Adressage IP : CIDR

CIDR correspond à l'acronyme *Classless InterDomain Routing* ou Routage inter domaine sans classe. 
Dans ce cas de figure, la portion d'adresse sous réseaux est de taille arbitraire déterminée par une nouvelle composante $x$ de l'adresse :
```c
a.b.c.d/x
```

où $x$ défini la portion d'adresses sous réseaux.

Par exemple pour $x=23$, les 23 premier bits sont réservé au sous-réseaux tandis que les $9$bits restant concernent les hôtes.
Pour déterminer l'adresse de sous-réseaux, il suffit d'appliquer un masque, dans notre cas 23bit à 1 et 9 bit à 0 :
`11111111 11111111 11111110 00000000`

### Adresses IP spécifiques : 
Il existes plusieurs adresse dédiées par défaut :
- **L'adresse nulle** : `0.0.0.0`, correspond à l'hôte actuel .
- **L'adresse pleine**: `255.255.255.255`, diffusion sur le réseau local
- **Les adresses de boucles**: `127.a.b.c`, par exemple `Localhost` est en `127.0.0.1`
- **Les parties hôtes d'adresse**: ensemble de $0$ suivit par l'adresse hôte
- **Diffusion sur réseaux distant** : adresse du réseaux suivit par un ensemble de 1

<img src="https://i.imgur.com/TXicJsi.png" width=500 />

### Protocole de configuration d'hôte dynamique : DHCP

Il existe plusieurs façon pour un hôte d'obtenir une adresse IP : 
- **Manière statique** : L'adresse est encodée manuellement par l'administrateur système au sein d'un fichier de config.
- **Manière dynamique**  : L'hôte obtient de manière dynamique une adresse IP d'un serveur réseaux quand il le rejoint. Protocole DHCP

Le protocole DHCP permet le renouvèlement de certaines adresses allouées, la réutilisation d'adresse et le support d'utilisateurs mobiles qui joignent / quittent le réseaux.

Pour se faire l'hôte diffuse un paquet `DHCP discover msg [optional]`, le serveur DHCP répond avec un paquet `DHCP offer msg [optional]`. L'hôte requête une adresse via `DHCP request msg` et le serveur confirme l'adresse via `DHCP ack msg`.

#### DHCP :  Scénario client-serveur

Généralement, le serveur DHCP est colocalisé au sein du routeur, servant tout les sous-réseaux auxquels le routeur est attaché.

Lorsqu'un client sans adresses IP arrive sur un réseaux, les étapes suivantes se produisent :
1. Le client diffuse une demande de reconnaissance pour savoir s'il y a un serveur DHCP
2. Le serveur DHCP réponds à cette demande et fourni une première adresse IP.
3. Le client accepte l'adresse IP et et le fait savoir au serveur DHCP
4. Le serveur DHCP envoi un ACK en **diffusion** (*broadcast*) pour confirmer que l'adresse IP est utilisée.

> ⚠️ Les deux première étapes peuvent être passées si le client a retenu et souhaite réutiliser une ancienne adresse IP
> Le serveur DHCP envoi sont ACK en diffusion pour indiquer aux autres machines du réseaux que l'adresse IP est prise.
> Le protocole DHCP utilise UDP et non TCP // TODO
> Le serveur DHCP ne renvoi pas qu'une adresse mais aussi le nom et l'adresse IP du serveur DNS local, le masque réseaux et l'adresse du premier routeur par rapport au client.

<center>
<img src="https://i.imgur.com/N05FI7w.png" width=500 />
</center>

#### DHCP : Exemple

- Un ordinateur portable désirant se connecter à un réseaux utilisera DHCP pour obtenir une adresse IP, l'adresse IP du premier routeur disponible et l'adresse du serveur DNS local.
- Le message de requête DHCP est encapsulé dans UDP, puis IP, puis Ethernet.
- La trame Ethernet est diffusé sur le réseaux local (LAN) et reçu par un routeur qui fait tourner un serveur DHCP.
- La trame Ethernet est décapsulé, puis le paquet IP, puis le paquet UDP, puis le message DHCP
- Le serveur DHCP formule un ACK DHCP qui contient l'adresse IP du client , l'adresse du premier routeur, le nom et l'adresse du serveur DNS local.
- La réponse DHCP est transférée au client qui le décapsule jusqu'au niveau DHCP.
- Le client connait son adresse IP, etc.

### Obtention d'une adresse IP par le serveur

Le serveur obtient sa partie sous-réseaux de son adresse IP par son ISP. En effet, une portion de l'espace d'adressage de l'ISP lui est alloué. On parle d'adresses assignées par le fournisseur ou PA (*Provider Assigned addresses*).

Par exemple le bloque d'adresse de l'ISP est :
`11001000 00010111 00010000 00000000 = 200.23.16.0/20`
Les 20 premiers bits servent donc à l'identification de l'ISP :
`11001000 00010111 0001.... ........`

L'ISP peut donc allouer son espace d'adressage par exemple en 8 bloques (3 bits additionnels au 20 premier bits `000` à `111`) : 
```
Organisation 0 : 11001000 00010111 0001000. ........ = 200.23.16.0/23
Organisation 1 : 11001000 00010111 0001001. ........ = 200.23.18.0/23
Organisation 2 : 11001000 00010111 0001010. ........ = 200.23.20.0/23
...
Organisation 7 : 11001000 00010111 0001111. ........ = 200.23.30.0/23
```
### Adressage hiérarchique : agrégation de routes

L'adressage hiérarchique permet une annonce efficace des informations de routage.

<center>
<img src="https://i.imgur.com/lGpETXl.png" width=500 />
</center>

> Dans cet exemple nous pouvons par exemple déterminer que toutes adresses commençant par `200.23.16. x/23` est une adresse de l'ISP *fly-by-night*

#### Adresses indépendantes de fournisseurs (PI *provider independent*) : Multihoming

Imaginons comme alternative qu'une organisation 8 obtiennent une gamme d'adresses indépendantes d'un fournisseur. L'organisation 8 peut avoir plusieurs fournisseurs (principe de multihoming) 

<center>
<img src="https://i.imgur.com/WRfxzuI.png" width=500 />
</center>

#### Tables de redirections IP
Imaginons que la redirections se base uniquement sur les adresses de destination. Comme une adresse est sur $32$bits, nous pouvons donc avoir $2^{32}$ (+4Md) adresses IPv4 différentes. Cependant, toutes les adresses d'un sous-réseaux peuvent être agrégée en une seule entrée de redirection dans la table. Cela permet de sauvegarder de l'espace et permet en plus de rendre la recherche d'adresses plus efficaces.

- **Table de redirection de l'ISP *fly-by-night***  :

|Gamme d'adresses de destination| Lien d'interface sortant|
|:-:|:-:|
|`200.23.16.0`|0|
|`200.23.18.0`|1|
|`200.23.20.0`|1|
|...|...|

#### Agrégation supplémentaire dans les tables de redirection
En reprenant notre exemple de l'ISP *fly-by-night*, il est possible d'agrégé les 8 organisations en une seule adresse étant `200.23.16.0/20` (⚠️ le masque n'est plus `/23`). Cependant une table de redirection est toujours nécessaire au sein de  l'ISP *fly-by-night* pour rediriger vers la bonne compagnie.

<center>
<img src="https://i.imgur.com/akiL4Da.png" width=500 />
</center>

#### Adressage hiérarchique : Routes plus spécifiques
Imaginons que  l'ISP *fly-by-night* acquiert un autre ISP du nom de *ISPs-R-U* et que l'organisation 1 de la gamme d'adresses de *fly-by-night* passe chez *ISPs-R-U* pour une raisons quelconque. Il est nécessaire que l'organisation 1 garde  sa gamme d'adresse pré attribuée pour éviter une refonte totale de son réseaux. Dès lors l'ISP *ISPs-R-U*  doit maintenant faire l'annonce des adresses de organisation 1.

<center>
<img src="https://i.imgur.com/yK2CYvH.png" width=500 />
</center>

#### Tables de redirections IP : chevauchement
Dans cet exemple, les tables de redirections au sein d'internet auront deux entrée se chevauchant en les adresse :
- `200.23.16.0/20` : après le masque `11001000.00010111.0001`
- `200.23.18.0/23` : après le masque `11001000.00010111.0001001`

> Nous remarquons que les deux adresses une grande partie de leurs préfixes en commun. Dès lors un paquet reçu destiné à `200.23.16.0` pourrait être envoyé à  `200.23.18.0`.


Une solution pour éviter ce problème est de prendre en considération la règle du plus long préfixe correspondant.

#### Plus long préfixe correspondant

Le principe est plutôt simple, lorsque un recherche une adresse dans la table de transfert pour une adresse de destination donnée, on utilise le plus long préfixe d'adresse qui correspond à notre adresse de destination.

<center>
<img src="https://i.imgur.com/bMjY20J.png" width=500/>
</center>

Par exemple  :
- `11001000.00010111.00011000.10100001` est redirigé vers le l'interface 1
- `11001000.00010111.00010010.10101010` est redirigé vers l'interface 2

Le principe de correspondance de préfixe fais sens si les entrées avec les même préfixe sont dans la même régions. Cela conduit à des table de préfixe plus petites. En effet il suffit de faire une entrée par sous réseaux où une entrée par agrégation de sous réseaux partageant un même préfixe.

Le principe de correspondance du plus long préfixe permet encore plus d'agrégation mais implique une procédure de recherche plus complexe.
Cela mène à des problème de performances. La correspondance d'adresse est souvent performée au sein matériel à l'aide de mémoire adressable à contenu ternaire (TCAMs *Ternary Content Addressable Memories*). Cela permet de retrouver une interface selon une adresse présentée en un cycle d'horloge peut importe la taille de la table (qui peut monter à ~1million d'adresse stockée)

### Obtention de bloques d'adresse pour les ISP
Les ISP obtiennent leur bloque d'adresses via l'ICANN (*Internet Corportation for Assigned Names and Numbers*) qui allouent les adresses IP via 5 registres régionaux. Cette instance gère la zone de la racine DNS et la délégation de gestion de TLD individuel (.com, .edu , etc.)

### Y a-t-il assez d'adresse IP en 32bit ?

L'ICANN à attribué le dernier morceaux d'adresse IPv4 en 2011. Il existe le principe de NAT qui permet d'éviter l'épuisement d'adresse IPv4. Cependant IPv6 à un espace d'adressage de 128-bit soit ($>3.10^{38}$ par rapport au $>4.10^9$ adresses en 32 bit)

### Traduction d'adresses réseaux (NAT *network address translation*)

Tout les appareils d'un même réseaux local partage une seule adresse IPv4 lorsque perçu par le monde extérieur.
Tout les paquets quittant un réseaux local ont la même adresse NAT IP source (138.78.29.7 selon l'exemple ci-dessous) mais différent numéro de port sources.
Les paquets avec une source ou une destination dans le réseaux ci-dessous possèdent une adresse `10.0.0.0/24` pour la source ou la destination.

<img src="https://i.imgur.com/uA6o6Wr.png" width=500/>

Tout les appareils d'un même réseaux local possède une adresse  32bit dans un espace d'adressage IP privé. Cela donne comme avantages :
- Il faut uniquement une seul adresse IP publique d'un ISP pour tout les appareil d'un réseaux local.
- Il peut y avoir un changement d'adressage au sein du réseaux local sans avoir à notifier le monde.
- On peut changer l'ISP sans changer toutes les adresses d'appareils du réseaux local.
- En terme de sécurité, les appareils au sein d'un réseaux local ne sont pas directement accessible par le monde extérieur.

En terme d'implémentation , un routeur NAT doit de manière transparente : 
- **Remplacer** l'adresse IP source et le numéro de port  de chaque paquets sortants avec l'adresse IP du NAT et le nouveau numéro de port. Les clients distants / serveurs répondront en utilisant l'adresse IP NAT et le numéro de port comme adresse de destination.
- **Se rappeler** au sein de sa table de traduction chaque tuple (Adresse IP source, Numéro de port) vers (Adresse IP NAT, nouveau numéro de port).
- **Remplacer** l'adresse de destination IP NAT et le numéro de port avec l'adresse IP locale et le numéro de port stocké dans la table de traduction NAT.

<img src="https://i.imgur.com/vFwM4XU.png" width=500/>

Il est possible de restreindre le trafique entrant encore plus. Par exemple seulement contacter l'hôte extérieur, en ajoutant des champs dans le côté WAN (*wide access network*) de la table.
Comme le champ de numéro de port est sur 16bit, plus de 65k connexions en simultanés sont possible avec une seule adresse coté LAN (*local access network*).

Nat à été controversé pour les raisons suivantes : 
- Les routeurs devrai uniquement traiter jusqu'à 3 couches.
- Le manque d'adresse IPv4 devrait être résolu par IPv6
- Ne respecte pas la condition d'argument end-to-end (manipulation de numéro de port par les appareils de la couche réseaux)

Cependant NAT est souvent utilisé dans les réseaux domestique, les réseaux d'institutions et les réseaux cellulaires 4G/5G.

#### NAT : Problème de la traversée

Mettons un client veux se connecté à un serveur avec l'adresse `10.0.0.1`. L'adresse du serveur est local à un LAN et seul l'adresse NAT est visible (ici `138.76.29.7`).

<center>
<img src="https://i.imgur.com/LhsSNuP.png" width=250/>
</center>

Une première solution est de configurer de manière statique NAT pour transférer les requêtes de connexion au serveur via le port correspondant (par exemple les requêtes pour `138.76.29.7` au port `2500` seront toujours transférer à l'adresse `10.0.0.1` au port `25000`) 


Une seconde solution est le *Plug and Play* universel (UPnP) *Internet Gateway Device* (IDG) Protocol qui permet au hôtes avec un NAT d'apprendre l'adresse IP publique et d'ajouter / supprimer le mappage de port.

<center>
<img src="https://i.imgur.com/Q27mowI.png" width=250/>
</center>

Une troisième solution (utilisée par Skype) est le principe de relais. Un serveur utilisant NAT établis une connexion à un relais. Les client se connectent à ce relais et le relais transfert les paquets entre deux connexions internet.

<center>
<img src="https://i.imgur.com/WzcWfM5.png" width=400/>
</center>

### Format de paquets

<center>
<img src="https://i.imgur.com/w0s3lzm.png" width=250/>
</center>

### Fragmentation et réassemblage de paquet

Les liens réseaux possède une taille de transfert maximale ou MTU (*max transfert size*) qui défini la taille maximale d'un cadre au niveau de la couche réseaux. Différent types de liens impliquent différent MTU
Les gros paquets IP sont le plus souvent divisé (fragmenté) au sein du réseaux. Dès lors un paquet devient plusieurs paquets qui sont réassemblé une fois arrivés à destination. Si les fragments sont aussi trop gros, ces dernier peuvent être encore une fois fragmentés. 
Les bits d'en-tête IP sont utilisés pour identifier et réarranger les fragments.

 #### Exemple :
 Soit un paquet de 4000 octets (4Ko) et un lien dont le MTU est de 1500 octets (1.5Ko).
 Le paquet est divisé en trois sous paquets de taille respective : 1500 octets - 1500 octets et 1040 et plusieurs informations sont ajoutés aux fragments : 
 
<center>
<img src="https://i.imgur.com/k6TprTL.png" width=300/>
</center>

> Un `offset = 0` implique qu'il s'agit du premier fragment.
> Un `fragflag = 0` implique qu'il s'agit du dernier fragment. Il s'agit d'une copie de la valeur `fragflag` avant segmentation.


### IPv6

La motivation de créer une nouvelle version de IPv4 à été le fait que l'espace d'adresses IPv4 sur 32 bits allait être complètement alloué. De plus, les en-tête de IPv6 sont fixée à 40 octets et implique aucune fragmentation au sein des routeurs. Cela permet donc différent traitement de flux au sein de la couche réseaux. 
Enfin , le passage d'IPv4 à IPv6 implique aucun changement dans les protocoles de couche inférieur et supérieure.

#### Format de Paquet IPv6

<center>
<img src="https://i.imgur.com/n8OcYUP.png" width=500/>
</center>

Par rapport à IPv4 nous remarquons qu'il n'y à plus de *checksum* au sein de l'en-tête pour faciliter le traitement par routeur.
Pas de fragmentation ou de réassemblage (seulement possible au niveau de la source).
Pas d'option disponible pour les couches supérieurs.

#### Représentation d'une adresse IPv6

Une adresse IPv6 est représentée par 128 bits de la formes `x:x:x:x:x:x:x:x` où `x` est un nombre de 16 bit écrit en hexadécimal. Par exemple `2001:0000:130F:0000:0000:09C0:876A:130B`.
Les suites de 0 dans les champs sont optionnels : `2001:0:130F:0:0:09C0:876A:130B`
Enfin les suite successive de 0 unique peuvent être représenté par `::` mais seulement une seule fois au sein de l'adresse :`2001:0:130F::::09C0:876A:130B`
 
 #### Hiérarchie dans les adresse IPv6
 Une hiérarchie d'adresse permet de faire de l'agrégation. Par exemple un préfixe de 64bit (dont la partie initiale de 48bit à été fournie par l'ISP) identifie un site.  Le suffixe de 64bit identifie une interface sur ce site.
 
 ### Transition d'IPv4 à IPv6
 Malheureusement, tous les routeurs ne peuvent pas être remplacé d'un coup de manière simultanée pour rendre compatible IPv6.
 
 Dès lors une stratégie de mise en tunnel (*tunneling*) est utilisée et permet à un paquet IPv6 d'être porté en tant que charge d'un paquet IPv4 parmi les routeurs IPv4. Il s'agit en quelque sorte d'un paquet au sein d'un paquet. Le *tunneling* est souvent utilisé dans d'autres contextes.
 
<center>
<img src="https://i.imgur.com/QPhESsG.png" width=400/>
</center>
 
 #### Mise en tunnel et encapsulation
 Plusieurs cas de figure sont à prendre en compte :
 
- **Plusieurs routeurs IPv6 sont reliés via ethernet** : Utilisation classique, le paquet IPv6 est la charge de la trame de la couche lien. Les adresse de source et de destination sont trouvée dans la charge

<center>
<img src="https://i.imgur.com/R23KbMH.png" width=400/>
</center>

- **Un réseaux IPv4 relie deux routeur IPv6** :  Plutôt que regarder la charge de la trame, le routeur va trouver l'adresse source et destination dans l'en-tête IPv4.
 
 <center>
<img src="https://i.imgur.com/m3tppj1.png" width=400/>
</center>
 
 ## 4.3 Les routeurs
 
 ### Vue haut niveau de l'architecture générique d'un routeur
 
 Le routeur est divisé en deux plan :
 - **Un plan de routage, gestion et contrôle** : Il s'agit d'un plan de niveau logiciel qui opère sur une fenêtre de quelque millisecondes.
 - **Un plan de transfert de données** : Il s'agit d'un plan de niveau matériel qui opère le plus souvent en nanosecondes.

<center>
<img src="https://i.imgur.com/QZ2SPj7.png" width=300/>
</center>

#### Fonctions du port d'entrée 

Au niveau du port d'entrée on différencie : 
- **La couche physique** : réception au niveau bit.
- **La couche lien** : c.f [Chapitre 6](#chap6)
-  **La commutation décentralisée**: Utilise les valeurs de champs d'en-tête IP, recherche recherche le port de sortie via la table de transfert dans la mémoire du port d'entrée. Le but étant de compléter le traitement de paquet en entrée à vitesse de la ligne. Si trop de paquets arrivent par rapport au taux de transfert, alors un système de queue est mis en place.

On parlera de :
- **transfert basé sur la destination** : quand le transfert se base uniquement sur l'adresse IP de destination du paquet.
- **transfert généralisé**: quand le transfet se base sur n'importe quel ensemble de valeur de champs d'en-tête.
<center>
<img src="https://i.imgur.com/xs9J5ij.png" width=300/>
</center>

#### Tissus de commutation (*switching fabrics*)
Il s'agit de la partie chargée du transfert d'un paquet d'un lien d'entrée au lien de sortie approprié.

Le taux de commutation est défini comme le taux auquel peuvent être transmit les paquets de l'entrée à la sortie.

<center>
<img src="https://i.imgur.com/x45XwLF.png" width=300/>
</center>

On différencie trois tissus de commutation différents : 

<center>
<img src="https://i.imgur.com/ZUJDEbp.png" width=400/>
</center>

> Respectivement : Mémoire - Bus de communication - Réseau interconnecté.

- **Commutation par mémoire** :
Il s'agit de la méthode utilisée dans les premières génération de routeurs. 
Il s'agissait d'ordinateurs dont le CPU avait un contrôle directe sur la commutation. Les paquets étaient directement copiés en mémoire et la vitesse de transfert était limité par la bande passante de la mémoire.
- **Commutation par Bus**:
Un bus partagé est mis à disposition de la mémoire des ports d'entrée vers la mémoire des ports de sorties. La vitesse de transfert est donc directement limité par la vitesse du bus. Dans les routeurs de Cisco 5600, les bus ont une vitesse de 32Gbps qui est généralement suffisant pour tout les routeurs d'accès.
- **Commutation par Réseaux interconnecté** : 
Il s'agit d'une mise à l'échelle utilisant plusieurs plan de commutations en parallèle. De manière générale on trouve chez les routeurs Cisco CRS 8 plan de commutation dont chacun dispose de 4 niveau d'interconnexion de réseaux. La vitesse est mesurée en Tbps.

#### Mise en queue du port d'entrée
Si la commutation est plus lente que les port d'entrée combinées,  une mise en queue peut être effectuée.
Le blocage *head of the line* ou *HOL blocking* décrit le fait qu'un paquet en tête de queue peut empêcher d'autre paquets d'avancer.

<center>
<img src="https://i.imgur.com/AqN2tJl.png" width=400/>
</center>

#### Mise en queue du port de sortie
La mise en queue au niveau du port de sortie occurre généralement quand le taux d'arrivée du commutateur excède le taux de sortie du port. Cela peut mener à de l'ajout de délais ainsi que des pertes de paquet dû à un dépassement de mémoire tampon ou *buffer overflow*. S'il il faut, un traitement plus évolué que FIFO peut être appliqué aux paquets et de la fragmentation peut être impliquée.

<center>
<img src="https://i.imgur.com/cS5mTsN.png" width=400/>
</center>

# Chapitre 5 : La couche de Réseaux - Le plan de contrôle

## 5.1 Introduction
Nous avons vu dans le plan de donnée le principe de transfert (*forwarding*) qui déplaçait des paquets de l'entrée d'un routeur à la sortie appropriée du même routeur.

Ici nous aborderons le principe de routage (*routing*) qui a pour but de déterminer la route à prendre pour un paquet d'un hôte source à un hôte de destination.
Cela peux se faire via deux approche ; un contrôle par routeur plus traditionnel ou un contrôle logique centralisé défini généralement au niveau logiciel (on parle alors de *software defined networking* qui ne sera pas abordé dans ce cours)

### Plan de contrôle par routeur
Il s'agit d'un ensemble de composants d'algorithme de routage présents dans chaque routeurs qui interagissent sur le plan de contrôle. 

<center>
<img src="https://i.imgur.com/XBuegfd.png" width=400/>
</center>

## 5.2 Protocole de contrôle de message Internet (ICMP)
Il s'agit d'un protocole utilisé par les hôtes et routeurs pour communiquer des information sur le niveau réseaux. Ces informations peuvent être des reportage d'erreurs (hôte, port, protocole inatteignable, etc.) ou une demande d'écho / réponse (utilisé par `ping`).

Il s'agit d'une couche réseaux "au dessus" d'IP et les messages ICMP sont portés dans les paquets IP. Un message ICMP contient un type , un code et les 8 premiers octets du paquet causant une erreur.

<img src="https://i.imgur.com/mJOBWqz.png" width=250/>

### Traceroute et ICMP
Le principe de la commande traceroute est simple :
- Un hôte source envoi un ensemble de segments UDP à une destination. Le premier ensemble de segment possède un TTL de 1, le second de 2 et ainsi de suite.
- Le paquet du $n$ ème ensemble arrive au $n$ ème routeur. Le routeur rejette le paquet (a cause du TTL) et envois un message ICMP de type 11 et code 0 ('*TTL expired*') incluant possiblement le noms du routeurs et l'adresse IP.
- Quand le message ICMP arrive à l'hôte source, le RTT (*round trip time*) est enregistré pour une destination donnée.

Il existe des critère d'arrêt de la commande traceroute : 
- Un paquet UDP arrive à l'hôte de destination.
- La destination retourne un message ICMP de type 3 et code 3 ('*port unreachable*')
- La source s'arrête.

## 5.3 Protocoles de routage intra domaine

Le but d'un protocole de routage est de déterminer de bons chemins d'un hôte envoyeur à un hôte receveur via un ensemble de routeurs. Un chemin peu être considéré comme bon selon plusieurs critère ; meilleur coût, plus rapide, moins congestionné etc.

### Abstraction de graphe : coûts de lien

Rappel du cours d'algorithmique : Un graphe est un objet mathématique composé par deux éléments ; Un ensemble $N$ de nœuds représentant dans notre cas un ensemble de routeurs. Et un ensemble $E$ de tuple de nœuds représentant une liaisons entre deux nœuds. Dès lors le graphe $G$ est défini par $G=(N,E)$. 
A chaque arrête peut être associé un coût $c_{a,b}$ représentant le coût pour aller d'un sommet $a$ à un sommet $b$. Dans notre cas, le coût d'un lien est défini par l'opérateur réseaux.

#### Réglages possibles des coûts de liaison <a id="pol"></a>

- **Nombre de sauts**  : Tout les liens possède un coût de 1.
- **InvCap** : Le coût d'un lien est inversement proportionnel à sa capacité en bps. Dès lors les meilleurs chemin sont ceux qui sont plus rapide et les liens de haute capacités sont plus sollicités.
- **Delay** : Délais de propagation statique.
- **Coût  de lien administratif** : Chaque coût de lien est calculé pour optimiser un score à un réseaux donné, généralement pour mieux balancer le la charge sur un réseaux via une matrice de trafique.

Basiquement, les coût de liens sont des quantité additionnables de par leurs capacité à être exprimé par une somme de toutes les composantes d'un chemin.

#### Règle d'optimalité
Si un routeur $J$ est sur le chemin d'un routeur $I$ vers un routeur $K$ alors le chemin optimal de $J$ vers $K$ est aussi sur la même route. 
Cette propriété a pour conséquence de rendre l'ensemble des chemins optimaux d'une source à une destination comme arbre enraciné à la source.

<center>
<img src="https://i.imgur.com/LNvKlL2.png" width=400 />
</center>

#### Classification d'algorithme de routage

On différencie les algorithmes de routages :
- **Global**: Tout les routeurs découvrent la topologie complète et toutes les information sur les coût de liaison. Avec ces informations, chaque routeurs calcule sont propre arbre de routage. Algorithme dit "état de liaison" (*link state*)
- **Décentralisé**: Processus itératif de calcul où chaque routeur échange des informations avec ses voisins directs. A l'état initial le routeur ne connaît que les coût le reliant à ses voisins, par la suite les routeurs connaissent leurs distance par rapport à tout les autres routeurs du réseaux. On parle d'algorithme de "vecteur de distance" 

### Routage par état de liaison (*Link stage routing*)
Ce principe de routage est divisé en 3 phases :
1. **Découverte de la topologie du graphe** : "état de liaison diffusé", Tout les nœuds possèdent la même information topologique.
2. **Calcul du chemin de moindre coût** : Chaque nœud calcule le chemin de meilleur coût vers les autres nœuds en utilisant l'algorithme de Dijkstra pour calculer l'arbre couvrant.
3. **Calcul de la table de transfert** : La table de transfert est calculée dans chaque nœuds pour chaque destination possible à l'aide de l'arbre couvrant de Dijkstra.

#### Phase 1 : Construire les paquets d'état de liaison

Les paquets d'état de liaison sont composés :
- D'un nœud source, un numéro de séquence et d'un âge.
-  D'un vecteur de distance limité au voisinage .

<center>
<img src="https://i.imgur.com/TdGGTFj.png" width=500 />
</center>

#### Phase 1 : Distribuer les paquets d'état de liaison
Les paquets sont "inondés" de manière sélective. Les paquets ne sont pas envoyés par le liens sur lequel ils sont arrivé et les duplicatas sont détecté par le numéro de séquence.
Une fois le paquet arrivé, il est ACK.

<center>
<img src="https://i.imgur.com/17V4wx8.png" width=500 />
</center>


#### Phase 1 : Problème potentiels 

- **Enroulement des numéro de séquence**:  Il suffit de prendre un numéro de séquence sur 32bits.
- **Crash du routeur**: Lorsqu'un routeur redémarre, son numéro de séquence est remis à 0. Les paquets sont donc ignorés jusqu'à se que le bon numéro de séquence apparaisse. Pour corriger cela, il suffit de décrémenter par 1 chaque seconde le champs âge et de retirer l'entrée quand cette dernière arrive à l'âge 0.
- **Numéro de séquence corrompu**: Même conséquence que précédemment, même solution.

#### Phase 1 : Complexité de message

Pour $n$ nœuds et $l$ liens chaque routeur doit émettre l'information d'état de lien aux autre $n$ routeurs. Il faut donc un algorithme de diffusion efficace. $O(l)$ croisements de liens pour diffuser un message de diffusion à partir d'une seule source. Chaque routeur effectue la même opération dès lors la complexité finale est de $O(nl)$

#### Phase 2 : Calcul du plus court chemin

A se stade, la topologie et le coût de chaque lien est connu de touts les nœuds.
Chaque routeur doit donc calculer le chemin de lui-même vers tout les autres routeurs. Cela se fait à l'aide de l'algorithme de Dijkstra avec une complexité de $O(n \log (n))$. La complexité sur tout le réseaux est donc en $O(nl \log (n))$


#### Phase 3 : Dérivation de la table de transfert

La table de transfert est déterminée à partir de l'arbre du chemin de plus faible coût.
Les identifiants de routeurs sont les adresses IP. En pratique les nœud avec un sous réseaux possède uniquement le préfixe de l'IP.

<center>
<img src="https://i.imgur.com/eLKSYbZ.png" width=500 />
</center>

#### Routage OSPF (*open shortest path first*)

Dans ce contexte le mot '*open*' fait référence à 'ouvert publiquement'. 

Il s'agit d'un état de liaison classique, chaque routeurs inondes les autres routeurs de *Link-State Advertisements* ou LSA. Le protocole OSPF est directement mis en couche au dessus de IP (pas de TCP/UDP). Chaque routeur possède la topologie totale et calcule la table de transfert via Dijkstra.
La table de transfert lie les préfixe de destination IP vers une interface locale sortantes vers le prochains routeurs.

#### Fonctionnalités "avancée" de OSPF

- **Sécurité**: les LSA peuvent être authentifié pour éviter les intrusions malicieuse.
- **Multi-path** : Les même chemins de moindre coût peuvent être stockés dans la table de transfert pour de l'équilibrage de charge.
- Pour chaque lien, une [politique](#pol) peut être établie.
- **Routeur désigné** : Pour réduire le trafique, quand plusieurs routeurs sont connecté à un même sous réseaux, un seul routeur peut être désigné pour échanger des LSA avec les autres routeurs du sous réseaux.
- **OSPF hiérarchique**: Souvent utilisé dans les grandes topologie.

#### OSPF hiérarchique

Il s'agit d'une hiérarchie à deux niveau :
- La zone locale.
- La structure (*backbone*).

Les LSA sont seulement envoyé dans la structure ou la zone locale et chaque nœud possède la topologie de la zone locale ou de la structure.

<center>
<img src="https://i.imgur.com/RoRtfG4.png" width=500 />
</center>

### Routage par vecteur de distance
Basé sur l'équation de Bellman-Ford (programmation dynamique)

// TODO

#### Protocole RIP (*Routing information protocol*)
Il s'agit d'un protocole inclus dans les distributions BSD-UNIX. 
Il se base sur l'algorithme du vecteur de distance et tourne au dessus de UDP sur le port 520.
Les métriques de distance sont défini comme le nombre de saut (max 15) et chaque lien possède un coût de 1. L'annonce est échangée avec les voisin toutes les 30secondes  et chaque annonce liste au plus 25 sous réseaux de destination.

#### Comparaison entre l'algorithme de *LinkState* (LS) et *Advertisement* (DV)

- **Complexité de message** : 
	- LS :  $n$ routeur, $l$ liens donc $O(nl)$ messages envoyés en phase d'inondation.
	- DV : gros vecteur de taille $n$ échangés entre les voisins, le nombre d'itération de Bellman-Ford varie.
- **Convergence rapide**: 
	- LS : $O(l \log (n))$ calculs par nœuds via algorithme de Dijkstra
	- DV : Le temps de convergences varie
- **Robustesse (malfonction du routeur)** : 
	- LS : Le routeur peut indiquer un mouvais coût de lien car chaque routeur calcule sa propre table.
	- DV : Le routeur peut indiquer un mauvais coût de chemin car chaque table est utilisé par les autres routeurs. L'erreur se propage donc sur le réseaux.


## 5.4 Routage inter domaine

Notre étude du routage à été idéalisée sur un ensemble de routeurs identiques sans hiérarchie se qui n'est pas réaliste. Une mise à l'échelle doit être effectuée pour des milliards de destinations (pas stockable en table de transfert) et doit garantir une autonomie administrative (chaque administrateur réseaux doit pouvoir contrôler son propre réseaux.)

### Approche d'Internet pour le routage évolutif.

Regroupent les routeurs dans des régions appelées "Systèmes autonomes" (AS, aka "domaines").

- **Intra AS , intra domaine**: Routage au sein du même réseaux AS, tout les routeurs dans le AS doivent exécuter le même protocole intra domaine. Des routeurs qui sont sur des réseaux AS différents peuvent exécuter des protocoles de routage intra domaine différent. Le routeur passerelle (*gateway router*) est défini comme le routeur "en bordure" d'un réseaus AS et possède des liens vers des routeurs dans d'autre réseaux AS.
- **Inter AS, inter domaine**:  Routage parmi les réseaux AS. Le routeur passerelle effectue le routage inter domaine.

### Routage intra domaine : routage au sein d'un AS

Les protocoles les plus communs au sein du routage intra AS sont :
- **OSPF** : *'Open Shortest Path First'* .
- **IS-IS** : *'Intermediate System to Intermediate System'*, routage d'état de liaison.
- **RIP** : *'Routing Information Protocol'*, basé sur DV mais plus autant utilisé.
- **EIGRP** : *''Enhance Interior Gateway Routing Protocol*, basé sur DB, et propriétaire à Cisco pour des décennies. Est devenu public en 2013.

### AS interconnectés 

Les tables de transferts sont configurés par les algorithme de routage intra et inter domaine. Le routage intra domaine détermine les entrés pour les destinations au sein du AS tandis que le routage inter domaine (et un peu intra domaine) détermine les entrées pour des destinations externes.

### Routage inter domaine : Un rôle dans le transfert intra domaine

Imaginons qu'un routeur dans un AS 1 reçoivent des paquets destinés à des membres hors de ce réseau AS. Le routeur concerné doit pouvoir envoyé ce paquet au bon routeur passerelle.
Le routage inter domaine de AS 1 doit donc apprendre quelle destination est atteignable via AS2 , AS3 , etc et propager cette information de connectivité à tous les routeurs de AS1.

## 5.5 Routage inter domaine

### Routage inter AS internet : BGP

Le protocole BGP ou *'Boarder Gateway protocol'* est le protocole inter domaine par défaut qui tient internet en un seul morceau.
Ce protocole permet aux sous-réseaux de prévenir de leurs existences ainsi que les destinations atteignable au reste d'internet.

BGP fournis à chaque AS un moyen de:
- Obtenir une information d'accessibilité de sous réseaux à partir des AS avoisinant (eBGP ou *external* BGP).
- Propager les information d'accessibilité a tous les routeur propre à AS (iBGP ou *internal* BGP).
- Déterminer une "bonne" route vers d'autres réseaux basé sur les information d'accessibilité et les polices mise en place.

### Connexion eBGP et iBGP

<center>
<img src="https://i.imgur.com/2yp0E9k.png" width=500 />
</center>

### Les bases de BGP

Une session BGP est ouverte par deux routeurs BGP (alias pairs) qui échanges des message BGP via une connexion TCP semi permanente dans le but d'annoncer les chemins vers différentes destination (préfixe IP). Le protocole BGP est dit protocole de "vecteur de chemin". Cela signifie que que tout le chemin est propagé, pas juste la distance (en opposition à DV).

<center>
<img src="https://i.imgur.com/MH8Wcmd.png" width=500 />
</center>

> Quand le routeur passerelle 3a de AS3 annonce le chemin AS3,X à AS2 via la passerelle 2C, AS3 promet a AS2 d'envoyer les paquet vers le sous réseaux X


### Attributs de chemin et routes BGP
BGP annonce une route via un préfixe et un attribut. Le préfixe est la destination qui est en train d'être annoncé tandis que les attributs sont :
- `AS-PATH`: liste des AS via lesquels l'annonce de préfixe est passé.
- `NEXT-HOP`: indique les passerelle AS interne spécifique au premier AS dans le chemin.

On parle de routage basé sur une police. La passerelle recevant une annonce de route utilise une police d'importation pour accepter ou décliner le chemin. Cette police AS détermine aussi s'il faut annoncer le chemin au As avoisinants.

### Annonce de chemin BGP :

<center>
<img src="https://i.imgur.com/JWZihYe.png" width=500 />
</center>

> - Le routeur 2c de AS2 reçoi une annonce de chemin `AS3,X` (via eBGP) à partir du routeur 3a.
> - Basé sur la police d'importation de AS2, le routeur 2C de AS2 accepte le chemin `AS3,X` et le propage à tous les routeurs de AS2 via iBGP.
> - Basé sur la police d'exportation de AS2. le routeur 2a de AS2 annonce le chemin via eBGP `AS2,AS3,X` vers le routeur 1c de AS1.

<center>
<img src="https://i.imgur.com/IuOzdCe.png" width=500 />
</center>

> - Le routeur passerelle 1c de AS1 apprend le chemin `AS2,AS3,X` de 2a.
> - Le routeur passerelle 1c de AS1 apprends le chemin `AS3,X` de 3a.
> - Basé sur la police, le routeur passerelle de AS1 choisi le chemin `AS3,X` et l'annonce au sein de AS1 via iBGP.

### Message BGP
Les messages BGP sont échangés entre pair au dessus d'une connexion TCP.
On retrouve les message :
- `OPEN` : Ouvre une connexion TCP vers un pair distant BGP et authentifie le pair envoyant des message BGP.
- `UPDATE`: annonce un nouveau chemin ou retire un ancien chemin.
- `KEEPALIVe` : garde une connexion vivante en l'absence de `UPDATE`, et ACK les requête `OPEN`.
- `NOTIFICATION` : Reporte des erreurs dans les message précédents, utilisé pour fermer des connexion.

### Protocole de Vecteur de chemin ; éviter les boucles

Si un réseaux AS se retrouve dans le chemin AS annoncé par un voisin, il va le rejeter pour éviter la création de boucle. Cela fait partie de la police d'importation.

### Sélection de route par BGP
Via BGP, un routeur à la possibilité d'apprendre plus d'une route vers une destination. Le choix de la route revient donc au routeur selon différent critères :
1. **Critère de business**:  Préfère passer par des routes via clients plutôt que pair ou fournisseur.
2. **Chemin AS le plus court**.
3. **Critère de la patate chaude** : routeur passerelle le plus proche
4. **Critère de rupture d'égalité**.

#### Critère de la patate chaude

<center>
<img src="https://i.imgur.com/t1DlA69.png" width=500 />
</center>

> Le routeur 2d apprend via iBGP qu'il peut utiliser une route via 2a ou 2c.
> Choisi le routeur 2a car le cout intra domaine est le plus faible.

### Police d'exportation de BGP via annonce

Les ISP veulent seulement diriger le trafic d'un réseaux client et ne veux pas porter un trafic de transit entre d'autre ISP.

<center>
<img src="https://i.imgur.com/UxLbpPi.png" width=500 />
</center>

> 💡
> -  A,B,C sont des fournisseurs réseaux.
> - w,x,y, sont des clients.
> - x est attaché a deux fournisseurs.
> - police à assurer : x ne veut pas passer de B a C via x. Donc x n'annoncera pas à B la route C.

<center>
<img src="https://i.imgur.com/y0LMvIg.png" width=500 />
</center>

> 💡 
> - A annonce le chemin Aw à B et à C.
> - B choisi de ne pas annoncer BAw à C car B ne percoit aucun revenu pour le routage CBAw puisque C A w ne sont pas des clients de B.
> - C utilisera la route CAw pour arriver à w.

### Polices BGP et Routage '*Valley-Free*'

Les annonces BCP perçues (en bleu) sont seulement transférés via les liens vert pour éviter les trafic de transit couteux.

<center>
<img src="https://i.imgur.com/lcbJxRA.png" width=250 />
<img src="https://i.imgur.com/gUrgMw2.png" width=250 />
<img src="https://i.imgur.com/6PsbsgX.png" width=250 />
</center>

Il est donc facile de voir que le trafic résultant sera '*valley-free*' : 
1. Après être allés vers le bas une fois, les paquets peuvent uniquement continuer vers le bas.
2. Après un plateau, les paquets peuvent uniquement continuer vers le bas
3. Après être allés vers le haut une fois, les paquets peuvent aller en haut, en bas, de travers.

### Processus BCP - Résumé

<center>
<img src="https://i.imgur.com/GwAMVqD.png" width=500 />
</center>

- **Filtres d'entrée (*input filter*)**: évite les cycle dans les chemins AS, évite certains AS dans les chemins AS.
- **Critère de sélection de route (*route selection*)** : Dans un premier temps local et orienté business ensuite plus cours chemin et enfin la patate chaude
- **Filtre d'export (*export filters*)** : Ne veux pas porter le trafic entre 2 AS de fournisseurs, 2 As pairs, ou entre un fournisseur AS et un pair AS.

### Différence entre routage inter et intra domaine 

- **Police** : 
	- inter AS: Les administrateurs veulent contrôler comment le trafique est dirigé lorsqu'il passe par leurs réseaux.
	- intra AS: Un seul administrateur donc la police est moins un problème.
- **Mise à l'échelle**: 
	- La hiérarchisation du routage permet d'économiser en taille de table et de réduire les mise à jours de trafique.
- **Performances**
	- intra AS : Possibilité de se focaliser sur les performances.
	- inter AS: La police domine sur les performances.

# Chapitre 6 : La couche de Lien et LANs <a id=chap6></a>

## 6.1 Introduction à la couche lien

Dans ce chapitre nous utiliserons la terminologie suivante : 
- **Nœuds** : hôte et routeur
- **Liens** : canaux de communication qui connectent des nœuds voisins le long d'un chemin. Ces liens peuvent être :
	- Des liens sans fils.
	- Des liens via câble.
	- Des réseaux d'accès locaux.
- **Frame** : paquet de couche 2 qui encapsule les paquet IP. 

La couche a pour responsabilité de transférer les paquet d'un nœud à un nœud physiquement adjacent via un lien.

### Contexte de la couche lien

Les paquet IP sont transféré par différents protocole de liaison via différent liens (par exemple en Wi-Fi dans un premier temps puis en Ethernet). Chaque protocole de liaison fourni différent services (par exemple le transfert fiable via ce même lien)

### Services de la couche de lien

- **Encadrement ('*framing*'), accès au lien :** Encapsule les paquet IP dans des trames (*frame*) en ajoutant une en-tête et un trailer. Fourni un accès au canal si le support est partagé. L'adresse MAC dans l'en-tête de trame permet d'identifier les nœuds source et destination aux deux extrémités du liens. Cette identification est différente de l'adresse IP qui identifie les interfaces d'hôtes envoyeurs et receveurs.
- **Livraison fiable entre deux nœuds adjacent** : 	c.f. [Chapitre 3](#chap3), ces méthodes sont rarement utilisée sur des liens ayant dit '*low bit-error*' mais est nécessaire dans le cas de liaison sans fils tel que le Wi-Fi.
- **Détection d'erreur**: Des erreurs peuvent subvenir via une atténuation du signal ou du bruit présent sur le canal. Le nœud receveur détecte ladite erreur et décide de demander une retransmission de signal ou abandonne le paquet.
- **Correction d'erreur**: Après identification d'une erreur, le receveur peut décider de corriger les erreurs de bits sans demander de retransmission. Cependant cette méthode est rarement utilisée.
- **Contrôle de flot**: gestion du rythme entre les nœuds d'envoi et de réception adjacents. Rarement utilisé.

### Implémentation de la couche lien

La couche lien est implémentée dans chaque interface de routeur et chaque hôte au sein d'une carte d'interface réseaux ou NIC ('*network interface card*') ou sur une puce. Cette puce ou cette carte réseaux est ensuite reliée a la machine via un bus . La couche lien est donc une combinaison de logiciel, matériel et de micrologiciel.

### Communication de 2 interfaces d'hôte via lien

<center>
<img src="https://i.imgur.com/x6RcV1w.png" width=500 />
</center>

> 💡
> - **Côté envoyeur** : Encapsulation du paquet IP -  Ajouts des bits de détections d'erreurs - Utilisation possible du transfert de donné fiable, du contrôle de flot etc. 
> - **Côté receveur**: Recherche d'erreur - Utilisation possible du transfert de donné fiable, du contrôle de flot etc. - Extraction du paquet IP et passation aux couche supérieures.

## 6.2 LAN : Réseaux d'accès local

Un LAN est un lien multipoint avec des équipements de transmission (par exemple 'fréquence radio' partagée, câble partagé, etc.). Un LAN peut aussi inclue un appareil de niveau lien ( switches ou point d'accès)

- **Câble partagé** : Réseaux d'accès basé sur des câbles, généralement Ethernet.

<center>
<img src="https://i.imgur.com/CxagCEk.png" width=300 />
</center>

- **Fréquence radio partagé** : Wi-Fi, 4G/5G, satellite.

<center>
<img src="https://i.imgur.com/Z2cZruS.png" width=300 />
</center>

Un LAN est donc la structure de la couche lien qui implémente un sous-réseaux IP multipoint. Un envoyeur peut envoyer une trame vers un receveur désigné dans son LAN, vers tout les receveurs (on parle alors de diffusion = '*broadcast*') ou vers un groupe cible de receveur (*multicast*). Un LAN peut être câblé ou non, dans ce cours nous nous focaliserons sur les LAN câblé. 

<center>
<img src="https://i.imgur.com/sK23rfl.png" width=250 />
</center>

### Adresses MAC, adresses de la couche lien

Pour rappel, une adresse IP est une adresse de la couche réseaux qui concerne les interfaces. On l'utilise généralement pour du transfert d'un hôte à un autre sur la couche réseaux. Elle possède la structure suivante (dans le cas de IPv4) : `192.128.40.36`.

L'adresse MAC ('*Medium Access Control*') est utilisé "localement" pour obtenir la trame d'une interface vers une autre interface **physiquement connectée** (même sous-réseaux en terme d'adressage IP). On parle parfois d'adresse LAN, d'adresse physique , d'adresse Wi-Fi / Ethernet pour qualifier l'adresse MAC. Cette adresse est le plus souvent gravée au sein de la ROM de la carte réseaux et est parfois modifiable. Elle suit une structure en Hexadécimal sur 48bit tel que : `1A-2F-BB-76-09-AD`.

Sur un LAN, chaque interface représenté par une carte réseaux possède donc une adresse MAC unique sur 48bit et une adresse IP de 32bit.

Une adresse MAC est dite portable (*flat*), on peut déplacer une interface d'un LAN à un autre sans devoir changer d'adresse MAC, à l'opposé d'une adresse IP, puisque unique.
L'allocation d'adresse MAC est gérée par IEEE, les constructeurs achètent une "portion" d'adresse via un préfixe pour assurer des adresses unique.

### Protocole de résolution d'adresses ARP

Il est nécessaire pour une communication de déterminer l'adresse MAC à partir d'une adresse IP. 
Cela se fait à l'aide du protocole ARP. Chaque nœuds possède une table ARP qui met en relation une adresse IP et une adresse MAC et un TTL (*Time to live*) d'environ 20 minutes. Après ce TTL, le mappage d'adresse est oublié.

#### Exemple 

Un nœud A souhaite envoyer un paquet IP à B. L'adresse MAC de B n'est pas connue de A, donc A fait appel au protocole ARP pour l'identifier : 

1. A envoi en diffusion une requête ARP contenant l'adresse IP de B, tout les nœuds du réseaux local reçoivent cette requête. 
2. B étant concerné par la requête ARP réponds à A en envoyant sa propre adresse MAC. Si B ne possédait pas l'adresse MAC de A, alors il en profite pour mettre à jour sa table.
3. A reçoit la réponse de B, et ajoute l'entrée dans sa table ARP.

<center>
<img src="https://i.imgur.com/HrZHasn.png" width=400 />
</center>

### Routage vers un autre sous réseaux

Reprenons l'exemple ci-dessus, sauf que cet fois ci A et B sont sur deux sous réseaux différents séparés par un routeur R.
1. A créer un paquet IP avec l'IP source de A et l'IP destination de B.
2.  A créer un trame de la couche lien contenant le paquet IP A vers B. ⚠️ L'adresse MAC de destination est l'adresse R.
3.  La trame est envoyée de A à R.
4.  La trame est perçue par R, le paquet IP est décapsulé et passé à IP.
5.  R détermine l'interface sortante, et transmet le paquet IP à la couche lien.
6.  R créer une trame de couche lien contenant le paquet IP de A vers B. Cette fois, l'adresse MAC de B est référencée.
7.  La trame est transmise via la couche lien.
8.  La trame est perçue par B, décapsulée et le paquet IP est envoyé vers les protocoles supérieurs.

## 6.3 Ethernet

### Structure de trame Ethernet
L'interface d'envoi encapsule un paquet IP (ou d'autre paquet des protocoles de la couche réseaux) dans une trame Ethernet :
<center>
<img src="https://i.imgur.com/e0Nq2Hj.png" width=450/>
</center>

- **Préambule** (*'préambule'*) : Utilisé pour synchroniser le taux d'horloge (? *clock rates*) du receveur et de l'envoyeur.  7 octets de `10101010` suivit par un octet de `10101011`.
- **Adresses** (destination + source) : 6 octet pour l'adresse MAC source et 6 bytes pour l'adresse MAC  de destination. Si l'adapteur reçoit une trame avec une adresse de destination correspondante, ou avec une adresse de diffusion (paquet ARP par exemple), il passe cette trame vers un protocole de couche supérieur. Sinon le rejette.
- **Type** : Indique les protocoles supérieurs. Généralement IPv4 ou IPv6 mais d'autres comme ARP sont possible. Utilisé pour démultiplexé au niveau du receveur.
- **CRC** ('*cyclic redundancy check*'): Détection d'erreur, quand une erreur est repérée, la trame est rejetée.

### Topologie physique d'Ethernet

- **Bus**: populaire jusqu'au milieux des années 90, tout les nœuds sont dans le même domaine de collision.
- **Topologie en étoile** : La topologie en bus est remplace par un appareil central. Avant il s'agissait d'un hub, maintenant d'un switch. Plus simple à contrôler.

<center>
<img src="https://i.imgur.com/iaZIID8.png" width=450/>
</center>

### Ethernet : Protocole MAC
Un problème commun est l'interférence (la collision) quand deux ou plusieurs trames sont transmise en simultanées sur un simple canal en diffusion partagée. Pour palier à ce problème Ethernet utilise le protocole MAC.

Le protocole MAC est un algorithme distribué qui détermine comment les nœuds partagent un même canal, et détermine quand un nœud peut transmettre via un canal partagé. 

### Protocole MAC de Ethernet : CSMA/CD

- **CSMA** ('*Carrier Sense Multiple Access*'): Ecoute avant de transmettre : 
	- Si un canal est détecté comme inactif, transmet la trame en entier.
	- SI un canal est détecté comme actif, délaie la transmission de la trame.
- **CSMA/CD** ('*Carrier Sense Multiple Access with Collision Detection*') :
	- Ecoute lors de la transmission.
	- Une collision est détectée sur un cour laps de temps.
	- La transmission faisant collision est avortée, permettant de réduire le gaspillage du canal.
	- La détection de collision est facile à repérer en câblé mais difficile en sans-fils.


### Les Hubs
Il s'agit de répéteur "bête" de la couche physique. Quand un bit arrive au niveau d'un lien vers le hub, le hub le répète sur touts les autres liens avec un même taux de transfert. Il n'y a pas de mise en tampon de trame au niveau du hub.
Tout les nœuds connectés à un hub peuvent faire collision. Cependant le hub ne dispose pas de détection de collision et cette fonctionnalité est reportée sur la carte réseaux.

### Les Switch

Les switch ont un rôle plus actif comparés aux hubs. Un switch possède une carte réseaux par interfaces et chaque interface (segment) exécute un protocole CSMA/CD séparé. Les nœuds ne peuvent donc pas engendrés de collisions entre eux mais peuvent engendrés des collisions avec le switch.
Voir [ici]( #switch)
### Ethernet : Peu fiable, sans connexion
Pour rappel : 
- **Sans connexion**: pas de serrage de main entre l'envoyeur et le receveur (ici les deux sont des cartes réseaux).
- **Peu fiable**: La carte réseaux recevant n'envoi pas de ACK ou NAK vers la carte réseaux envoyant.

Bien que le protocole est peu fiable, quand une collision est détectée, la trame concernée est retransmise après un délais aléatoire.

### Standard Ethernet 802.3 : Couche physique et de lien

Il existe beaucoup de standard Ethernet concernant des vitesse différentes, des support physique différent (connexion via lien cuivré, fibre optique, etc.). Cependant le format de trame et le protocole MAC sont commun à tous.


### Switch Ethernet <a id=switch></a>

Comme énoncé plus haut, un switch est un appareil de la couche lien plus intelligent qu'un hub et qui prends un rôle actif.
Toutes les cartes réseaux d'un switch capture toutes trames Ethernet venant. On parle de mode promiscuité.
Le switch stocke, examine et transfert chaque trame Ethernet en fonction de l'adresse MAC de destination de manière sélective. Une fois la trame transférée, le switch utilise le protocole CSMDA/CD pour détecter une éventuelle collision.

Un switch est dit transparent car les hôtes ne sont pas au courant de sa présence. De plus un switch est dit '*plug and play*' et auto apprenant. Cela signifie qu'il n'a pas besoin de configuration.

#### Switch : Transmission multiple

Mettons deux nœuds A-A' et deux nœuds B-B' communiquent entre eux au travers d'un switch, ces nœuds peuvent communiquer de manière simultanée sans craindre de collisions.

Si la communication se fait entre A-A' et B-A', une trame est retardée au niveau du switch.

Le protocole CSMDA/CD est quand même utilisé sur chaque lien car une collision est possible entre le switch et un nœud. Chaque lien est sont propre domaine de collision. Cependant il existe des lien dit full duplex permettant aucune collision.


#### Switch : Table de transfert

Chaque switch maintient une table de transfert type niveau deux. Une entrée de cette table correspond à une adresse MAC, une interface sortante, et un TTL. Ces entrées sont créés et maintenue par un protocole de routage.

#### Switch : Auto apprentissage

Le switch apprends quel hôte atteindre via quel interface sortante.

#### Switch : Filtrage et transfert de trames

Quand une trame arrive au niveau d'un switch : 
1. Enregistre le lien entrant et l'adresse MAC source (auto apprentissage).
2. Indexation de la table du switch en utilisant l'adresse MAC de destination.
3. Si l'entrée est trouvée dans la table pour la destination donnée, le paquet est transféré. Sinon, le switch provoque une 'inondation' (diffusion sauf au lien entrant) pour déterminer la destination.


### LAN Ethernet : Inconvénients d'une structure physique en arbre

<center>
<img src="https://i.imgur.com/4Fex50e.png" width=450/>
</center>

Touts les principes énoncés jusqu'à maintenant ne faisait pas intervenir de cycle.

### Problème avec les cycles

Soit trois switch en cycle ayant aucune adresse de destination au sein de leurs table de transfert. Lorsqu'une trame est envoyé par un nœud, les switch vont provoqué une inondation volontaire qui bouclera à l'infini.
Une solution à ce problème est de construire un arbre couvrant logique de la topologie.

<center>
<img src="https://i.imgur.com/NIn9JLJ.png" width=350/>
</center>

#### Arbres couvrants
 Lors de la conception d'un arbre couvrant, il y à trois étapes importante : 
 1. **Déterminer le switch racine** (qui a le plus petit identifiant) : Comme les switch inondent tout leurs ports de sortie (BPDU) , les switch découvrent rapidement les identifiants des autres et donc la racine.
 2. **Construction de l'arbre**: En recevant continuellement des BPDU, chaque switch détermine sa distance par rapport a la racine et donc quel port y conduit le plus rapidement. Généralement ces distance sont inversement proportionnelle à la capacité du lien.  
 3. **Décider si les port non racines sont pour le transfert ou le blocage de donnée**: Un port est décidé  pour le transfert lorsque le BPDU envoyé par ce switch est plus petite que le BPDU perçu. Sinon le port est décidé pour le blocage.

### Switch vs Routeur

Les deux possèdent un principe de stockage et de transfert : 
- **Routeur** : appareil de la couche réseaux (analyse les en-tête de la couche réseaux).
- **Switch** : appareil de la couche lien (analyse les en-tête de la couche lien).

Les deux possèdent des tables de transfert :
- **Routeur** : détermine les tables en utilisant des algorithmes et l'adresse IP.
- **Switch** : détermine les tables en utilisant le principe d'inondation, et des adresse MAC.

||Hub|Switch|Routeur|
|:-:|:-:|:-:|:-:|
|**Isolation du trafic**|❌|✅|✅|
|***Plug & play***|✅|✅|❌|
|**Routage optimal**|❌|❌|✅|
|**Couche**| couche 1 : physique|couche 2 : lien| couche 3: réseaux|

## 6.4 Réseaux de centres de données
Il s'agit de réseaux de 10 000 à 100 000 hôtes, souvent couplé de manière rapprochée, à proximité.

Une telle infrastructure implique plusieurs défis allant de la fiabilité à la gestion / balance de charge pour éviter les engorgement au niveau du réseaux.

### Réseaux de centre de données : éléments réseaux

<center>
<img src="https://i.imgur.com/mnFYuHA.png" width=350/>
</center>

- **Routeurs de bordure** : Connexions hors du centre de données.
- **Switch de tier 1** : Connecte environs 16 switch de Tier 2 en dessous.
- **Switch de tier 2**: Connecte environs 16 switch TOR (*top of rack*) en dessous.
- **Switch '*top of rack*'** : Un switch par rack, connecté avec des câble Ethernet de 40 à 100 Gbps aux lames de serveurs
- **Rack de serveurs** : 20 à 40 lames de serveurs ; hôtes.

### Réseaux de centre de données : multi chemin
Une bonne interconnexion parmi les switch et les racks  augmente le débit entre les rack ainsi que la fiabilité via la redondance des chemins.


### Réseaux de centre de données :  Routage au niveau de la couche application
Il existe des balanceur de charges qui reçoivent des requêtes de clients externes, qui effectue une charge de travaille au sein du centre de données et qui retourne le résultat au client externe (en cachant le centre au client).

## 6.5 Détection d'erreurs

Soit D les données protégée par une vérification d'erreurs,  incluant les en-tête de trame.
Soit EDC le champ pour la détection d'erreur (et parfois la correction).

<center>
<img src="https://i.imgur.com/KIJl3rH.png" width=350/>
</center>

La détection d'erreur n'est pas toujours fiable à 100%. Un bon choix de fonction $f$ ainsi qu'un champ plus grand au niveau de EDC conduit à une meilleur détection / correction.

### EDC simple : Vérification de parité
Il s'agit d'une méthode simple. On différencie : 
- **La parité de bit simple** : détecte une seule erreur de bit, un bit de poids fort / faible est mis à 1 lorsqu'on retrouve un nombre pair de 1 dans l'envoi.

<center>
<img src="https://i.imgur.com/8E054eS.png" width=250/>
</center>

- **La parité de bit en double dimension** : détecte et corrige une seul erreur de bit. Principe du bit de parité sur les composantes x et y d'un tableau.

<center>
<img src="https://i.imgur.com/Uyq9zTX.png" width=250/>
</center>

### EDC dans TCP/UDP : checksum
Le but du checksum dans TCP/UDP est de détecter les changements de bits au sein d'un segment transmit.

- **Au niveau de l'envoyeur** : Traite le contenu d'un segment (y compris l'en-tête) comme une séquence de 16bits et effectue une addition du segment. Cette somme est placé dans le champ checksum du paquet.
- **Au niveau du receveur** : La checksum est déterminée et comparée, si elle correspond aucune erreur a été détectée (mais il peut y en avoir) sinon, erreur détectée.

### Contrôle de redondance cyclique :CRC

Il s'agit d'une détection d'erreur un peu plus puissante.
Soit :
- D : les bits de données.
- R : les bits de CRC au nombre de $r$.
- G : les bits de pattern (générateur) au nombre de $r+1$

<center>
<img src="https://i.imgur.com/WgXf2JS.png" width=300/>
</center>

Le but est simple : Choisi $r$ bits parmi le champs CRC telle que  D et R soient exactement divisible par G.
Comme le receveur connais G, il divise les champs D et R par G. Si la division possède un reste, alors une erreur est détectée.
Ce système à la possibilité de détecter des erreurs de longueurs $\le r$ bits et est souvent utilisé.

⚠️ Pour un exemple voir sildes du chapitre 6 slides 64 à 68.

# Synthèse : Un jour dans la vie d'une requête web

Scénario :  Un étudiants utilise sont portable sur le réseaux du campus, et effectue une requête vers `www.google.com`.

1. Le portable se connectant à besoin de recevoir sa propre adresse IP, l'adresse du premier routeur et l'adresse du serveur DNS. Il va donc utiliser le protocole DHCP :
	- La requête DHCP est encapsulée dans UDP, dans IP et enfin dans Ethernet 802.3
	- Une trame Ethernet est diffusée en *broadcast* sur le réseaux local LAN avec comme adresse MAC de destination `FFFFFFFFFFFF`. Cette trame est perçue par un routeur qui exécute le serveur DHCP.
	- La trame est décapsulée vers IP, vers UDP et enfin vers DHCP.
	- Le serveur DHCP formule un ACK DHCP contenant l'adresse IP du client, l'adresse IP du premier routeur, le nom et l'adresse du serveur DNS.
	- L'encapsulation se fait au niveau du serveur DHCP et la trame est transmise via le LAN (apprentissage du switch) et décapsulée au niveau du client. Le client DHCP reçoit une réponse ACK DHCP.
	- ✅ Le client possède maintenant une adresse IP, connait le nom et l'adresse du serveur DNS et connait l'adresse IP du premier routeur
<center>
<img src="https://i.imgur.com/wlxQqM8.png" width=250/>
</center>

2.  Avant de pouvoir envoyer une requête HTTP, le client à besoin de connaitre l'adresse IP de `www.google.com`. Il va donc utiliser le protocole DNS :
	- Une requête DNS est créé, encapsulée dans UDP,  dans IP et enfin dans Ethernet 802.3. Pour envoyer la trame au routeur, le client a besoin d'effectué  une requête ARP afin de connaitre l'adresse MAC de ce dernier : 
		- Une requête ARP est envoyée en *broadcast*, perçue par le routeur qui réponds via ARP en donnant son adresse d'interface routeur.
		- ✅ Le client dispose maintenant de l'adresse MAC du routeur et peut donc envoyer sa trame contenant la requête DNS.

<center>
<img src="https://i.imgur.com/MrTAgxg.png" width=250/>
</center>

2. Suite :
	-  Le paquet IP contenant la requête DNS est transférée via le switch LAN du client vers le premier routeur.
	-  Le paquet IP transféré du réseaux du campus vers le réseaux Comcast, et routé vers le serveur DNS à l'aide des tables générées par les protocole RIP, OSPF, IS-IS et / ou BGP.
	-  Le paquet est décapsulé par le serveur DNS jusqu'à la requête DNS.
	-  Le serveur DNS réponds à la requête DNS avec l'adresse IP de `www.google.com`.
	- ✅ Le client dispose de l'adresse IP de `www.google.com`
	
<center>
<img src="https://i.imgur.com/y8Mwc1e.png" width=350/>
</center>

3.  Pour commencer à envoyer des requête HTTP, le client doit ouvrir un socket TCP vers le serveur web :
	-   Un segment SYN TCP (premier étape de la poignée de main à 3 étapes) est routée en inter domaine vers le serveurs web.
	-   Le serveur web réponds avec un TCP SYNACK (étape 2).
	-   ✅ La connexion TCP est établie.

<center>
<img src="https://i.imgur.com/ecza1Xw.png" width=300/>
</center>

4. Le client peut enfin envoyer des requête HTTP vers le serveur via le socket TCP : 
	- Le paquet IP contenant la requête HTPP est encapsulée puis dirigée vers `www.google.com`, décapsulée.
	- Le serveur web réponds avec un HTTP *reply* contenant une page web.
	- Le paquet IP contenant la réponse HTTP est redirigée vers le client.
	- ⭐️ Une page web s'affiche. (ENFIN !)

<center>
<img src="https://i.imgur.com/px3J7gj.png" width=300/>
</center>