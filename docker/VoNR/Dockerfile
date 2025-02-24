# Image de base : Ubuntu 22.04 (compatible avec Open5GS, srsRAN, et Node.js)
FROM ubuntu:22.04

# Installation des dépendances de base
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    kamailio \
    kamailio-ims-modules \
    bind9 \
    git \
    nodejs \
    npm \
    && rm -rf /var/lib/apt/lists/*

# Installation de PyHSS
RUN git clone https://github.com/nickvsnetworking/pyhss /pyhss \
    && cd /pyhss \
    && pip3 install -r requirements.txt

# Préparation et installation des dépendances du webgui
COPY webgui/ /var/www/webgui/
RUN cd /var/www/webgui && npm install

# Copie des fichiers de configuration (ajuste les chemins selon ta structure)
COPY dns/ /etc/bind/
COPY iscscf/ /etc/kamailio/iscscf/
COPY ims_base/ /etc/ims_base/
COPY pcscf/ /etc/kamailio/pcscf/
COPY pyhss/ /pyhss/
COPY scscf/ /etc/kamailio/scscf/

# Configurations spécifiques (dans un dossier configs/)
COPY configs/kamailio.cfg /etc/kamailio/kamailio.cfg
COPY configs/named.conf /etc/bind/named.conf
COPY configs/pyhss.yml /pyhss/config.yaml

# Script de démarrage
COPY start-ims.sh /start-ims.sh
RUN chmod +x /start-ims.sh

# Exposition des ports (SIP, SIP TLS, Diameter, DNS, webgui)
EXPOSE 5060/udp 5061/tcp 3868/tcp 53/udp 53/tcp 8080/tcp  # Port 8080 pour webgui

# Commande par défaut
CMD ["/start-ims.sh"]