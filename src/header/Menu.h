#ifndef FLIGHTMANAGEMENT_MENU_H
#define FLIGHTMANAGEMENT_MENU_H

#include <iostream>
#include "FlightManagement.h"
#include <unordered_set>
#include <set>


void printStatisticsMenu();
void printNumberFlightsMenu (const FlightManagement& flightManagement);
void printCountriesOptionsMenu(const FlightManagement& flightManagement);
void printDestinationOptionMenu(const FlightManagement& flightManagement);
void printDestinationWithStopsMenu(const FlightManagement& flightManagement);

void printGlobalAirports(const FlightManagement& flightManagement);
void printGlobalFlights(const FlightManagement& flightManagement);
void printNumFlights_outAirport(const FlightManagement& flightManagement);
void printNumFlights_perCity(const FlightManagement& flightManagement);
void printNumFlights_perAirline(const FlightManagement& flightManagement);
void printNumCountries_perAirport(const FlightManagement& flightManagement);
void printNumCountries_perCity(const FlightManagement& flightManagement);
void printNumAirports_perAirport(const FlightManagement& flightManagement);
void printNumCities_perAirport(const FlightManagement& flightManagement);
vector<string> reachableDest(const FlightManagement& flightManagement, const string& sourceAirportCode, int maxStops);
//void printNumberAirportsWithStops(const FlightManagement& flightManagement);
//void printNumberCitiesWithStops(const FlightManagement& flightManagement);
//void printNumberCountriesWithStops(const FlightManagement& flightManagement);
void printMaximumTrip(const FlightManagement& flightManagement);
void printAirportsGreatestCapability(const FlightManagement& flightManagement);
void printEssentialAirports(const FlightManagement& flightManagement);
void dfs_art(const Graph<string>& g, Vertex<string> *v, unordered_set<string> &l, int &i);

struct airportComparator;
void printStatisticWithStops(const FlightManagement& flightManagement);

void printAirport(const set<Airport *, airportComparator>& set, bool b);
void printList(const set<string>& set, bool b);

bool isNumber(const string& str);
string upperCase(const string& str);

#endif //FLIGHTMANAGEMENT_MENU_H
