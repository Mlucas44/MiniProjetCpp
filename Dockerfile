# Utilise une image de base Ubuntu 20.04
FROM ubuntu:20.04

# Mettre à jour les packages
RUN apt-get update && apt-get -y upgrade

# Installer les outils de développement C++ et les dépendances nécessaires
RUN apt-get -y install build-essential cmake libboost-all-dev

# Copier le code source du projet dans le conteneur Docker
COPY . /app

# Définir le dossier de travail
WORKDIR /app

# Compiler l'application
RUN cmake . && make

# Exposer le port 8080 (si nécessaire)
EXPOSE 8080

# Définir la commande par défaut pour lancer l'application
CMD ["./puissance4"]