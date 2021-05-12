- Parsing csv files to usable data structures
  - parsed <>
  - put unto structs

- request file ?

+ .clang-format file ? <>

+ resolve duplications <>

+ organizing branches <>

- find spelling errors

-functions :
	show-airports <airline_id>  : liste tous les aéroports depuis lesquels la compagnie aérienne <airline_id> opère des vols

	show-airlines <port_id>: liste l'ensemble des compagnie aériennes depuis l'aéroport passé en paramètre

	show-flights <port_id> <date> [<time>] [limit=xx] : lister les vols qui partent de l'aéroport à la date, avec optionnellement une heure de début, et limité à xx vols

	most-delayed-flights     : donne les 5 vols qui ont subis les plus longs retards à l'arrivée

	most-delayed-airlines    : donne les 5 compagnies aériennes qui ont, en moyenne, le plus de retards

	airlines <port_id> : recherche compagnies aériens qui ont des vols qui partent de l'aéroport IATA_AIRPORT


	changed-flights <date> : les vols annulés ou déviés à la date  (format M-D)

	avg-flight-duration <port_id> <port_id>: calcule le temps de vol moyen entre deux aéroports

	find-itinerary <port_id> <port_id> <date>: trouve un itinéraire entre deux aéroports à une date donnée (il peut y avoir des escales)

	quit       : quit

