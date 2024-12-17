/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob
 * Roberts-Baca.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <regex>
#include <vector>

/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double> &dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.
  auto min = std::min_element(dailyWeather.begin(), dailyWeather.end());
  auto max = std::max_element(dailyWeather.begin(), dailyWeather.end());
  auto avg = std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0) /
             dailyWeather.size();
  Forecast res;
  res.min_temp = *min;
  res.max_temp = *max;
  res.avg_temp = avg;
  return res;
}

std::vector<Forecast>
get_forecasts(const std::vector<std::vector<double>> &weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData
   * which contains std::vector<double> which contain values for the weather on
   * that day.
   */
  std::vector<Forecast> res(weatherData.size());
  std::transform(weatherData.begin(), weatherData.end(), res.begin(),
                 [](auto x) { return compute_forecast(x); });
  return res;
}

std::vector<Forecast>
get_filtered_data(const std::vector<Forecast> &forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with
  // specific weather.
  std::vector<Forecast> filtered_data(forecastData.begin(), forecastData.end());
  auto filter = std::remove_if(filtered_data.begin(), filtered_data.end(),
                               [](const auto &x) {
                                 return x.min_temp < kMaxTempRequirement ||
                                        x.avg_temp < uAvgTempRequirement;
                               });
  filtered_data.erase(filter, filtered_data.end());
  return filtered_data;
};

std::vector<Forecast>
get_shuffled_data(const std::vector<Forecast> &forecastData) {
  // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the
  // data!
  std::vector<Forecast> res(forecastData.begin(), forecastData.end());
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(res.begin(), res.end(), g);
  return res;
}

std::vector<Forecast>
run_weather_pipeline(const std::vector<std::vector<double>> &weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!
  auto forecasts = get_forecasts(weatherData);
  auto filtered_data = get_filtered_data(forecasts);
  auto shuffled_data = get_shuffled_data(filtered_data);
  return shuffled_data;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"