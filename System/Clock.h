#ifndef SYSTEM_CLOCK_H
#define SYSTEM_CLOCK_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Config.h>


namespace System
{
////////////////////////////////////////////////////////////
/// \brief Utility class for manipulating time
///
////////////////////////////////////////////////////////////
class Clock
{
public :

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// The clock starts automatically after being constructed.
    ///
    ////////////////////////////////////////////////////////////
    Clock();

    ////////////////////////////////////////////////////////////
    /// \brief Get the time elapsed
    ///
    /// This function returns the time elapsed since the last call
    /// to Reset() (or the construction of the instance if Reset()
    /// has not been called) in seconds.
    ///
    /// \return Time elapsed, in seconds
    ///
    ////////////////////////////////////////////////////////////
    float GetElapsedTime() const;

    ////////////////////////////////////////////////////////////
    /// \brief Restart the timer
    ///
    /// This function puts the time counter back to zero.
    ///
    ////////////////////////////////////////////////////////////
    void Reset();

private :

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    double myStartTime; ///< Time of last reset
};

} // namespace System


#endif // SYSTEM_CLOCK_H


////////////////////////////////////////////////////////////
/// \class System::Clock
/// \ingroup system
///
/// System::Clock is a lightweight class for measuring time.
/// Its resolution depends on the underlying OS, but you can generally
/// expect a 1 ms resolution.
///
/// Usage example:
/// \code
/// System::Clock clock;
/// ...
/// float time1 = clock.GetElapsedTime();
/// clock.Reset();
/// ...
/// float time2 = clock.GetElapsedTime();
/// \endcode
///
////////////////////////////////////////////////////////////
