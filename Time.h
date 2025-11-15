#ifndef Time_H
#define Time_H

#include <iostream>

class Time {
public:
  /** @brief Default Constructor for Time
   */
  Time();

  /** @brief Constructor for Time
   *
   * @param hours - Hour int
   * @param mins - Minute int
   * @param secs - Second int
   *
   */
  Time( int hours, int mins, int secs );

  /** @brief Get Hour from Time
   *
   * @return int
   *
   */
  int GetHour() const;

  /** @brief Set Hour in Time
   *
   * @param hours - Hour int
   *
   */
  void SetHour( int hours );

  /** @brief Get Minute from Time
   *
   * @return int
   *
   */
  int GetMinute() const;

  /** @brief Set Minute in Time
   *
   * @param mins - Minute int
   * @return void
   *
   */
  void SetMinute( int mins );

  /** @brief Get Seconds from Time
   *
   * @return int
   *
   */
  int GetSecond() const;

  /** @brief Set Seconds in Time
   *
   * @param secs - Second int
   * @return void
   *
   */
  void SetSecond( int secs );

  /** @brief Copy from another Time obj
   *
   * @param other - const Time&
   * @return Time&
   *
   */
  Time& operator=(const Time& other) = default;

  /** @brief Copy Constructor for Time
   *
   * @param other - const Time&
   * @return Time
   *
   */
  Time(const Time& other) = default;

private:
  /// number of Hours
  int hour;
  /// number of Minutes
  int minute;
  /// number of Seconds
  int sec;
};

/** @brief Output operator (<<) for Time obj
* @param os - std::ostream&
* @param C - const Time&
* @return std::ostream&
*/
std::ostream & operator <<( std::ostream & os, const Time & C );
/** @brief Input operator (>>) for Time obj
* @param input - std::istream&
* @param C - const Time&
* @return std::istream&
*/
std::istream & operator >>( std::istream & input, Time & C );

#endif
