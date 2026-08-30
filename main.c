#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void install(const char *paquet) {
    printf("Récupération de %s...\n", paquet);

    char command[512];

    // Téléchargement (-f échoue si 404), exécution puis suppression
    snprintf(command, sizeof(command), 
             "curl -fsSL https://raw.githubusercontent.com/Ianou68/Recipe-package-manager/main/recipe/%s.sh -o /tmp/%s.sh && bash /tmp/%s.sh && rm /tmp/%s.sh", 
             paquet, paquet, paquet, paquet);

    int status = system(command);

    if (status != 0) {
        printf("Erreur : l'installation du paquet '%s' a échoué.\n", paquet);
        snprintf(command, sizeof(command), "rm -f /tmp/%s.sh", paquet);
        system(command);
        return;
    }

    printf("Installation de %s terminée avec succès.\n", paquet);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s install <paquet>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "install") == 0) {
        install(argv[2]);
    } else {
        printf("Commande inconnue : %s\n", argv[1]);
        printf("Usage: %s install <paquet>\n", argv[0]);
        return 1;
    }

    return 0;
}
