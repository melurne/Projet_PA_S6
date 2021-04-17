def readFlights() :
    with open('../data/flights.csv', 'r') as f:
        lines = f.readlines()
        header = lines[0]
        raw = lines[1:]
    data = []
    #header = header.split(',')
    for line in raw :
        month, day, weekday, airline, org_air, dest_air, sched_dep,dep_delay, air_time, dist, sched_arr, arr_delay, diverted, canceled = line.rstrip('\n').split(',')
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
        IATA_code, airline = line.rstrip('\n').split(',')
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
        IATA_code, airport, city, state, country, latitude, longitude = line.rstrip('\n').split(',')
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

def formatDictToStr(dict) :
    out_str = ""
    for key in dict.keys() :
        out_str = out_str + "{0[key]},".format(dict)
    return out_str.rstrip(',')

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
    out_airports = []
    for airport in Airports :
        if airport['IATA_code'] in out_airports_id :
            out_airports.append(formatDictToStr(airline))
    out_airports.sort()
    return out_airports

def show_airlines(port_id) :
    """
    list all airlines which operate flights from <port_id>
    port_id = airport.IATA_code
    i.e the result from this SQL query :

    SELECT * FROM airlines
    WHERE airlines.IATA_code IN (   SELECT flights.airline FROM flights
                                    WHERE flights.org_air == <port_id>)
    """
    out_airlines_id = []
    for flight in Flights :
        if (flight['org_air'] == port_id or flight['dest_air'] == port_id) and not flight['airline'] in out_airlines_id:
            out_airlines_id.append(flight['airline'])
    out_airlines = []
    for airline in Airlines :
        if airline['IATA_code'] in out_airlines_id :
            out_airlines.append(formatDictToStr(airline))
    out_airlines.sort()
    return out_airlines

def show_flights(   port_id,        #Airport['IATA_code']
                    date,           #month-day
                    time = None,    #optional sched_dep
                    limit=None      #int limit number of flights to display
                    ) :
    """
    lists flights from <port_id> on the date <date> with an optional sched_dep <time> and a <limit> for the max number of flights to display
    i.e the result of this SQL query :

    SELECT * FROM Flights
    WHERE Flights.org_air == <port_id>
    AND Flights.month == <date>[0] AND Flights.day == <date>[1]
    /*AND Flights.sched_dep == <time>*/

    only displaying the first <limit> results
    """
    pass
