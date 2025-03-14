#!/bin/bash

# Parcours tous les fichiers qui commencent par "medium_"
for fichier in school_*; do
    # Vérifie que c'est bien un fichier (et pas un dossier vide ou autre)
    if [ -f "$fichier" ]; then
        # Remplace "medium_" par "m_" et renomme le fichier
        mv "$fichier" "${fichier/school_/s_}"
    fi
done

echo "Renommage terminé !"
