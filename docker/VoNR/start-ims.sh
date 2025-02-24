#!/bin/bash
# Définir la variable d’environnement pour MongoDB
export MONGO_IP=10.53.3.2  # IP de MongoDB depuis docker-compose.yml et vonr.env

# Démarrer Kamailio (IMS : I-CSCF, P-CSCF, S-CSCF)
kamailio -f /etc/kamailio/kamailio.cfg &

# Démarrer PyHSS (HSS)
cd /pyhss && python3 pyhss.py &

# Démarrer DNS (bind)
named -c /etc/bind/named.conf &

# Démarrer le webgui (via webgui.init.sh)
cd /var/www/webgui && ./webgui.init.sh &

# Garder le conteneur actif
wait