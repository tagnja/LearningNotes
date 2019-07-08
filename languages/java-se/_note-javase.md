# Java Note

### Content

<h3 id="content"></h3>

- II. Libraries
  - [Date Time Library](#dtli)

### Main



### Data Time Library

<h3 id="dtli"></h3>

- java.util 
  - Date
  - Calendar
  - TimeZone
  - SimpleDateFormat
  - TimeUnit
- java.time // Since Java 8
  - LocalDate
  - Period
  - LocalDateTime
  - Duration
  - ChronoUnit
  - ZonedDateTime
  - Temporal
- JodaTime
  - LocalDate
  - Period
- Date4J
  - DateTime

**Java 8 Date Time API**

- based on the popular Java library called JodaTime.

- simplified date and time processing and fixed many shortcomings of the old date library.

- **API Clarity**. New API is clear, concise and easy to understand. It does not have a lot of inconsistencies found in the old library such as the field numbering (in Calendar months are zero-based, but days of week are one-based).

- **API Flexibility**. working with multiple representations of time.

  ```
  Instant – represents a point in time (timestamp)
  LocalDate – represents a date (year, month, day)
  LocalDateTime – same as LocalDate, but includes time with nanosecond precision
  OffsetDateTime – same as LocalDateTime, but with time zone offset
  LocalTime – time with nanosecond precision and without date information
  ZonedDateTime – same as OffsetDateTime, but includes a time zone ID
  OffsetLocalTime – same as LocalTime, but with time zone offset
  MonthDay – month and day, without year or time
  YearMonth – month and year, without day or time
  Duration – amount of time represented in seconds, minutes and hours. Has nanosecond precision
  Period – amount of time represented in days, months and years
  ```

- **Immutability and Thread-Safety**.

- **Method Chaining**. Allowing to implement complex transformations in a single line of code.

References
[Migrating to the New Java 8 Date Time API](https://www.baeldung.com/migrating-to-java-8-date-time-api)