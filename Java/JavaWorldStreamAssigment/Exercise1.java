
import java.util.Comparator;
import java.util.stream.Collectors;
import java.util.Map;

public class Exercise1 {

   public static void main(String[] args) {
      CountryDao countryDao = InMemoryWorldDao.getInstance();
      // write your answer here
      Map<Country, City> mp = countryDao.findAllCountries().stream()
            .filter(c -> c.getCities() != null && !c.getCities().isEmpty()) // i used this to forbid empty lists as
                                                                            // Collectors.toMap gives
                                                                            // nullpointerexcetpion when the key or
                                                                            // value has null values
            .collect(Collectors.toMap(country -> country,
                  country -> country.getCities().stream().max(Comparator.comparing(City::getPopulation)).orElse(null)));

      // countryDao.findAllCountries().forEach(c -> System.out.println(
      // c.getName() + " cities size = " + c.getCities().size()));
      for (Country country : mp.keySet()) {
         if (mp.get(country) != null) {
            System.out.println(country.getName() + "'s most populated city is " + mp.get(country).getName());
         }
      }
   }

}