
import java.util.Objects;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.Map;

import static java.lang.System.out;
import static java.util.Comparator.comparing;
import static java.util.stream.Collectors.maxBy;

import java.util.Comparator;

public class Exercise5 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        CityDao cityDao = InMemoryWorldDao.getInstance();
        // write your answer here
        Map<Country, City> capitals = countryDao.findAllCountries().stream()
                .filter(c -> cityDao.findCityById(c.getCapital()) != null)
                .collect(Collectors.toMap(country -> country, country -> cityDao.findCityById(country.getCapital())));

        City mostPopulatedCapital = capitals.values().stream().max(Comparator.comparing(City::getPopulation))
                .orElse(null);

        // for (Country country : capitals.keySet()) {
        // System.out.println(country.getName() + "'s capital is " +
        // capitals.get(country).getName());
        // }

        System.out.println("Most populated capital is " + mostPopulatedCapital.getName());
    }

}