class date :
    def __init__(   self,
                    month,      #int
                    day,        #int
                    weekday     #int
                    ) :
        self.month = month
        self.day = day
        self.weekday = weekday

    def pretify(self) :
        return "{0.month},{0.day},{0.weekday}".format(self)

class airline :
    def __init__(   self,
                    IATA_code,  #char[2]
                    name        #str
                    ) :
        self.IATA_code = IATA_code
        self.name = name

    def pretify(self) :
        return "{0.IATA_code},{0.name}".format(self)

class airports :
    def __init__(   self,
                    IATA_code,  #char[3]
                    name,       #str
                    city,       #str
                    state,      #char[2]
                    country,    #str
                    latitude,   #float
                    longitude   #float
                    ) :
        self.IATA_code = IATA_code
        self.name = name
        self.city = city
        self.state = state
        self.country = country
        self.latitude = latitude
        self.longitude = longitude
    def pretify(self) :
        return "{0.IATA_code},{0.name},{0.city},{0.state}".format(self)

class flight :
    def __init__(   self,
                    date,       #<class date>
                    airline,    #<class airline>.IATA_code
                    org_air,    #<class airport>.IATA_code
                    dest_air,   #<class airport>.IATA_code
                    sched_dep,  #int (1625 = 16h25)
                    dep_delay,  #float (in minutes)
                    air_time,   #float (in minutes)
                    dist,       #int (in miles)
                    sched_arr,  #int (1625=16h25)
                    arr_delay,  #float (in minutes)
                    diverted,   #bool
                    canceled    #bool
                    ) :
        self.date = date

        self.airline = airline
        self.org_air = org_air
        self.dest_air = dest_air

        self.sched_dep = sched_dep
        self.dep_delay = dep_delay

        self.air_time = air_time
        self.dist = dist

        self.sched_arr = sched_arr
        self.arr_delay = arr_delay

        self.diverted = diverted
        self.canceled = canceled

    def pretify(self) :
        return self.date.pretify() + ",{0.airline},{0.org_air},{0.dest_air},{0.sched_dep},{0.dep_delay},{0.air_time},{0.dist},{0.sched_arr},{0.arr_delay},{1},{2}".format(self, 1 if self.diverted else 0, 1 if self.canceled else 0)
