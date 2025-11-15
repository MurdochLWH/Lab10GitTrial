
#ifndef Date_H
#define Date_H

#include <string>
#include <iostream>

class Date {
public:
  /// Array of months in string
  static const std::string months[12];
  static const int dayLimit[12];

  /** @brief Default Constructor for Date
   */
  Date();

  /** @brief Constructor for Date
   *
   * @param days - day of month
   * @param mont - month of year
   * @param yea - year number
   *
   */
  Date( int days, int mont, int yea );
  // Construct a Date from a day, month ,
  // and year.

  ~Date() = default;

  /** @brief Get Day from Date
   *
   * @return int
   *
   */
  int GetDay() const;
  // Get the number of days.

  /** @brief Set Day in Date
   *
   * @param days - day of month
   * @return void
   *
   */
  void SetDay( int days );
  // Set the number of days.

  /** @brief Get Month from Date
   *
   * @return int
   *
   */
  int GetMonth() const;
  // Get the number of months

  /** @brief Set Month in Date
   *
   * @param mont - month of year
   * @return void
   *
   */
  void SetMonth( int mont );
  // Set the number of months

  /** @brief Get Year from Date
   *
   * @return int
   *
   */
  int GetYear() const;
  // Get the number of years

  /** @brief Set Year in Date
   *
   * @param yea - year number
   * @return void
   *
   */
  void SetYear( int yea );
  // Set the number of years

  /** @brief Copy from another Date obj
   *
   * @param other - const Date&
   * @return Date&
   *
   */
  Date& operator=(const Date& other);

private:
  /// number of day
  int day;
  /// number of month
  int month;
  /// number of year
  int year;
};

/** @brief Output operator (<<) for Date obj
* @param os - std::ostream&
* @param C - const Date&
* @return std::ostream&
*/
std::ostream & operator <<( std::ostream & os, const Date & C );
/** @brief Input operator (>>) for Date obj
* @param input - std::istream&
* @param C - const Date&
* @return std::istream&
*/
std::istream & operator >>( std::istream & input, Date & C );
#endif
