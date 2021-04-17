import classes

def readFlights() :
    with open('../data/flights.csv', 'r') as f:
        lines = f.readlines()
        header = lines[0]
        raw = lines[1:]
    data = []
    #header = header.split(',')
    for line in raw :
        month, day, weekday, airline, org_air, dest_air, sched_dep,dep_delay, air_time, dist, sched_arr, arr_delay, diverted, canceled = line.split(',')
        data.append({   'month': int(month),
                        'day': int(day),
                        'weekday': int(weekday),
                        'airline': airline,
                        'org_air': org_air,
                        'dest_air': dest_air,
                        'sched_dep': int(sched_dep),
                        'dep_delay': float(dep_delay) if dep_delay != '' else 0.,
                        'air_time': float(air_time) if air_time != '' else 0.,
                        'dist': int(dist),
                        'sched_arr': int(sched_arr),
                        'arr_delay': float(arr_delay) if arr_delay != '' else 0.,
                        'diverted': int(diverted),
                        'canceled': int(canceled)
                    })
    return data

def readAirlines() :
    with open('../data/airlines.csv') as f :
        lines = f.readlines()
        header = lines[0]
        raw = lines[1:]
    data = []

    for line in raw :
        IATA_code, airline = line.split(',')
        data.append({   'IATA_code' : IATA_code,
                        'name': airline
                    })
    return data

def readAirports() :
    with open('../data/airports.csv') as f :
        lines = f.readlines()
        header = lines[0]
        raw = lines[1:]
    data = []

    for line in raw :
        IATA_code, airport, city, state, country, latitude, longitude = line.split(',')
        data.append({   'IATA_code': IATA_code,
                        'name': airport,
                        'city': city,
                        'state': state,
                        'country': country,
                        'latitude': float(latitude) if latitude != '' else 0.,
                        'longitude': float(longitude) if latitude != '' else 0.
                    })
    return data

Flights = readFlights()
Airlines = readAirlines()
Airports = readAirports()

def show_airports(airline_id) :
    """
    lists all airports where the company <airline_id> operates flights
    airline_id = airline.IATA_code
    Under the assumption that an airline operating in an airport means a flight from this company flew either from or to said airport
    i.e the result from this SQL query :

    SELECT * FROM airports
    WHERE airports.IATA_code IN (   SELECT flights.org_air FROM flights
                                    WHERE flights.airline == <airline_id>)
    OR airports.IATA_code IN (      SELECT flights.dest_air FROM flights
                                    WHERE flights.airline == <airline_id>)
    """
    out_airports_id = []
    for flight in Flights :
        if flight['airline'] == airline_id :
            if not flight['org_air'] in out_airports_id :
                out_airports_id.append(flight['org_air'])
            if not flight['dest_air'] in out_airports_id :
                out_airports_id.append(flight['dest_air'])
    out_airports_id.sort()
    out_airports = []
    for airport in Airports :
        if airport['IATA_code'] in out_airports_id :
            out_airports.append("{0[IATA_code]},{0[name]},{0[city]},{0[state]}".format(airport))
    return out_airports

def show_airlines() :
    pass


print(show_airports('HA'))
