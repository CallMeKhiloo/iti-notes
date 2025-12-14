
import java.util.Comparator;
import java.util.Map;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class Exercise2 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        // write your answer here
        List<City> allCities = countryDao.findAllCountries().stream() // gets all countries then get a stream of cities
                                                                      // for each country then flatmap spreads all these
                                                                      // cities into one stream
                .flatMap(country -> country.getCities().stream())
                .toList();

        Map<String, City> mostPopulatedByContinent = allCities.stream()
                .collect(Collectors.groupingBy(
                        city -> countryDao.findCountryByCode(city.getCountryCode()).getContinent(),
                        Collectors.collectingAndThen(
                                Collectors.maxBy(Comparator.comparing(City::getPopulation)), // find max city
                                Optional::get // convert Optional into City
                        )));

        for (String continent : mostPopulatedByContinent.keySet()) {
            System.out.println(
                    continent + "'s most populated city is " + mostPopulatedByContinent.get(continent).getName());
        }
    }

}
