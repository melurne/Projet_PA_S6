Flights structs will be stored in a research tree (not yet implemented)

Airlines and Airports will be saved in a hashtable in order to get a fast access using the already in place IATA_code identification key. In order to make the code simpler, we would like to get a "perfect" hash function, which means it would be a bijectiv function of 
[IATA_code] -> N, this way we wouldn't have to worry about collisions. Note this is possible only because of the fact that our Airlines and Airports tables are static, because of this we will be able to generate a perfect hashing function and verify that it is in fact perfect. Idealy such a function would map [IATA_code] to an subset of N of a length as close to the lenght of [IATA_code] as possible to keep memory usage to a minimum for our hashtable.
In order to generate our perfect hash functions, we will be using a python package called perfect-hash which is freely available on github (https://github.com/ilanschnell/perfect-hash) which takes a template file for our function (C exemples are given in the repository) and the list of keys we want to map (we can use our .csv files directly so long as we remove the header line) we have used this package to generate the hashing files in the hashFunc/ folder. We will be using those functions via a library file in our makefile.  