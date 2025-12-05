package dev.sixik.noesisgui.nsgui;

/**
 * Specifies the scope which modifies how input from alternative input methods is interpreted
 */
public enum NSGui_InputScope {
    /**
     * The default handling of input commands
     */
    InputScope_Default,

    /**
     * The text input pattern for a Uniform Resource Locator (URL)
     */
    InputScope_Url,

    /**
     * The text input pattern for the full path of a file
     */
    InputScope_FullFilePath,

    /**
     * The text input pattern for a file name
     */
    InputScope_FileName,

    /**
     * The text input pattern for an email user name
     */
    InputScope_EmailUserName,

    /**
     * The text input pattern for a Simple Mail Transfer Protocol (SMTP) email address
     */
    InputScope_EmailSmtpAddress,

    /**
     * The text input pattern for a log on name
     */
    InputScope_LogOnName,

    /**
     * The text input pattern for a person's full name
     */
    InputScope_PersonalFullName,

    /**
     * The text input pattern for the prefix of a person's name
     */
    InputScope_PersonalNamePrefix,

    /**
     * The text input pattern for a person's given name
     */
    InputScope_PersonalGivenName,

    /**
     * The text input pattern for a person's middle name
     */
    InputScope_PersonalMiddleName,

    /**
     * The text input pattern for a person's surname
     */
    InputScope_PersonalSurname,

    /**
     * The text input pattern for the suffix of a person's name
     */
    InputScope_PersonalNameSuffix,

    /**
     * The text input pattern for a postal address
     */
    InputScope_PostalAddress,

    /**
     * The text input pattern for a postal code
     */
    InputScope_PostalCode,

    /**
     * The text input pattern for a street address
     */
    InputScope_AddressStreet,

    /**
     * The text input pattern for a state or province
     */
    InputScope_AddressStateOrProvince,

    /**
     * The text input pattern for a city address
     */
    InputScope_AddressCity,

    /**
     * The text input pattern for the name of a country
     */
    InputScope_AddressCountryName,

    /**
     * The text input pattern for the abbreviated name of a country
     */
    InputScope_AddressCountryShortName,

    /**
     * The text input pattern for amount and symbol of currency
     */
    InputScope_CurrencyAmountAndSymbol,

    /**
     * The text input pattern for amount of currency
     */
    InputScope_CurrencyAmount,

    /**
     * The text input pattern for a calendar date
     */
    InputScope_Date,

    /**
     * The text input pattern for the numeric month in a calendar date
     */
    InputScope_DateMonth,

    /**
     * The text input pattern for the numeric day in a calendar date
     */
    InputScope_DateDay,

    /**
     * The text input pattern for the year in a calendar date
     */
    InputScope_DateYear,

    /**
     * The text input pattern for the name of the month in a calendar date
     */
    InputScope_DateMonthName,

    /**
     * The text input pattern for the name of the day in a calendar date
     */
    InputScope_DateDayName,

    /**
     * The text input pattern for digits
     */
    InputScope_Digits,

    /**
     * The text input pattern for a number
     */
    InputScope_Number,

    /**
     * The text input pattern for one character
     */
    InputScope_OneChar,

    /**
     * The text input pattern for a password
     */
    InputScope_Password,

    /**
     * The text input pattern for a telephone number
     */
    InputScope_TelephoneNumber,

    /**
     * The text input pattern for a telephone country code
     */
    InputScope_TelephoneCountryCode,

    /**
     * The text input pattern for a telephone area code
     */
    InputScope_TelephoneAreaCode,

    /**
     * The text input pattern for a telephone local number
     */
    InputScope_TelephoneLocalNumber,

    /**
     * The text input pattern for the time
     */
    InputScope_Time,

    /**
     * The text input pattern for the hour of the time
     */
    InputScope_TimeHour,

    /**
     * The text input pattern for the minutes or seconds of time
     */
    InputScope_TimeMinorSec,

    /**
     * The text input pattern for a full-width number
     */
    InputScope_NumberFullWidth,

    /**
     * The text input pattern for alphanumeric half-width characters
     */
    InputScope_AlphanumericHalfWidth,

    /**
     * The text input pattern for alphanumeric full-width characters
     */
    InputScope_AlphanumericFullWidth,

    /**
     * The text input pattern for Chinese currency
     */
    InputScope_CurrencyChinese,

    /**
     * The text input pattern for the Bopomofo Mandarin Chinese phonetic transcription system
     */
    InputScope_Bopomofo,

    /**
     * The text input pattern for the Hiragana writing system
     */
    InputScope_Hiragana,

    /**
     * The text input pattern for half-width Katakana characters
     */
    InputScope_KatakanaHalfWidth,

    /**
     * The text input pattern for full-width Katakana characters
     */
    InputScope_KatakanaFullWidth,

    /**
     * The text input pattern for Hanja characters
     */
    InputScope_Hanja,

    /**
     * The text input pattern for a phrase list
     */
    InputScope_PhraseList(-1),

    /**
     * The text input pattern for a regular expression
     */
    InputScope_RegularExpression(-2),

    /**
     * The text input pattern for the Speech Recognition Grammar Specification (SRGS)
     */
    InputScope_Srgs(-3),

    /**
     * The text input pattern for XML
     */
    InputScope_Xml(-4);


    public final int value;

    NSGui_InputScope(int value) {
        this.value = value;
    }

    NSGui_InputScope() {
        this.value = this.ordinal();
    }

    public static NSGui_InputScope fromValue(int value) {
        for (NSGui_InputScope scope : values()) {
            if (scope.value == value) {
                return scope;
            }
        }
        throw new IllegalArgumentException("No InputScope with value: " + value);
    }
}