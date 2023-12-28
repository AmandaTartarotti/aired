
#include "../header/Menu.h"
#include <unordered_set>
#include <iostream>
#include <set>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cmath>

struct airportComparator {
    bool operator()(const Airport* firstAirport, const Airport* secondAirport) const {
        return *firstAirport < *secondAirport;
    }
};


void printMainMenu() {
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Statistics" << endl;
    cout << "2 - Find the best flight option" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
}
void printStatisticsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Global statistics" << endl;                                                                        //Check
    cout << "2 - Total number of flights per airport/city/airline" << endl;
    cout << "3 - Check destinations available for a given airport/city" << endl;
    cout << "4 - Statistics with layovers" << endl;
    cout << "5 - Check the airports with the most traffic" << endl;                                                 //Check
    cout << "6 - Consult the essential airports" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option){
        case '1':
            printGlobalStatistics(flightManagement);
            break;
        case '2':
            printNumberFlightsMenu(flightManagement);
            break;
        case '3':
            printDestinationOptionMenu(flightManagement);
            break;
        case '4':
            printLayoverMenu(flightManagement);
            break;
        case '5':
            printAirportsGreatestCapability(flightManagement);
            break;
        case '6':
            printEssentialAirports(flightManagement);
            break;
        case '0':
            return;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }

}
void printNumberFlightsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Total flights of an airport" << endl;
    cout << "2 - Total flights of a city" << endl;
    cout << "3 - Total flights of an airline" << endl;
    cout << "0 - Return to the main menu" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option){
        case '1':
            printNumFlights_outAirport(flightManagement);
            break;
        case '2':
            printNumFlights_perCity(flightManagement);
            break;
        case '3':
            printNumFlights_perAirline(flightManagement);
            break;
        case '0':
            cout << "--------------------------------------------------\n";
            cout << "Returning to the main menu." << endl;
            return;
        default:
            cout << "--------------------------------------------------\n";
            cout << "Invalid option. Please, try again." << endl;
            break;
        }
}
void printDestinationOptionMenu(const FlightManagement& flightManagement) {

    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Search by airport" << endl;
    cout << "2 - Search by city" << endl;
    cout << "0 - Return to the main menu" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    char option1 = '0';
    cin >> option1;

    switch (option1) {
        case '1':
            printNumByAirport(flightManagement);
            break;
        case '2':
            printNumByCity(flightManagement);
            break;
        case '0':
            cout << "--------------------------------------------------\n";
            cout << "Returning to the main menu." << endl;
            return;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}
void printLayoverMenu(const FlightManagement& flightManagement) {
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Consult reachable destinations with 'n' layovers" << endl;
    cout << "2 - Check the trips with the greatest number of layovers" << endl;
    cout << "0 - Return to the main menu" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option){
        case '1':
            printStatisticWithStops(flightManagement);
            break;
        case '2':
            printMaximumTrip(flightManagement);
            break;
        case '0':
            cout << "--------------------------------------------------\n";
            cout << "Returning to the main menu." << endl;
            return;
        default:
            cout << "--------------------------------------------------\n";
            cout << "Invalid option. Please, try again." << endl;
            break;
    }
}


void printBestFlight(const FlightManagement& flightManagement) {
    char option = '0';
    unordered_set<string> sourceLocation;
    unordered_set<string> destLocation;

    cout << "--------------------------------------------------\n";
    cout << "Choose your source location:" << endl;
    cout << "1 - Airport" << endl;
    cout << "2 - City" << endl;
    cout << "3 - Coordinates with range" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    cin >> option;
    switch (option){
        case '1':
            sourceLocation = findAirport(flightManagement);
            break;
        case '2':
            sourceLocation = findAirportInCity(flightManagement);
            break;
        case '3':
            sourceLocation = findAirportHaversine(flightManagement);
            if (sourceLocation.empty()) {
                cout << "--------------------------------------------------\n";
                cout << "There's no airport inside the range you asked! Please, try again." << endl;
                return;
            }
            break;
        case '0':
            cout << "Returning to the main menu." << endl;
            return;
        default:
            cout << "Invalid option. Exiting." << endl;
            return;
    }
    if (sourceLocation.empty()) {
        cout << "Location not found! Please, try again." << endl;
        return;
    }

    cout << "--------------------------------------------------\n";
    cout << "Choose your destination location:" << endl;
    cout << "1 - Airport" << endl;
    cout << "2 - City" << endl;
    cout << "3 - Coordinates with range" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    cin >> option;
    switch (option){
        case '1':
            destLocation = findAirport(flightManagement);
            break;
        case '2':
            destLocation = findAirportInCity(flightManagement);
            break;
        case '3':
            destLocation = findAirportHaversine(flightManagement);
            if (destLocation.empty()) {
                cout << "--------------------------------------------------\n";
                cout << "There's no airport inside the range you asked! Please, try again." << endl;
                return;
            }
            break;
        case '0':
            cout << "Returning to the main menu." << endl;
            return;
        default:
            cout << "Invalid option. Exiting." << endl;
            return;
    }
    if (destLocation.empty()) {
        cout << "Location not found! Please, try again." << endl;
        return;
    }

    bool flag = true;
    bool least = false;
    unordered_set<string> excludedLocation;
    unordered_set<string> excludedAirline;
    vector<list<string>> res;

    while (flag) {
        cout << "--------------------------------------------------\n";
        cout << "Do you have any restriction?" << endl;
        cout << "1 - Exclude countries" << endl;
        cout << "2 - Exclude cities" << endl;
        cout << "3 - Exclude airports" << endl;
        cout << "4 - Exclude airlines" << endl;
        cout << boolalpha;
        cout << "5 - Use the least amount of airlines -> " << least << endl;
        cout << endl;
        cout << "6 - Continue" << endl;
        cout << "0 - Exit" << endl;
        cout << "--------------------------------------------------\n";
        cout << "Option:";
        cin >> option;
        switch(option) {
            case '1':
                includeConstraint(flightManagement, excludedLocation, 1);
                break;
            case '2':
                includeConstraint(flightManagement, excludedLocation, 2);
                break;
            case '3':
                includeConstraint(flightManagement, excludedLocation, 3);
                break;
            case '4':
                includeConstraint(flightManagement, excludedAirline, 4);
                break;
            case '5':
                if (least) {
                    least = false;
                } else {
                    least = true;
                }
                break;
            case '6':
                res = findFlight(flightManagement, sourceLocation, destLocation, excludedLocation, excludedAirline);
                flag = false;
                break;
            default:
                cout << "--------------------------------------------------\n";
                cout << "Invalid option! Please, try again." << endl;
                return;
            case '0':
                cout << "--------------------------------------------------\n";
                cout << "Returning to main menu." << endl;
                return;
        }
    }
    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    Graph<string> graph = flightManagement.getGraph();

    cout << "--------------------------------------------------\n\n";
    if (res.empty()) {
        cout << "It was not possible to find a trip meeting those criteria! Please, try again." << endl << endl;
    }
    for (const list<string>& path : res) {

        auto it = path.begin();
        Airport* airport = allAirports[*it];

        for (int i = 0; i < path.size() - 1; i++) {

            Vertex<string>* vertex = graph.findVertex(*it);
            vector<Edge<string>> airlines = vertex->getAdj();
            cout << airport->getCode() << ", " << capitalizeWords(airport->getCity()) << ", " << capitalizeWords(airport->getCountry()) << " ";
            advance(it, 1);
            airport = allAirports[*it];
            cout << airport->getCode() << " " << capitalizeWords(airport->getCity()) << " " << capitalizeWords(airport->getCountry()) << " : ";

            for (const auto & airline : airlines) {
                if (airline.getDest()->getInfo() == airport->getCode() and excludedAirline.find(airline.getAirline()) == excludedAirline.end()) {
                    cout << airline.getAirline() << " ";
                }
            }

            cout << endl;
        }
        cout << endl;
    }
}

void includeConstraint(const FlightManagement& flightManagement, unordered_set<string>& exclude, int mode) {
    string constraint;
    unordered_map<string, Airport*> airportMap = flightManagement.getAirportMap();
    unordered_map<string, Airline*> airlineMap = flightManagement.getAirlineMap();

    cout << "--------------------------------------------------\n";
    if (mode != 4) {
        cout << "Enter the name of the location you want to exclude (type 'end' when finished):" << endl;
    } else {
        cout << "Enter the name of the airline you want to exclude (type 'end' when finished):" << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        getline(cin, constraint);
        cout << endl;

        bool valid = false;
        if (constraint == "end") {
            break;
        }

        if (mode == 1) {
            constraint = upperCase(constraint);
            for (auto & it : airportMap) {
                if (it.second->getCountry() == constraint) {
                    exclude.insert(it.first);
                    valid = true;
                }
            }
        } else if (mode == 2) {
            constraint = upperCase(constraint);
            for (auto & it : airportMap) {
                if (it.second->getCity() == constraint) {
                    exclude.insert(it.first);
                    valid = true;
                }
            }
        } else if (mode == 3) {
            constraint = upperCase(constraint);
            auto it = airportMap.find(constraint);
            if (it != airportMap.end()) {
                exclude.insert(constraint);
                valid = true;
            }
        } else {
            constraint = upperCase(constraint);
            auto it = airlineMap.find(constraint);
            if (it != airlineMap.end()) {
                exclude.insert(constraint);
                valid = true;
            }
        }

        if (!valid) {
            cout << "--------------------------------------------------\n";
            cout << "Invalid location. The location provided was not processed." << endl;
            cout << "--------------------------------------------------\n";
        }
    }
}

list<string> shortestPath(const Graph<string>& graph, const string& source, const string& dest, const unordered_set<string>& excludeAirline, const unordered_set<string>& excludeLocation) {
    list<string> path;
    for (Vertex<string>* vertex : graph.getVertexSet()) {
        if (excludeLocation.find(vertex->getInfo()) != excludeLocation.end()) {
            vertex->setVisited(true);
        } else {
            vertex->setVisited(false);
        }
    }

    Vertex<string>* sourceVertex = graph.findVertex(source);
    Vertex<string>* destVertex = graph.findVertex(dest);

    if (sourceVertex->isVisited() or destVertex->isVisited()) {
        return path;
    }

    queue<string> q;
    q.push(source);
    sourceVertex->setVisited(true);
    sourceVertex->setDistance(0);

    while (!q.empty()) {
        Vertex<string>* tempVertex = graph.findVertex(q.front());
        q.pop();
        for (const Edge<string>& edge : tempVertex->getAdj()) {
            if (excludeAirline.find(edge.getAirline()) != excludeAirline.end()) {
                continue;
            }
            Vertex<string>* neighbour = edge.getDest();
            if (!neighbour->isVisited()) {
                neighbour->setVisited(true);
                q.push(neighbour->getInfo());
                neighbour->setDistance(tempVertex->getDistance() + 1);
                neighbour->setLastVisit(tempVertex->getInfo());
            }
        }
    }

    if (!destVertex->isVisited()) {
        return path;
    }

    while (destVertex != sourceVertex) {
        path.push_front(destVertex->getInfo());
        destVertex = graph.findVertex(destVertex->getLastVisit());
    }
    path.push_front(source);
    return path;
}

vector<list<string>> findFlight(const FlightManagement& flightManagement, const unordered_set<string>& sourceLocation, const unordered_set<string>& destLocation, const unordered_set<string>& excludeLocation, const unordered_set<string>& excludeAirline) {
    Graph<string> graph = flightManagement.getGraph();
    int minDis = INT_MAX;
    for (const string& source : sourceLocation) {
        Vertex<string> *s = graph.findVertex(source);
        for (Vertex<string>* vertex : graph.getVertexSet()) {
            if (excludeLocation.find(vertex->getInfo()) != excludeLocation.end()) {
                vertex->setVisited(true);
            } else {
                vertex->setVisited(false);
            }
        }

        if (!s->isVisited()) {
            queue<Vertex<string> *> unvisited;
            s->setDistance(0);
            unvisited.push(s);
            s->setVisited(true);
            while (!unvisited.empty()) {
                Vertex<string> *v = unvisited.front();
                unvisited.pop();
                for (const Edge<string> &neighbor: v->getAdj()) {
                    Vertex<string> *w = neighbor.getDest();

                    if (excludeLocation.find(w->getInfo()) != excludeLocation.end() or excludeAirline.find(neighbor.getAirline()) != excludeAirline.end()) {
                        continue;
                    }

                    if (!w->isVisited()) {
                        w->setDistance(v->getDistance() + 1);
                        unvisited.push(w);
                        w->setVisited(true);
                    }
                }

                if (destLocation.find(v->getInfo()) != destLocation.end()) {
                    minDis = min(v->getDistance(), minDis);
                }
            }
        }
    }

    vector<list<string>> res;
    for (const string& source : sourceLocation) {
        for (const string& dest : destLocation) {
            list<string> path = shortestPath(graph, source, dest, excludeAirline, excludeLocation);
            if (path.size() - 1 == minDis) {
                res.push_back(path);
            }
        }
    }
    return res;
}


void printGlobalStatistics(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    int numAirports = graph.getNumVertex();
    int numAirlines = flightManagement.getAirlineMap().size();

    vector<Vertex<string>*> nodes = graph.getVertexSet();
    int numFlights = 0;

    unordered_map<string, Airport*> airportMap = flightManagement.getAirportMap();
    unordered_set<string> countriesSet;
    unordered_set<string> citiesSet;

    for (Vertex<string> *node: nodes) {
        numFlights += node->getAdj().size();
        Airport* airport = airportMap[node->getInfo()];
        countriesSet.insert(airport->getCountry());
        citiesSet.insert(airport->getCity());
    }


    cout << "--------------------------------------------------\n";
    cout << "There are a total of:" << endl;
    cout << "     - " << numAirports << " airports;" << endl;
    cout << "     - " << numFlights << " flights;" << endl;
    cout << "     - " << numAirlines << " airlines;" << endl;
    cout << "     - " << countriesSet.size() << " reachable countries;" << endl;
    cout << "     - " << citiesSet.size() << " reachable cities." << endl;
}



void printNumFlights_outAirport(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the airport code [XXX]:";
    string airportCode;
    cin >> airportCode;
    airportCode = upperCase(airportCode);

    Graph<string> graph = flightManagement.getGraph();
    Vertex<string>* airport_ = graph.findVertex(airportCode);

    if (airport_ != NULL) {
        unordered_map<string, Airport*> mapa = flightManagement.getAirportMap();
        Airport* airport = mapa[airportCode];

        unordered_set<string> uniqueAirlines;
        for (const Edge<string>& edge : airport_->getAdj()) {
            uniqueAirlines.insert(edge.getAirline());
        }

        cout << "--------------------------------------------------\n";
        cout << "The number of flights involving the airport " << airport->getCode() << " (" << airport->getName() << ") is " << airport_->getAdj().size() + airport_->getIndegree() << ":" << endl;

        if (airport_->getAdj().size() == 1) {
            cout << "   - There is 1 flight leaving the airport;" << endl;
        } else {
            cout << "   - There are " << airport_->getAdj().size() << " flights leaving the airport;" << endl;
        }

        if (airport_->getIndegree() == 1) {
            cout << "   - There is 1 flight arriving the airport." << endl;
        } else {
            cout << "   - There are " << airport_->getIndegree() << " flights arriving in the airport." << endl;
        }

        cout << "Those flights are from " << uniqueAirlines.size() << " different airlines." << endl;

        return;
    }
    cout << "--------------------------------------------------\n";
    cout << "Airport not found! Please try again." << endl;
}
void printNumFlights_perCity(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the city name:";
    string cityName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cityName);
    cityName = upperCase(cityName);

    int numFlightsToCity = 0;
    int numFlightsOutCity = 0;

    Graph<string> graph = flightManagement.getGraph();
    unordered_map<string, Airport*> airports = flightManagement.getAirportMap();
    vector<string> airportsOfCity;

    //Primeiro confere quais os aeroportos da cidade
    for (pair<const string, Airport*> airport : airports){
        if(airport.second->getCity() == cityName){
            airportsOfCity.push_back(airport.first);
        }
    }

    if (airportsOfCity.empty()) {
        cout << "--------------------------------------------------\n";
        cout << "City not found! Please, try again." << endl;
        return;
    }


    unordered_set<string> uniqueAirlines;

    //Depois confere quantos voos saem e chegam desses aeroportos
    for (const string& airportCode : airportsOfCity){

        Vertex<string>* vertex = graph.findVertex(airportCode);
        if (vertex != NULL) {
            numFlightsOutCity += vertex->getAdj().size();
            numFlightsToCity += vertex->getIndegree();

            for (Edge<string> edge : vertex->getAdj()) {
                uniqueAirlines.insert(edge.getAirline());
            }
        }
    }


    cout << "--------------------------------------------------\n";
    cout << "The number of flights involving the city of " << cityName << " is " << (numFlightsToCity + numFlightsOutCity) << ':' << endl;

    if (numFlightsOutCity == 1) {
        cout << "   - There is 1 flight leaving the city;" << endl;
    } else {
        cout << "   - There are " << numFlightsOutCity << " flights leaving the city;" << endl;
    }

    if (numFlightsToCity == 1) {
        cout << "   - There is 1 flight arriving the city." << endl;
    } else {
        cout << "   - There are " << numFlightsToCity << " flights arriving in the city." << endl;
    }
    cout << "Those flights are from " << uniqueAirlines.size() << " different airlines." << endl;
}
void printNumFlights_perAirline(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the airline's code [XXX]:";
    string airlineCode;
    cin >> airlineCode;
    airlineCode = upperCase(airlineCode);

    unordered_map<string, Airline*> airlineMap = flightManagement.getAirlineMap();
    auto it = airlineMap.find(airlineCode);

    cout << "--------------------------------------------------\n";
    if (it != airlineMap.end()) {
        cout << "The number of flights operated by " << airlineMap[airlineCode]->getName() << " (" << airlineCode << ")" << " is " << airlineMap[airlineCode]->getFlights() << '.' << endl;
    } else {
        cout << "Airline not found. Please try again." << endl;
    }
}



void printNumByAirport(const FlightManagement& flightManagement) {
    cout << "--------------------------------------------------\n";
    cout << "Enter the airport's code [XXX]:";
    string airportCode;
    cin >> airportCode;
    airportCode = upperCase(airportCode);

    Graph<string> graph = flightManagement.getGraph();
    unordered_set<string> airports;

    Vertex<string>* vertex = graph.findVertex(airportCode);
    if (vertex != NULL) {
        for (const Edge<string>& edge : vertex->getAdj()) {
            airports.insert(edge.getDest()->getInfo());
        }
    } else {
        cout << "Airport not found! Please, try again." << endl;
        return;
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();

    set<string> countries;
    set<string> cities;
    set<Airport*, airportComparator> airportDest;

    for (const string& destinationAirport : airports){
        Airport* airport = allAirports[destinationAirport];
        countries.insert(airport->getCountry());
        cities.insert(airport->getCity());
        airportDest.insert(airport);
    }


    int numCountries = countries.size();
    int numAirports = airports.size();
    int numCities = cities.size();

    cout << "--------------------------------------------------\n";
    cout << "The airport " << allAirports[airportCode]->getName() << " (" << airportCode << ") is connected to:" << endl;

    if (numCountries == 1) {
        cout << "     - " << numCountries << " different country;" << endl;
    } else {
        cout << "     - " << numCountries << " different countries;" << endl;
    }

    if (numCities == 1) {
        cout << "     - " << numCities << " different city;" << endl;
    } else {
        cout << "     - " << numCities << " different cities;" << endl;
    }

    if (numAirports == 1) {
        cout << "     - " << numAirports << " different airport." << endl;
    } else {
        cout << "     - " << numAirports << " different airports." << endl;
    }

    cout << "--------------------------------------------------" << endl;
    cout << "Do you want to consult any of the results?" << endl;
    cout << "1. Only airports" << endl;
    cout << "2. Only cities" << endl;
    cout << "3. Only countries" << endl;
    cout << "4. Countries, cities and airports" << endl;
    cout << "0. None of them" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option) {
        case '0':
            return;
        case '1':
            printAirport(airportDest, false);
            break;
        case '2':
            printList(cities, true);
            break;
        case '3':
            printList(countries, false);
            break;
        case '4':
            printAirport(airportDest, true);
            break;
        default:
            cout << "--------------------------------------------------" << endl;
            cout << "Invalid option! Please, try again." << endl;
            return;
    }
}
void printNumByCity(const FlightManagement& flightManagement) {
    cout << "--------------------------------------------------\n";
    cout << "Enter the name of the city:";
    string cityName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cityName);
    cityName = upperCase(cityName);

    Graph<string> graph = flightManagement.getGraph();
    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    vector<string> airportsOfCity;

    for (pair<const string, Airport*> element : allAirports) {
        if(element.second->getCity() == cityName){
            airportsOfCity.push_back(element.first);
        }
    }

    if (airportsOfCity.empty()) {
        cout << "City not found! Please, try again." << endl;
        return;
    }

    unordered_set<string> airportsDestination;
    for (const string& airport : airportsOfCity) {

        Vertex<string>* airport_ = graph.findVertex(airport);
        if (airport_) {
            for (const Edge<string>& edge : airport_->getAdj()){
                airportsDestination.insert(edge.getDest()->getInfo());
            }
        }
    }

    set<string> countries;
    set<Airport*, airportComparator> airportSet;
    set<string> cities;

    for (const string& destinationAirport : airportsDestination){
        Airport* airport = allAirports[destinationAirport];
        countries.insert(airport->getCountry());
        cities.insert(airport->getCity());
        airportSet.insert(airport);
    }

    int numCountries = countries.size();
    int numAirports = airportsDestination.size();
    int numCities = cities.size();

    cout << "--------------------------------------------------\n";
    cout << "The city " << cityName << " is connected to:" << endl;

    if (numCountries == 1) {
        cout << "     - " << numCountries << " different country;" << endl;
    } else {
        cout << "     - " << numCountries << " different countries;" << endl;
    }

    if (numCities == 1) {
        cout << "     - " << numCities << " different city;" << endl;
    } else {
        cout << "     - " << numCities << " different cities;" << endl;
    }

    if (numAirports == 1) {
        cout << "     - " << numAirports << " different airport." << endl;
    } else {
        cout << "     - " << numAirports << " different airports." << endl;
    }

    cout << "--------------------------------------------------" << endl;
    cout << "Do you want to consult any of the results?" << endl;
    cout << "1. Only airports" << endl;
    cout << "2. Only cities" << endl;
    cout << "3. Only countries" << endl;
    cout << "4. Countries, cities and airports" << endl;
    cout << "0. None of them" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option) {
        case '0':
            return;
        case '1':
            printAirport(airportSet, false);
            break;
        case '2':
            printList(cities, true);
            break;
        case '3':
            printList(countries, false);
            break;
        case '4':
            printAirport(airportSet, true);
            break;
        default:
            cout << "--------------------------------------------------" << endl;
            cout << "Invalid option! Please, try again." << endl;
            return;
    }

}


void printStatisticWithStops(const FlightManagement& flightManagement) {
    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();

    cout << "--------------------------------------------------\n";
    cout << "Enter the source airport's code [XXX]:";
    string sourceAirportCode;
    cin >> sourceAirportCode;
    sourceAirportCode = upperCase(sourceAirportCode);

    unordered_map<string, Airport *>::iterator it;
    it = allAirports.find(sourceAirportCode);
    if (it == allAirports.end()) {
        cout << "Airport not found! Please, try again." << endl;
        return;
    }

    cout << "Enter the maximum number of layovers:";
    string maxStops_;
    cin >> maxStops_; cout << endl;
    for (char c : maxStops_) {
        if (!isdigit(c)) {
            cout << "--------------------------------------------------" << endl;
            cout << "Invalid input! Please, try again." << endl;
            return;
        }
    }
    int maxStops = stoi(maxStops_);

    vector<string> reachable = flightManagement.getGraph().bfsDis(sourceAirportCode, maxStops, true);


    set<string> citiesDest;
    set<string> countriesDest;
    set<Airport*, airportComparator> airportSet;

    for (const string& destinationAirport : reachable) {
        Airport* airport = allAirports[destinationAirport];
        airportSet.insert(airport);
        citiesDest.insert(airport->getCity());
        countriesDest.insert(airport->getCountry());
    }


    cout << "--------------------------------------------------" << endl;
    cout << "From " << sourceAirportCode << " (" << capitalizeWords((*it).second->getCity()) << ")" << ", with " << maxStops << " layovers, you can reach:" << endl;
    cout << "     - " << reachable.size() - 1 << " airports;" << endl;
    cout << "     - " << citiesDest.size() << " cities;" << endl;
    cout << "     - " << countriesDest.size() << " countries." << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Do you want to consult any of the results?" << endl;
    cout << "1. Only airports" << endl;
    cout << "2. Only cities" << endl;
    cout << "3. Only countries" << endl;
    cout << "4. Countries, cities and airports" << endl;
    cout << "0. None of them" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option) {
        case '0':
            return;
        case '1':
            printAirport(airportSet, false);
            break;
        case '2':
            printList(citiesDest, true);
            break;
        case '3':
            printList(countriesDest, false);
            break;
        case '4':
            printAirport(airportSet, true);
            break;
        default:
            cout << "--------------------------------------------------" << endl;
            cout << "Invalid option! Please, try again." << endl;
            return;
    }

}


int maxPathDistance(const FlightManagement& flightManagement, const string& sourceAirportCode) {
    Graph<string> graph = flightManagement.getGraph();
    Vertex<string> *s = graph.findVertex(sourceAirportCode);
    int maxDis = 0;

    if (s == NULL) {
        return 0;
    }

    for (auto node: graph.getVertexSet()) {
        node->setVisited(false);
    }

    queue<Vertex<string> *> unvisited;
    s->setDistance(0);
    unvisited.push(s);
    s->setVisited(true);
    while (!unvisited.empty()) {
        Vertex<string> *v = unvisited.front();
        unvisited.pop();
        for (const Edge<string> &neighbor: v->getAdj()) {
            Vertex<string> *w = neighbor.getDest();
            if (!w->isVisited()) {
                w->setDistance(v->getDistance() + 1);
                unvisited.push(w);
                w->setVisited(true);
            }
        }
        maxDis = max(v->getDistance(), maxDis);
    }
    return maxDis;
}
void printMaximumTrip(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Calculating the longest trips..." << endl;
    cout << "--------------------------------------------------" << endl;
    Graph<string> graph = flightManagement.getGraph();
    int maxDis = 0;
    for (Vertex<string>* vertex : graph.getVertexSet()) {
        maxDis = max(maxDis, maxPathDistance(flightManagement, vertex->getInfo()));
    }

    vector<pair<string, vector<string>>> trips;
    for (Vertex<string>* vertex : graph.getVertexSet()) {
        vector<string> dest = graph.bfsDis(vertex->getInfo(), maxDis, false);
        if (!dest.empty()) {
            trips.emplace_back(vertex->getInfo(), dest);
        }

    }

    cout << "The max trip has " << maxDis << " layovers!" << endl;
    cout << "--------------------------------------------------\n";
    cout << "FROM                                                     TO" << endl;
    cout << "CODE    COUNTRY      NAME                                CODE    COUNTRY          NAME" << endl;

    unordered_map<string, Airport*> airports = flightManagement.getAirportMap();
    for (const pair<string, vector<string>>& trip : trips) {
        Airport* source = airports[trip.first];
        for (const string& dest : trip.second) {
            Airport* second = airports[dest];
            cout << left << setw(7) << source->getCode() << " "
                 << left << setw(12) << capitalizeWords(source->getCountry()) << " "
                 << left << setw(35) << source->getName() << " "
                 << left << setw(7) << second->getCode() << " "
                 << left << setw(16) << capitalizeWords(second->getCountry()) << " "
                 << left << setw(37) << second->getName() << "\n";
        }
    }
}


void printAirportsGreatestCapability(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the number of airports to be seen (Maximum of " << flightManagement.getAirportMap().size() << " airports):";
    int k;
    cin >> k;
    cout << "--------------------------------------------------\n";

    Graph<string> graph = flightManagement.getGraph();
    set<pair<int, string>, greater<>> totalFlights;

    for (Vertex<string>* specificNode : graph.getVertexSet()){
        totalFlights.insert(make_pair(specificNode->getIndegree() + specificNode->getAdj().size(), specificNode->getInfo()));
    }


    unordered_map<string, Airport *> airports = flightManagement.getAirportMap();
    cout << "Top " << k << " airports by traffic capacity:" << endl;
    int i = 0;
    for (const auto& airport : totalFlights) {
        if (i >= k) {
            break;
        }
        cout << i+1 << ". " << airport.second << " - " << airport.first << " flights" << endl;
        i++;
    }
}


void printEssentialAirports(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    unordered_set<string> essentialAirports;

    int i = 0;
    for (auto element : graph.getVertexSet()){
        element->setVisited(false);
        element->setProcessing(false);
        element->setNum(i);
    }
    i++;

    for (auto element : graph.getVertexSet()){
        if (element->getNum() == 0){
            dfs_art(graph, element, essentialAirports, i);
        }
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    cout << "There are " << essentialAirports.size() <<  " essential airports to the network's circulation capability: " << endl;
    cout << "CODE   COUNTRY                     CITY                      NAME" << endl;

    set<Airport*, airportComparator> airportSet;
    for (const string& element : essentialAirports){
        airportSet.insert(allAirports[element]);
    }
    for (Airport* airport : airportSet) {
        cout << left << setw(6) << airport->getCode() << " ";
        cout << left << setw(27) << capitalizeWords(airport->getCountry()) << " ";
        cout << left << setw(25) << capitalizeWords(airport->getCity()) << " ";
        cout << left << setw(35) << airport->getName() << "\n";
    }
}
void dfs_art(const Graph<string>& g, Vertex<string> *v, unordered_set<string> &l, int &i){
    v->setProcessing(true);
    v->setNum(i);
    v->setLow(i);
    i++;
    int children = 0;
    for (const Edge<string>& edge : v->getAdj()){
        if(edge.getDest()->getNum() == 0){
            children++;
            dfs_art(g, edge.getDest(), l, i);
            v->setLow(min(edge.getDest()->getLow(), v->getLow()));
            if(v != g.getVertexSet().at(0) && edge.getDest()->getLow() >= v->getNum()) {
                l.insert(v->getInfo());
            }
        } else if(edge.getDest()->isProcessing()){
            v->setLow(min(edge.getDest()->getNum(), v->getLow()));
        }

    }

    v->setProcessing(false);
    if(v == g.getVertexSet().at(0) && children > 1){
        l.insert(v->getInfo());
    }
}


unordered_set<string> findAirportHaversine(const FlightManagement& flightManagement) {
    unordered_set<string> source;
    cout << "--------------------------------------------------\n";
    cout << "Enter the approximated latitude:";
    string latitude;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, latitude);

    if (!isFloat(latitude)) {
        cout << "--------------------------------------------------\n";
        cout << "The input value was not valid! Please, try again." << endl;
        return source;
    }

    cout << "Enter the approximated longitude:";
    string longitude;
    getline(cin, longitude);

    if (!isFloat(longitude)) {
        cout << "--------------------------------------------------\n";
        cout << "The input value was not valid! Please, try again." << endl;
        return source;
    }

    cout << "Enter the maximum distance of the nearby airports:";
    string radius;
    getline(cin, radius);

    if (!isFloat(radius)) {
        cout << "--------------------------------------------------\n";
        cout << "The input value was not valid! Please, try again." << endl;
        return source;
    }

    unordered_map<string, Airport*> airportMap = flightManagement.getAirportMap();
    Graph<string> graph = flightManagement.getGraph();

    for (Vertex<string>* vertex : graph.getVertexSet()) {
        Airport* airport = airportMap[vertex->getInfo()];
        double distance = haversineDistance(stod(latitude), stod(longitude), airport->getLatitude(), airport->getLongitude());
        if (distance <= stod(radius)) {
            source.insert(vertex->getInfo());
        }
    }
    return source;
}
unordered_set<string> findAirport(const FlightManagement& flightManagement) {
    cout << "--------------------------------------------------\n";
    cout << "Enter the airport's code [XXX]:";
    string airportCode;
    cin >> airportCode;
    airportCode = upperCase(airportCode);

    unordered_set<string> source;
    unordered_map<string, Airport*> airportsMap = flightManagement.getAirportMap();
    auto it = airportsMap.find(airportCode);
    if (it != airportsMap.end()) {
        source.insert(airportCode);
    }
    return source;
}
unordered_set<string> findAirportInCity(const FlightManagement& flightManagement) {
    cout << "--------------------------------------------------\n";
    cout << "Enter the name of the city:";
    string cityName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cityName);
    cityName = upperCase(cityName);

    unordered_set<string> source;
    unordered_map<string, Airport*> airportMap = flightManagement.getAirportMap();
    Graph<string> graph = flightManagement.getGraph();

    for (Vertex<string>* vertex : graph.getVertexSet()) {
        if (cityName == airportMap[vertex->getInfo()]->getCity()) {
            source.insert(vertex->getInfo());
        }
    }
    return source;
}

void printAirport(const set<Airport *, airportComparator>& set, bool b) {
    cout << "--------------------------------------------------" << endl;
    if (b) {
        cout << "Code   Country                     City                      Name" << endl;
        for (Airport* airport : set) {
            cout << left << setw(6) << airport->getCode() << " ";
            cout << left << setw(27) << capitalizeWords(airport->getCountry()) << " ";
            cout << left << setw(25) << capitalizeWords(airport->getCity()) << " ";
            cout << left << setw(35) << airport->getName() << "\n";
        }
    } else {
        cout << "Code   Name" << endl;
        for (Airport *airport: set) {
            cout << left << setw(6) << airport->getCode() << " ";
            cout << left << setw(35) << airport->getName() << "\n";
        }
    }
}
void printList(const set<string>& set, bool b) {
    cout << "--------------------------------------------------" << endl;
    if (b) {
        cout << "City" << endl;
    } else {
        cout << "Country" << endl;
    }
    for (const string& str : set) {
        cout << capitalizeWords(str) << "\n";
    }
}

double haversineDistance(double latA, double lonA, double latB, double lonB) {
    latA = (latA) * M_PI / 180.0;
    latB = (latB) * M_PI / 180.0;

    double vlat = latB - latA;
    double vlon = lonB - lonA;

    double a = pow(sin(vlat / 2), 2) + pow(sin(vlon / 2), 2) * cos(latA) * cos(latB);
    double rad = 6365;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}
string upperCase(const string& str) {
    string s;
    for (char c : str) {
        s += toupper(c);
    }
    return s;
}
string capitalizeWords(const string& str) {
    string result = str;
    bool capitalizeNext = true;

    for (char& c : result) {
        if (isspace(c)) {
            capitalizeNext = true;
        } else {
            if (capitalizeNext) {
                c = toupper(c);
                capitalizeNext = false;
            } else {
                c = tolower(c);
            }
        }
    }

    return result;
}
bool isFloat(const string& str) {
    char* end = nullptr;
    double val = strtod(str.c_str(), &end);
    return end != str.c_str() && *end == '\0' && val != HUGE_VAL;
}