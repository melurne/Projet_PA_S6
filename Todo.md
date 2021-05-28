- Parsing csv files to usable data structures
  - parsed <>
  - put unto structs <>

- request file ?

+ .clang-format file ? <>

+ resolve duplications <>

+ organizing branches <>

- find spelling errors

-functions :
show-airports <airline_id>  : affiche tous les aéroports depuis lesquels la compagnie aérienne <airline_id> opère des vols


show-airlines <port_id>: affiche les compagnies aériens qui ont des vols qui partent de l'aéroport <port_id>


show-flights <port_id> <date> [<time>] [limit=<xx>] : affiche les vols qui partent de l'aéroport à la date, avec optionnellement une heure de début, et limité à xx vols


most-delayed-flights     : donne les 5 vols qui ont subis les plus longs retards à l'arrivée


most-delayed-airlines    : donne les 5 compagnies aériennes qui ont, en moyenne, le plus de retards


delayed-airline <airline_id>    : donne le retard moyen de la compagnie aérienne passée en paramètre


most-delayed-airlines-at-airport <airport_id>    : donne les 3 compagnies aériennes avec le plus de retard d'arrivé à l'aéroport passée en paramètre


changed-flights <date> : les vols annulés ou déviés à la date  (format M-D)


avg-flight-duration <port_id> <port_id>: calcule le temps de vol moyen entre deux aéroports


find-itinerary <port_id> <port_id> <date> [<time>] [limit=<xx>]: trouve un ou plusieurs itinéraires entre deux aéroports à une date donnée (l'heure est optionnel, requête peut être limité à xx propositions, il peut y avoir des escales)


find-multicity-itinerary <port_id_depart> <port_id_dest1> <date> [<time>] <port_id_dest2> <date> [<time>] ... <port_id_destN> <date> [<time>]: trouve un itinéraire multiville qui permet de visiter plusieurs villes (il peut y avoir des escales pour chaque vol intermediaire)


quit       : quit

