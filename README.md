# FT_PRINTF

Ce projet est clair et efficace. Vous devez recoder printf. Vous aurez dès lors la possibilité de le réutiliser dans vos futurs projets. Ce projet porte principalement sur les arguments à taille variable.

_______________________________________________________________________________

# Méthodologie utilisée :

# Parsing :
Création d'une structure qui stockera les flags parcourus après un '%'.
La variable "i" et "compteur" agissent comme des variables globales. Contrairement aux autres éléments de la structure, ces deux variables sont initialisées qu'une fois.
i est l'indice dans la lecture de la chaîne de caractère de printf.
compteur est la valeur de retour de printf.
Après un '%', on va donc chercher si les flags '-', '0', '.' sont présents et passer leur valeur à 1 si c'est le cas.

# Fonction print :
Utilisation de la fonction itoa_base pour les types 'd', 'i', 'u', 'x', 'X', 'p'.
Les fonctions vont toutes avoir les 3 comportement différent :
    - le flag '-' est activé
    - le flag '0' est activé
    - aucun flag n'est activé

[... à compléter ...]
