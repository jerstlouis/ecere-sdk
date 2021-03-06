//////////////////////////////////////////////////////////////////////////////// ////////////////////////
//////////////////////////////////////////////////////////////////////////////// ////////////////////////
////                                                                        //// ////////////////////////
////    ecere Module                                                        //// ////////////////////////
////                                                                        //// ////////////////////////
//////////////////////////////////////////////////////////////////////////////// ////////////////////////
//////////////////////////////////////////////////////////////////////////////// ////////////////////////


#if !defined(__ECERE_H__)
#define __ECERE_H__

#define CPP11 (defined(__cplusplus) && __cplusplus >= 201103L)

#ifdef __cplusplus

extern "C" {

#endif



////////////////////////////////////////////////////////////// includes //////// ////////////////
//////////////////////////////////////////////////////////////////////////////// ////////////////
//////////////////////////////////////////////////////////////////////////////// ////////////////

#include "eC.h"

#define ECERE_APP_INTRO(c) \
      APP_INTRO(true) \
      ecere_init(app); \
      loadTranslatedStrings(null, MODULE_NAME); \
      Instance_evolve(&app, class_ ## c);

#define ECERE_APP_OUTRO \
      unloadTranslatedStrings(MODULE_NAME); \
      APP_OUTRO

#define GUIAPP_INTRO ECERE_APP_INTRO(GuiApplication)


// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////    //////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////



// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere  /////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////



// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||sys  ////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
typedef double C(Time);
#if CPP11
enum C(ThreadPriority) : int
#else
typedef int C(ThreadPriority);
enum C(ThreadPriority)
#endif
{
   ThreadPriority_normal = 0x0,
   ThreadPriority_aboveNormal = 0x1,
   ThreadPriority_belowNormal = -1,
   ThreadPriority_highest = 0x2,
   ThreadPriority_lowest = -2,
   ThreadPriority_idle = -15,
   ThreadPriority_timeCritical = 0xF
};

typedef C(Instance) C(Thread);
#if CPP11
enum C(SettingsIOResult) : int
#else
typedef int C(SettingsIOResult);
enum C(SettingsIOResult)
#endif
{
   SettingsIOResult_error = 0x0,
   SettingsIOResult_success = 0x1,
   SettingsIOResult_fileNotFound = 0x2,
   SettingsIOResult_fileNotCompatibleWithDriver = 0x3
};

typedef struct C(Semaphore) C(Semaphore);
typedef int64 C(SecSince1970);
typedef struct C(Point) C(Point);
#if CPP11
enum C(Month) : int
#else
typedef int C(Month);
enum C(Month)
#endif
{
   Month_january = 0x0,
   Month_february = 0x1,
   Month_march = 0x2,
   Month_april = 0x3,
   Month_may = 0x4,
   Month_june = 0x5,
   Month_july = 0x6,
   Month_august = 0x7,
   Month_september = 0x8,
   Month_october = 0x9,
   Month_november = 0xA,
   Month_december = 0xB
};

typedef int C(MinMaxValue);
#if CPP11
enum C(JSONResult) : int
#else
typedef int C(JSONResult);
enum C(JSONResult)
#endif
{
   JSONResult_syntaxError = 0x0,
   JSONResult_success = 0x1,
   JSONResult_typeMismatch = 0x2,
   JSONResult_noItem = 0x3
};

typedef C(Instance) C(JSONParser);
typedef C(Instance) C(GlobalSettingsDriver);
typedef C(Instance) C(GlobalSettingsData);
typedef C(Instance) C(GlobalSettings);
#if CPP11
enum C(GlobalSettingType) : int
#else
typedef int C(GlobalSettingType);
enum C(GlobalSettingType)
#endif
{
   GlobalSettingType_integer = 0x0,
   GlobalSettingType_singleString = 0x1,
   GlobalSettingType_stringList = 0x2
};

typedef C(GlobalSettings) C(GlobalAppSettings);
typedef uint C(FileSize);
typedef uint32 C(FileAttribs);
struct C(FileStats)
{
   C(FileAttribs) attribs;
   C(FileSize) size;
   C(SecSince1970) accessed;
   C(SecSince1970) modified;
   C(SecSince1970) created;
};
typedef struct C(FileStats) C(FileStats);
#if CPP11
enum C(FileSeekMode) : int
#else
typedef int C(FileSeekMode);
enum C(FileSeekMode)
#endif
{
   FileSeekMode_start = 0x0,
   FileSeekMode_current = 0x1,
   FileSeekMode_end = 0x2
};

#if CPP11
enum C(FileOpenMode) : int
#else
typedef int C(FileOpenMode);
enum C(FileOpenMode)
#endif
{
   FileOpenMode_read = 0x1,
   FileOpenMode_write = 0x2,
   FileOpenMode_append = 0x3,
   FileOpenMode_readWrite = 0x4,
   FileOpenMode_writeRead = 0x5,
   FileOpenMode_appendRead = 0x6
};

typedef C(Instance) C(FileMonitor);
#if CPP11
enum C(FileLock) : int
#else
typedef int C(FileLock);
enum C(FileLock)
#endif
{
   FileLock_unlocked = 0x0,
   FileLock_shared = 0x1,
   FileLock_exclusive = 0x2
};

typedef struct C(FileListing) C(FileListing);
typedef uint32 C(FileChange);
typedef C(IOChannel) C(File);
typedef uint32 C(ErrorCode);
typedef C(File) C(DualPipe);
#if CPP11
enum C(DayOfTheWeek) : int
#else
typedef int C(DayOfTheWeek);
enum C(DayOfTheWeek)
#endif
{
   DayOfTheWeek_sunday = 0x0,
   DayOfTheWeek_monday = 0x1,
   DayOfTheWeek_tuesday = 0x2,
   DayOfTheWeek_wednesday = 0x3,
   DayOfTheWeek_thursday = 0x4,
   DayOfTheWeek_friday = 0x5,
   DayOfTheWeek_saturday = 0x6
};

typedef struct C(DateTime) C(DateTime);
typedef struct C(Date) C(Date);
typedef struct C(Condition) C(Condition);
typedef uint32 C(CharCategories);
typedef struct C(Box) C(Box);
typedef C(Instance) C(ArchiveDir);
#if CPP11
enum C(ArchiveAddMode) : int
#else
typedef int C(ArchiveAddMode);
enum C(ArchiveAddMode)
#endif
{
   ArchiveAddMode_replace = 0x0,
   ArchiveAddMode_refresh = 0x1,
   ArchiveAddMode_update = 0x2,
   ArchiveAddMode_readOnlyDir = 0x3
};

typedef C(Instance) C(Archive);
typedef C(Instance) C(Window);
typedef C(Window) C(CommonControl);
typedef C(CommonControl) C(Button);
struct CM(Timer)
{
   byte __ecerePrivateData0[16];
   C(Time) _delay;
};
typedef C(Instance) C(Timer);
// end -- moved backwards outputs
#define AllErrors (minor)

#define AnyFileChange ((((unsigned int)(true)) | (((unsigned int)(true)) << 1) | (((unsigned int)(true)) << 2) | (((unsigned int)(true)) << 3) | (((unsigned int)(true)) << 4)))

#define Pi (((C(Angle))(3.1415926535897932384626433832795028841971)))

typedef uint32 C(ArchiveOpenFlags);
typedef C(File) C(BufferedFile);
#if CPP11
enum C(CharCategory) : int
#else
typedef int C(CharCategory);
enum C(CharCategory)
#endif
{
   CharCategory_none = 0x0,
   CharCategory_Mn = 0x1,
   CharCategory_markNonSpacing = 0x1,
   CharCategory_Mc = 0x2,
   CharCategory_markSpacing = 0x2,
   CharCategory_Me = 0x3,
   CharCategory_markEnclosing = 0x3,
   CharCategory_Nd = 0x4,
   CharCategory_numberDecimalDigit = 0x4,
   CharCategory_Nl = 0x5,
   CharCategory_numberLetter = 0x5,
   CharCategory_No = 0x6,
   CharCategory_numberOther = 0x6,
   CharCategory_Zs = 0x7,
   CharCategory_separatorSpace = 0x7,
   CharCategory_Zl = 0x8,
   CharCategory_separatorLine = 0x8,
   CharCategory_Zp = 0x9,
   CharCategory_separatorParagraph = 0x9,
   CharCategory_Cc = 0xA,
   CharCategory_otherControl = 0xA,
   CharCategory_Cf = 0xB,
   CharCategory_otherFormat = 0xB,
   CharCategory_Cs = 0xC,
   CharCategory_otherSurrogate = 0xC,
   CharCategory_Co = 0xD,
   CharCategory_otherPrivateUse = 0xD,
   CharCategory_Cn = 0xE,
   CharCategory_otherNotAssigned = 0xE,
   CharCategory_Lu = 0xF,
   CharCategory_letterUpperCase = 0xF,
   CharCategory_Ll = 0x10,
   CharCategory_letterLowerCase = 0x10,
   CharCategory_Lt = 0x11,
   CharCategory_letterTitleCase = 0x11,
   CharCategory_Lm = 0x12,
   CharCategory_letterModifier = 0x12,
   CharCategory_Lo = 0x13,
   CharCategory_letterOther = 0x13,
   CharCategory_Pc = 0x14,
   CharCategory_punctuationConnector = 0x14,
   CharCategory_Pd = 0x15,
   CharCategory_punctuationDash = 0x15,
   CharCategory_Ps = 0x16,
   CharCategory_punctuationOpen = 0x16,
   CharCategory_Pe = 0x17,
   CharCategory_punctuationClose = 0x17,
   CharCategory_Pi = 0x18,
   CharCategory_punctuationInitial = 0x18,
   CharCategory_Pf = 0x19,
   CharCategory_punctuationFinal = 0x19,
   CharCategory_Po = 0x1A,
   CharCategory_punctuationOther = 0x1A,
   CharCategory_Sm = 0x1B,
   CharCategory_symbolMath = 0x1B,
   CharCategory_Sc = 0x1C,
   CharCategory_symbolCurrency = 0x1C,
   CharCategory_Sk = 0x1D,
   CharCategory_symbolModifier = 0x1D,
   CharCategory_So = 0x1E,
   CharCategory_symbolOther = 0x1E
};

typedef C(File) C(ConsoleFile);
typedef double C(Distance);
typedef C(GlobalSettingsDriver) C(ECONGlobalSettings);
typedef C(JSONParser) C(ECONParser);
#if CPP11
enum C(ErrorLevel) : int
#else
typedef int C(ErrorLevel);
enum C(ErrorLevel)
#endif
{
   ErrorLevel_veryFatal = 0x0,
   ErrorLevel_fatal = 0x1,
   ErrorLevel_major = 0x2,
   ErrorLevel_minor = 0x3
};

typedef uint64 C(FileSize64);
#if CPP11
enum C(GuiErrorCode) : uint
#else
typedef C(ErrorCode) C(GuiErrorCode);
enum C(GuiErrorCode)
#endif
{
   GuiErrorCode_driverNotSupported = 0x101,
   GuiErrorCode_windowCreationFailed = 0x102,
   GuiErrorCode_graphicsLoadingFailed = 0x103,
   GuiErrorCode_modeSwitchFailed = 0x104
};

typedef C(GlobalSettingsDriver) C(JSONGlobalSettings);
#if CPP11
enum C(LoggingMode) : int
#else
typedef int C(LoggingMode);
enum C(LoggingMode)
#endif
{
   LoggingMode_noLogging = 0x0,
   LoggingMode_stdOut = 0x1,
   LoggingMode_stdErr = 0x2,
   LoggingMode_debug = 0x3,
   LoggingMode_logFile = 0x4,
   LoggingMode_msgBox = 0x5,
   LoggingMode_buffer = 0x6
};

typedef uint32 C(MoveFileOptions);
typedef uint32 C(PipeOpenMode);
typedef struct C(Pointf) C(Pointf);
#if CPP11
enum C(PredefinedCharCategories) : uint
#else
typedef C(CharCategories) C(PredefinedCharCategories);
enum C(PredefinedCharCategories)
#endif
{
   PredefinedCharCategories_none = 0x1,
   PredefinedCharCategories_marks = 0xE,
   PredefinedCharCategories_numbers = 0x70,
   PredefinedCharCategories_separators = 0x380,
   PredefinedCharCategories_others = 0x7C00,
   PredefinedCharCategories_letters = 0xF8000,
   PredefinedCharCategories_punctuation = 0x7F00000,
   PredefinedCharCategories_symbols = 0x78000000,
   PredefinedCharCategories_connector = 0x100000
};

typedef C(Button) C(RepButton);
#if CPP11
enum C(SetBool) : uint
#else
typedef uint C(SetBool);
enum C(SetBool)
#endif
{
   SetBool_unset = 0x0,
   SetBool_false = 0x1,
   SetBool_true = 0x2
};

typedef struct C(Size) C(Size);
#if CPP11
enum C(SysErrorCode) : uint
#else
typedef C(ErrorCode) C(SysErrorCode);
enum C(SysErrorCode)
#endif
{
   SysErrorCode_allocationFailed = 0x1001,
   SysErrorCode_nameInexistant = 0x1002,
   SysErrorCode_nameExists = 0x1003,
   SysErrorCode_missingLibrary = 0x1004,
   SysErrorCode_fileNotFound = 0x3005,
   SysErrorCode_writeFailed = 0x2006
};

typedef C(File) C(TempFile);
typedef uint C(TimeStamp32);
extern int M_VTBLID(Archive, clear);
#define Archive_clear(__i) \
   VMETHOD(CO(Archive), Archive, clear, __i, C(bool), \
      C(Archive), \
      __i)
extern C(Method) * METHOD(Archive, clear);
extern int M_VTBLID(Archive, fileExists);
#define Archive_fileExists(__i, fileName) \
   VMETHOD(CO(Archive), Archive, fileExists, __i, C(FileAttribs), \
      C(Archive) _ARG const char *, \
      __i _ARG fileName)
extern C(Method) * METHOD(Archive, fileExists);
extern int M_VTBLID(Archive, fileOpen);
#define Archive_fileOpen(__i, fileName) \
   VMETHOD(CO(Archive), Archive, fileOpen, __i, C(File), \
      C(Archive) _ARG const char *, \
      __i _ARG fileName)
extern C(Method) * METHOD(Archive, fileOpen);
extern int M_VTBLID(Archive, fileOpenAtPosition);
#define Archive_fileOpenAtPosition(__i, position) \
   VMETHOD(CO(Archive), Archive, fileOpenAtPosition, __i, C(File), \
      C(Archive) _ARG uint, \
      __i _ARG position)
extern C(Method) * METHOD(Archive, fileOpenAtPosition);
extern int M_VTBLID(Archive, openDirectory);
#define Archive_openDirectory(__i, name, stats, addMode) \
   VMETHOD(CO(Archive), Archive, openDirectory, __i, C(ArchiveDir), \
      C(Archive) _ARG const char * _ARG C(FileStats) * _ARG C(ArchiveAddMode), \
      __i _ARG name _ARG stats _ARG addMode)
extern C(Method) * METHOD(Archive, openDirectory);
extern int M_VTBLID(Archive, setBufferRead);
#define Archive_setBufferRead(__i, bufferRead) \
   VMETHOD(CO(Archive), Archive, setBufferRead, __i, void, \
      C(Archive) _ARG uint, \
      __i _ARG bufferRead)
extern C(Method) * METHOD(Archive, setBufferRead);
extern int M_VTBLID(Archive, setBufferSize);
#define Archive_setBufferSize(__i, bufferSize) \
   VMETHOD(CO(Archive), Archive, setBufferSize, __i, void, \
      C(Archive) _ARG uint, \
      __i _ARG bufferSize)
extern C(Method) * METHOD(Archive, setBufferSize);
extern C(Property) * PROPERTY(Archive, totalSize);
extern void (* Archive_set_totalSize)(C(Archive) a, C(FileSize) value);
extern C(FileSize) (* Archive_get_totalSize)(C(Archive) a);

extern C(Property) * PROPERTY(Archive, bufferSize);
extern void (* Archive_set_bufferSize)(C(Archive) a, uint value);

extern C(Property) * PROPERTY(Archive, bufferRead);
extern void (* Archive_set_bufferRead)(C(Archive) a, uint value);

extern C(bool) (* ArchiveDir_add)(C(ArchiveDir) __this, const char * name, const char * path, C(ArchiveAddMode) addMode, int compression, int * ratio, uint * newPosition);

extern int M_VTBLID(ArchiveDir, addFromFile);
#define ArchiveDir_addFromFile(__i, name, input, stats, addMode, compression, ratio, newPosition) \
   VMETHOD(CO(ArchiveDir), ArchiveDir, addFromFile, __i, C(bool), \
      C(ArchiveDir) _ARG const char * _ARG C(File) _ARG C(FileStats) * _ARG C(ArchiveAddMode) _ARG int _ARG int * _ARG uint *, \
      __i _ARG name _ARG input _ARG stats _ARG addMode _ARG compression _ARG ratio _ARG newPosition)
extern C(Method) * METHOD(ArchiveDir, addFromFile);
extern int M_VTBLID(ArchiveDir, addFromFileAtPosition);
#define ArchiveDir_addFromFileAtPosition(__i, position, name, input, stats, addMode, compression, ratio, newPosition) \
   VMETHOD(CO(ArchiveDir), ArchiveDir, addFromFileAtPosition, __i, C(bool), \
      C(ArchiveDir) _ARG uint _ARG const char * _ARG C(File) _ARG C(FileStats) * _ARG C(ArchiveAddMode) _ARG int _ARG int * _ARG uint *, \
      __i _ARG position _ARG name _ARG input _ARG stats _ARG addMode _ARG compression _ARG ratio _ARG newPosition)
extern C(Method) * METHOD(ArchiveDir, addFromFileAtPosition);
extern int M_VTBLID(ArchiveDir, delete);
#define ArchiveDir_delete(__i, fileName) \
   VMETHOD(CO(ArchiveDir), ArchiveDir, delete, __i, C(bool), \
      C(ArchiveDir) _ARG const char *, \
      __i _ARG fileName)
extern C(Method) * METHOD(ArchiveDir, delete);
extern int M_VTBLID(ArchiveDir, fileExists);
#define ArchiveDir_fileExists(__i, fileName) \
   VMETHOD(CO(ArchiveDir), ArchiveDir, fileExists, __i, C(FileAttribs), \
      C(ArchiveDir) _ARG const char *, \
      __i _ARG fileName)
extern C(Method) * METHOD(ArchiveDir, fileExists);
extern int M_VTBLID(ArchiveDir, fileOpen);
#define ArchiveDir_fileOpen(__i, fileName) \
   VMETHOD(CO(ArchiveDir), ArchiveDir, fileOpen, __i, C(File), \
      C(ArchiveDir) _ARG const char *, \
      __i _ARG fileName)
extern C(Method) * METHOD(ArchiveDir, fileOpen);
extern int M_VTBLID(ArchiveDir, move);
#define ArchiveDir_move(__i, name, to) \
   VMETHOD(CO(ArchiveDir), ArchiveDir, move, __i, C(bool), \
      C(ArchiveDir) _ARG const char * _ARG C(ArchiveDir), \
      __i _ARG name _ARG to)
extern C(Method) * METHOD(ArchiveDir, move);
extern int M_VTBLID(ArchiveDir, openDirectory);
#define ArchiveDir_openDirectory(__i, name, stats, addMode) \
   VMETHOD(CO(ArchiveDir), ArchiveDir, openDirectory, __i, C(ArchiveDir), \
      C(ArchiveDir) _ARG const char * _ARG C(FileStats) * _ARG C(ArchiveAddMode), \
      __i _ARG name _ARG stats _ARG addMode)
extern C(Method) * METHOD(ArchiveDir, openDirectory);
extern int M_VTBLID(ArchiveDir, rename);
#define ArchiveDir_rename(__i, name, newName) \
   VMETHOD(CO(ArchiveDir), ArchiveDir, rename, __i, C(bool), \
      C(ArchiveDir) _ARG const char * _ARG const char *, \
      __i _ARG name _ARG newName)
extern C(Method) * METHOD(ArchiveDir, rename);
#define ARCHIVEOPENFLAGS_writeAccess_SHIFT               0
#define ARCHIVEOPENFLAGS_writeAccess_MASK                0x1
#define ARCHIVEOPENFLAGS_writeAccess(x)                  ((((ArchiveOpenFlags)(x)) & ARCHIVEOPENFLAGS_writeAccess_MASK) >> ARCHIVEOPENFLAGS_writeAccess_SHIFT)
#define ARCHIVEOPENFLAGS_SET_writeAccess(x, writeAccess)           (x) = ((ArchiveOpenFlags)(x) & ~((ArchiveOpenFlags)ARCHIVEOPENFLAGS_writeAccess_MASK)) | (((ArchiveOpenFlags)(writeAccess)) << ARCHIVEOPENFLAGS_writeAccess_SHIFT)
#define ARCHIVEOPENFLAGS_buffered_SHIFT                  1
#define ARCHIVEOPENFLAGS_buffered_MASK                   0x2
#define ARCHIVEOPENFLAGS_buffered(x)                     ((((ArchiveOpenFlags)(x)) & ARCHIVEOPENFLAGS_buffered_MASK) >> ARCHIVEOPENFLAGS_buffered_SHIFT)
#define ARCHIVEOPENFLAGS_SET_buffered(x, buffered)              (x) = ((ArchiveOpenFlags)(x) & ~((ArchiveOpenFlags)ARCHIVEOPENFLAGS_buffered_MASK)) | (((ArchiveOpenFlags)(buffered)) << ARCHIVEOPENFLAGS_buffered_SHIFT)
#define ARCHIVEOPENFLAGS_exclusive_SHIFT                 2
#define ARCHIVEOPENFLAGS_exclusive_MASK                  0x4
#define ARCHIVEOPENFLAGS_exclusive(x)                    ((((ArchiveOpenFlags)(x)) & ARCHIVEOPENFLAGS_exclusive_MASK) >> ARCHIVEOPENFLAGS_exclusive_SHIFT)
#define ARCHIVEOPENFLAGS_SET_exclusive(x, exclusive)             (x) = ((ArchiveOpenFlags)(x) & ~((ArchiveOpenFlags)ARCHIVEOPENFLAGS_exclusive_MASK)) | (((ArchiveOpenFlags)(exclusive)) << ARCHIVEOPENFLAGS_exclusive_SHIFT)
#define ARCHIVEOPENFLAGS_waitLock_SHIFT                  3
#define ARCHIVEOPENFLAGS_waitLock_MASK                   0x8
#define ARCHIVEOPENFLAGS_waitLock(x)                     ((((ArchiveOpenFlags)(x)) & ARCHIVEOPENFLAGS_waitLock_MASK) >> ARCHIVEOPENFLAGS_waitLock_SHIFT)
#define ARCHIVEOPENFLAGS_SET_waitLock(x, waitLock)              (x) = ((ArchiveOpenFlags)(x) & ~((ArchiveOpenFlags)ARCHIVEOPENFLAGS_waitLock_MASK)) | (((ArchiveOpenFlags)(waitLock)) << ARCHIVEOPENFLAGS_waitLock_SHIFT)
#define ARCHIVEOPENFLAGS(writeAccess, buffered, exclusive, waitLock)                      ((((((ArchiveOpenFlags)(writeAccess)) << ARCHIVEOPENFLAGS_writeAccess_SHIFT) | ((ArchiveOpenFlags)(buffered)) << ARCHIVEOPENFLAGS_buffered_SHIFT) | ((ArchiveOpenFlags)(exclusive)) << ARCHIVEOPENFLAGS_exclusive_SHIFT) | ((ArchiveOpenFlags)(waitLock)) << ARCHIVEOPENFLAGS_waitLock_SHIFT)


struct C(Box)
{
   int left;
   int top;
   int right;
   int bottom;
};
extern void (* Box_clip)(C(Box) * __this, C(Box) * against);

extern void (* Box_clipOffset)(C(Box) * __this, C(Box) * against, int x, int y);

extern C(bool) (* Box_isPointInside)(C(Box) * __this, C(Point) * point);

extern C(bool) (* Box_overlap)(C(Box) * __this, C(Box) * box);

extern C(Property) * PROPERTY(Box, width);
extern void (* Box_set_width)(C(Box) b, int value);
extern int (* Box_get_width)(C(Box) b);

extern C(Property) * PROPERTY(Box, height);
extern void (* Box_set_height)(C(Box) b, int value);
extern int (* Box_get_height)(C(Box) b);

extern C(Property) * PROPERTY(BufferedFile, handle);
extern void (* BufferedFile_set_handle)(C(BufferedFile) b, C(File) value);
extern C(File) (* BufferedFile_get_handle)(C(BufferedFile) b);

extern C(Property) * PROPERTY(BufferedFile, bufferSize);
extern void (* BufferedFile_set_bufferSize)(C(BufferedFile) b, uint value);
extern uint (* BufferedFile_get_bufferSize)(C(BufferedFile) b);

extern C(Property) * PROPERTY(BufferedFile, bufferRead);
extern void (* BufferedFile_set_bufferRead)(C(BufferedFile) b, uint value);
extern uint (* BufferedFile_get_bufferRead)(C(BufferedFile) b);

extern C(Property) * PROPERTY(Centimeters, Meters);
extern double (* Centimeters_from_Meters)(C(Distance) meters);
extern C(Distance) (* Centimeters_to_Meters)(double centimeters);
#define Centimeters(x)  ((C(Distance))((x) * 0.01))
#define Distance_in_Centimeters(x)  ((double)((x) * 100))

#define CHARCATEGORIES_none_SHIFT                        0
#define CHARCATEGORIES_none_MASK                         0x1
#define CHARCATEGORIES_none(x)                           ((((CharCategories)(x)) & CHARCATEGORIES_none_MASK) >> CHARCATEGORIES_none_SHIFT)
#define CHARCATEGORIES_SET_none(x, none)                    (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_none_MASK)) | (((CharCategories)(none)) << CHARCATEGORIES_none_SHIFT)
#define CHARCATEGORIES_markNonSpacing_SHIFT              1
#define CHARCATEGORIES_markNonSpacing_MASK               0x2
#define CHARCATEGORIES_markNonSpacing(x)                 ((((CharCategories)(x)) & CHARCATEGORIES_markNonSpacing_MASK) >> CHARCATEGORIES_markNonSpacing_SHIFT)
#define CHARCATEGORIES_SET_markNonSpacing(x, markNonSpacing)          (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_markNonSpacing_MASK)) | (((CharCategories)(markNonSpacing)) << CHARCATEGORIES_markNonSpacing_SHIFT)
#define CHARCATEGORIES_markSpacing_SHIFT                 2
#define CHARCATEGORIES_markSpacing_MASK                  0x4
#define CHARCATEGORIES_markSpacing(x)                    ((((CharCategories)(x)) & CHARCATEGORIES_markSpacing_MASK) >> CHARCATEGORIES_markSpacing_SHIFT)
#define CHARCATEGORIES_SET_markSpacing(x, markSpacing)             (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_markSpacing_MASK)) | (((CharCategories)(markSpacing)) << CHARCATEGORIES_markSpacing_SHIFT)
#define CHARCATEGORIES_markEnclosing_SHIFT               3
#define CHARCATEGORIES_markEnclosing_MASK                0x8
#define CHARCATEGORIES_markEnclosing(x)                  ((((CharCategories)(x)) & CHARCATEGORIES_markEnclosing_MASK) >> CHARCATEGORIES_markEnclosing_SHIFT)
#define CHARCATEGORIES_SET_markEnclosing(x, markEnclosing)           (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_markEnclosing_MASK)) | (((CharCategories)(markEnclosing)) << CHARCATEGORIES_markEnclosing_SHIFT)
#define CHARCATEGORIES_numberDecimalDigit_SHIFT          4
#define CHARCATEGORIES_numberDecimalDigit_MASK           0x10
#define CHARCATEGORIES_numberDecimalDigit(x)             ((((CharCategories)(x)) & CHARCATEGORIES_numberDecimalDigit_MASK) >> CHARCATEGORIES_numberDecimalDigit_SHIFT)
#define CHARCATEGORIES_SET_numberDecimalDigit(x, numberDecimalDigit)      (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_numberDecimalDigit_MASK)) | (((CharCategories)(numberDecimalDigit)) << CHARCATEGORIES_numberDecimalDigit_SHIFT)
#define CHARCATEGORIES_numberLetter_SHIFT                5
#define CHARCATEGORIES_numberLetter_MASK                 0x20
#define CHARCATEGORIES_numberLetter(x)                   ((((CharCategories)(x)) & CHARCATEGORIES_numberLetter_MASK) >> CHARCATEGORIES_numberLetter_SHIFT)
#define CHARCATEGORIES_SET_numberLetter(x, numberLetter)            (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_numberLetter_MASK)) | (((CharCategories)(numberLetter)) << CHARCATEGORIES_numberLetter_SHIFT)
#define CHARCATEGORIES_numberOther_SHIFT                 6
#define CHARCATEGORIES_numberOther_MASK                  0x40
#define CHARCATEGORIES_numberOther(x)                    ((((CharCategories)(x)) & CHARCATEGORIES_numberOther_MASK) >> CHARCATEGORIES_numberOther_SHIFT)
#define CHARCATEGORIES_SET_numberOther(x, numberOther)             (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_numberOther_MASK)) | (((CharCategories)(numberOther)) << CHARCATEGORIES_numberOther_SHIFT)
#define CHARCATEGORIES_separatorSpace_SHIFT              7
#define CHARCATEGORIES_separatorSpace_MASK               0x80
#define CHARCATEGORIES_separatorSpace(x)                 ((((CharCategories)(x)) & CHARCATEGORIES_separatorSpace_MASK) >> CHARCATEGORIES_separatorSpace_SHIFT)
#define CHARCATEGORIES_SET_separatorSpace(x, separatorSpace)          (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_separatorSpace_MASK)) | (((CharCategories)(separatorSpace)) << CHARCATEGORIES_separatorSpace_SHIFT)
#define CHARCATEGORIES_separatorLine_SHIFT               8
#define CHARCATEGORIES_separatorLine_MASK                0x100
#define CHARCATEGORIES_separatorLine(x)                  ((((CharCategories)(x)) & CHARCATEGORIES_separatorLine_MASK) >> CHARCATEGORIES_separatorLine_SHIFT)
#define CHARCATEGORIES_SET_separatorLine(x, separatorLine)           (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_separatorLine_MASK)) | (((CharCategories)(separatorLine)) << CHARCATEGORIES_separatorLine_SHIFT)
#define CHARCATEGORIES_separatorParagraph_SHIFT          9
#define CHARCATEGORIES_separatorParagraph_MASK           0x200
#define CHARCATEGORIES_separatorParagraph(x)             ((((CharCategories)(x)) & CHARCATEGORIES_separatorParagraph_MASK) >> CHARCATEGORIES_separatorParagraph_SHIFT)
#define CHARCATEGORIES_SET_separatorParagraph(x, separatorParagraph)      (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_separatorParagraph_MASK)) | (((CharCategories)(separatorParagraph)) << CHARCATEGORIES_separatorParagraph_SHIFT)
#define CHARCATEGORIES_otherControl_SHIFT                10
#define CHARCATEGORIES_otherControl_MASK                 0x400
#define CHARCATEGORIES_otherControl(x)                   ((((CharCategories)(x)) & CHARCATEGORIES_otherControl_MASK) >> CHARCATEGORIES_otherControl_SHIFT)
#define CHARCATEGORIES_SET_otherControl(x, otherControl)            (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_otherControl_MASK)) | (((CharCategories)(otherControl)) << CHARCATEGORIES_otherControl_SHIFT)
#define CHARCATEGORIES_otherFormat_SHIFT                 11
#define CHARCATEGORIES_otherFormat_MASK                  0x800
#define CHARCATEGORIES_otherFormat(x)                    ((((CharCategories)(x)) & CHARCATEGORIES_otherFormat_MASK) >> CHARCATEGORIES_otherFormat_SHIFT)
#define CHARCATEGORIES_SET_otherFormat(x, otherFormat)             (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_otherFormat_MASK)) | (((CharCategories)(otherFormat)) << CHARCATEGORIES_otherFormat_SHIFT)
#define CHARCATEGORIES_otherSurrogate_SHIFT              12
#define CHARCATEGORIES_otherSurrogate_MASK               0x1000
#define CHARCATEGORIES_otherSurrogate(x)                 ((((CharCategories)(x)) & CHARCATEGORIES_otherSurrogate_MASK) >> CHARCATEGORIES_otherSurrogate_SHIFT)
#define CHARCATEGORIES_SET_otherSurrogate(x, otherSurrogate)          (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_otherSurrogate_MASK)) | (((CharCategories)(otherSurrogate)) << CHARCATEGORIES_otherSurrogate_SHIFT)
#define CHARCATEGORIES_otherPrivateUse_SHIFT             13
#define CHARCATEGORIES_otherPrivateUse_MASK              0x2000
#define CHARCATEGORIES_otherPrivateUse(x)                ((((CharCategories)(x)) & CHARCATEGORIES_otherPrivateUse_MASK) >> CHARCATEGORIES_otherPrivateUse_SHIFT)
#define CHARCATEGORIES_SET_otherPrivateUse(x, otherPrivateUse)         (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_otherPrivateUse_MASK)) | (((CharCategories)(otherPrivateUse)) << CHARCATEGORIES_otherPrivateUse_SHIFT)
#define CHARCATEGORIES_otherNotAssigned_SHIFT            14
#define CHARCATEGORIES_otherNotAssigned_MASK             0x4000
#define CHARCATEGORIES_otherNotAssigned(x)               ((((CharCategories)(x)) & CHARCATEGORIES_otherNotAssigned_MASK) >> CHARCATEGORIES_otherNotAssigned_SHIFT)
#define CHARCATEGORIES_SET_otherNotAssigned(x, otherNotAssigned)        (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_otherNotAssigned_MASK)) | (((CharCategories)(otherNotAssigned)) << CHARCATEGORIES_otherNotAssigned_SHIFT)
#define CHARCATEGORIES_letterUpperCase_SHIFT             15
#define CHARCATEGORIES_letterUpperCase_MASK              0x8000
#define CHARCATEGORIES_letterUpperCase(x)                ((((CharCategories)(x)) & CHARCATEGORIES_letterUpperCase_MASK) >> CHARCATEGORIES_letterUpperCase_SHIFT)
#define CHARCATEGORIES_SET_letterUpperCase(x, letterUpperCase)         (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_letterUpperCase_MASK)) | (((CharCategories)(letterUpperCase)) << CHARCATEGORIES_letterUpperCase_SHIFT)
#define CHARCATEGORIES_letterLowerCase_SHIFT             16
#define CHARCATEGORIES_letterLowerCase_MASK              0x10000
#define CHARCATEGORIES_letterLowerCase(x)                ((((CharCategories)(x)) & CHARCATEGORIES_letterLowerCase_MASK) >> CHARCATEGORIES_letterLowerCase_SHIFT)
#define CHARCATEGORIES_SET_letterLowerCase(x, letterLowerCase)         (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_letterLowerCase_MASK)) | (((CharCategories)(letterLowerCase)) << CHARCATEGORIES_letterLowerCase_SHIFT)
#define CHARCATEGORIES_letterTitleCase_SHIFT             17
#define CHARCATEGORIES_letterTitleCase_MASK              0x20000
#define CHARCATEGORIES_letterTitleCase(x)                ((((CharCategories)(x)) & CHARCATEGORIES_letterTitleCase_MASK) >> CHARCATEGORIES_letterTitleCase_SHIFT)
#define CHARCATEGORIES_SET_letterTitleCase(x, letterTitleCase)         (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_letterTitleCase_MASK)) | (((CharCategories)(letterTitleCase)) << CHARCATEGORIES_letterTitleCase_SHIFT)
#define CHARCATEGORIES_letterModifier_SHIFT              18
#define CHARCATEGORIES_letterModifier_MASK               0x40000
#define CHARCATEGORIES_letterModifier(x)                 ((((CharCategories)(x)) & CHARCATEGORIES_letterModifier_MASK) >> CHARCATEGORIES_letterModifier_SHIFT)
#define CHARCATEGORIES_SET_letterModifier(x, letterModifier)          (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_letterModifier_MASK)) | (((CharCategories)(letterModifier)) << CHARCATEGORIES_letterModifier_SHIFT)
#define CHARCATEGORIES_letterOther_SHIFT                 19
#define CHARCATEGORIES_letterOther_MASK                  0x80000
#define CHARCATEGORIES_letterOther(x)                    ((((CharCategories)(x)) & CHARCATEGORIES_letterOther_MASK) >> CHARCATEGORIES_letterOther_SHIFT)
#define CHARCATEGORIES_SET_letterOther(x, letterOther)             (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_letterOther_MASK)) | (((CharCategories)(letterOther)) << CHARCATEGORIES_letterOther_SHIFT)
#define CHARCATEGORIES_punctuationConnector_SHIFT        20
#define CHARCATEGORIES_punctuationConnector_MASK         0x100000
#define CHARCATEGORIES_punctuationConnector(x)           ((((CharCategories)(x)) & CHARCATEGORIES_punctuationConnector_MASK) >> CHARCATEGORIES_punctuationConnector_SHIFT)
#define CHARCATEGORIES_SET_punctuationConnector(x, punctuationConnector)    (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_punctuationConnector_MASK)) | (((CharCategories)(punctuationConnector)) << CHARCATEGORIES_punctuationConnector_SHIFT)
#define CHARCATEGORIES_punctuationDash_SHIFT             21
#define CHARCATEGORIES_punctuationDash_MASK              0x200000
#define CHARCATEGORIES_punctuationDash(x)                ((((CharCategories)(x)) & CHARCATEGORIES_punctuationDash_MASK) >> CHARCATEGORIES_punctuationDash_SHIFT)
#define CHARCATEGORIES_SET_punctuationDash(x, punctuationDash)         (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_punctuationDash_MASK)) | (((CharCategories)(punctuationDash)) << CHARCATEGORIES_punctuationDash_SHIFT)
#define CHARCATEGORIES_punctuationOpen_SHIFT             22
#define CHARCATEGORIES_punctuationOpen_MASK              0x400000
#define CHARCATEGORIES_punctuationOpen(x)                ((((CharCategories)(x)) & CHARCATEGORIES_punctuationOpen_MASK) >> CHARCATEGORIES_punctuationOpen_SHIFT)
#define CHARCATEGORIES_SET_punctuationOpen(x, punctuationOpen)         (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_punctuationOpen_MASK)) | (((CharCategories)(punctuationOpen)) << CHARCATEGORIES_punctuationOpen_SHIFT)
#define CHARCATEGORIES_punctuationClose_SHIFT            23
#define CHARCATEGORIES_punctuationClose_MASK             0x800000
#define CHARCATEGORIES_punctuationClose(x)               ((((CharCategories)(x)) & CHARCATEGORIES_punctuationClose_MASK) >> CHARCATEGORIES_punctuationClose_SHIFT)
#define CHARCATEGORIES_SET_punctuationClose(x, punctuationClose)        (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_punctuationClose_MASK)) | (((CharCategories)(punctuationClose)) << CHARCATEGORIES_punctuationClose_SHIFT)
#define CHARCATEGORIES_punctuationInitial_SHIFT          24
#define CHARCATEGORIES_punctuationInitial_MASK           0x1000000
#define CHARCATEGORIES_punctuationInitial(x)             ((((CharCategories)(x)) & CHARCATEGORIES_punctuationInitial_MASK) >> CHARCATEGORIES_punctuationInitial_SHIFT)
#define CHARCATEGORIES_SET_punctuationInitial(x, punctuationInitial)      (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_punctuationInitial_MASK)) | (((CharCategories)(punctuationInitial)) << CHARCATEGORIES_punctuationInitial_SHIFT)
#define CHARCATEGORIES_punctuationFinal_SHIFT            25
#define CHARCATEGORIES_punctuationFinal_MASK             0x2000000
#define CHARCATEGORIES_punctuationFinal(x)               ((((CharCategories)(x)) & CHARCATEGORIES_punctuationFinal_MASK) >> CHARCATEGORIES_punctuationFinal_SHIFT)
#define CHARCATEGORIES_SET_punctuationFinal(x, punctuationFinal)        (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_punctuationFinal_MASK)) | (((CharCategories)(punctuationFinal)) << CHARCATEGORIES_punctuationFinal_SHIFT)
#define CHARCATEGORIES_punctuationOther_SHIFT            26
#define CHARCATEGORIES_punctuationOther_MASK             0x4000000
#define CHARCATEGORIES_punctuationOther(x)               ((((CharCategories)(x)) & CHARCATEGORIES_punctuationOther_MASK) >> CHARCATEGORIES_punctuationOther_SHIFT)
#define CHARCATEGORIES_SET_punctuationOther(x, punctuationOther)        (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_punctuationOther_MASK)) | (((CharCategories)(punctuationOther)) << CHARCATEGORIES_punctuationOther_SHIFT)
#define CHARCATEGORIES_symbolMath_SHIFT                  27
#define CHARCATEGORIES_symbolMath_MASK                   0x8000000
#define CHARCATEGORIES_symbolMath(x)                     ((((CharCategories)(x)) & CHARCATEGORIES_symbolMath_MASK) >> CHARCATEGORIES_symbolMath_SHIFT)
#define CHARCATEGORIES_SET_symbolMath(x, symbolMath)              (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_symbolMath_MASK)) | (((CharCategories)(symbolMath)) << CHARCATEGORIES_symbolMath_SHIFT)
#define CHARCATEGORIES_symbolCurrency_SHIFT              28
#define CHARCATEGORIES_symbolCurrency_MASK               0x10000000
#define CHARCATEGORIES_symbolCurrency(x)                 ((((CharCategories)(x)) & CHARCATEGORIES_symbolCurrency_MASK) >> CHARCATEGORIES_symbolCurrency_SHIFT)
#define CHARCATEGORIES_SET_symbolCurrency(x, symbolCurrency)          (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_symbolCurrency_MASK)) | (((CharCategories)(symbolCurrency)) << CHARCATEGORIES_symbolCurrency_SHIFT)
#define CHARCATEGORIES_symbolModifier_SHIFT              29
#define CHARCATEGORIES_symbolModifier_MASK               0x20000000
#define CHARCATEGORIES_symbolModifier(x)                 ((((CharCategories)(x)) & CHARCATEGORIES_symbolModifier_MASK) >> CHARCATEGORIES_symbolModifier_SHIFT)
#define CHARCATEGORIES_SET_symbolModifier(x, symbolModifier)          (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_symbolModifier_MASK)) | (((CharCategories)(symbolModifier)) << CHARCATEGORIES_symbolModifier_SHIFT)
#define CHARCATEGORIES_symbolOther_SHIFT                 30
#define CHARCATEGORIES_symbolOther_MASK                  0x40000000
#define CHARCATEGORIES_symbolOther(x)                    ((((CharCategories)(x)) & CHARCATEGORIES_symbolOther_MASK) >> CHARCATEGORIES_symbolOther_SHIFT)
#define CHARCATEGORIES_SET_symbolOther(x, symbolOther)             (x) = ((CharCategories)(x) & ~((CharCategories)CHARCATEGORIES_symbolOther_MASK)) | (((CharCategories)(symbolOther)) << CHARCATEGORIES_symbolOther_SHIFT)


extern void (* Condition_signal)(C(Condition) * __this);

extern void (* Condition_wait)(C(Condition) * __this, C(Mutex) * mutex);

extern C(Property) * PROPERTY(Condition, name);
extern void (* Condition_set_name)(C(Condition) * c, const char * value);
extern const char * (* Condition_get_name)(C(Condition) * c);

struct C(Date)
{
   int year;
   C(Month) month;
   int day;
};
extern const char * (* Date_onGetStringEn)(C(Date) * __this, char * stringOutput, void * fieldData, C(bool) * needClass);

extern C(Property) * PROPERTY(Date, dayOfTheWeek);
extern C(DayOfTheWeek) (* Date_get_dayOfTheWeek)(C(Date) d);

struct C(DateTime)
{
   int year;
   C(Month) month;
   int day;
   int hour;
   int minute;
   int second;
   C(DayOfTheWeek) dayOfTheWeek;
   int dayInTheYear;
};
extern C(bool) (* DateTime_fixDayOfYear)(C(DateTime) * __this);

extern C(bool) (* DateTime_getLocalTime)(C(DateTime) * __this);

extern C(Property) * PROPERTY(DateTime, SecSince1970);
extern void (* DateTime_from_SecSince1970)(C(DateTime) d, C(SecSince1970) value);
extern C(SecSince1970) (* DateTime_to_SecSince1970)(C(DateTime) d);

extern C(Property) * PROPERTY(DateTime, Date);
extern void (* DateTime_from_Date)(C(DateTime) d, const C(Date) * value);
extern void (* DateTime_to_Date)(C(DateTime) d, C(Date) * value);

extern C(Property) * PROPERTY(DateTime, global);
extern void (* DateTime_set_global)(C(DateTime) d, const C(DateTime) * value);
extern void (* DateTime_get_global)(C(DateTime) d, C(DateTime) * value);

extern C(Property) * PROPERTY(DateTime, local);
extern void (* DateTime_set_local)(C(DateTime) d, const C(DateTime) * value);
extern void (* DateTime_get_local)(C(DateTime) d, C(DateTime) * value);

extern C(Property) * PROPERTY(DateTime, daysSince1970);
extern int64 (* DateTime_get_daysSince1970)(C(DateTime) d);

extern C(Property) * PROPERTY(Degrees, Radians);
extern double (* Degrees_from_Radians)(C(Angle) radians);
extern C(Angle) (* Degrees_to_Radians)(double degrees);
#define Degrees(x)  ((C(Angle))((x) * 0.0174532925199433))
#define Angle_in_Degrees(x)  ((double)((x) * 57.2957795130823))

extern int (* DualPipe_getExitCode)(C(DualPipe) __this);

extern C(bool) (* DualPipe_getLinePeek)(C(DualPipe) __this, char * s, int max, int * charsRead);

extern int (* DualPipe_getProcessID)(C(DualPipe) __this);

extern C(bool) (* DualPipe_peek)(C(DualPipe) __this);

extern void (* DualPipe_terminate)(C(DualPipe) __this);

extern void (* DualPipe_wait)(C(DualPipe) __this);

#define ERRORCODE_level_SHIFT                            12
#define ERRORCODE_level_MASK                             0x3000
#define ERRORCODE_level(x)                               ((((ErrorCode)(x)) & ERRORCODE_level_MASK) >> ERRORCODE_level_SHIFT)
#define ERRORCODE_SET_level(x, level)                        (x) = ((ErrorCode)(x) & ~((ErrorCode)ERRORCODE_level_MASK)) | (((ErrorCode)(level)) << ERRORCODE_level_SHIFT)
#define ERRORCODE_code_SHIFT                             0
#define ERRORCODE_code_MASK                              0xFFF
#define ERRORCODE_code(x)                                ((((ErrorCode)(x)) & ERRORCODE_code_MASK) >> ERRORCODE_code_SHIFT)
#define ERRORCODE_SET_code(x, code)                         (x) = ((ErrorCode)(x) & ~((ErrorCode)ERRORCODE_code_MASK)) | (((ErrorCode)(code)) << ERRORCODE_code_SHIFT)
#define ERRORCODE(level, code)                                 ((((ErrorCode)(level)) << ERRORCODE_level_SHIFT) | ((ErrorCode)(code)) << ERRORCODE_code_SHIFT)


extern C(Property) * PROPERTY(Feet, Meters);
extern double (* Feet_from_Meters)(C(Distance) meters);
extern C(Distance) (* Feet_to_Meters)(double feet);
#define Feet(x)  ((C(Distance))((x) * 0.304800003767014))
#define Distance_in_Feet(x)  ((double)((x) * 3.28083985446533))

extern int M_VTBLID(File, close);
#define File_close(__i) \
   VMETHOD(CO(File), File, close, __i, void, \
      C(File), \
      __i)
extern C(Method) * METHOD(File, close);
extern int M_VTBLID(File, closeInput);
#define File_closeInput(__i) \
   VMETHOD(CO(File), File, closeInput, __i, void, \
      C(File), \
      __i)
extern C(Method) * METHOD(File, closeInput);
extern int M_VTBLID(File, closeOutput);
#define File_closeOutput(__i) \
   VMETHOD(CO(File), File, closeOutput, __i, void, \
      C(File), \
      __i)
extern C(Method) * METHOD(File, closeOutput);
extern C(bool) (* File_copyTo)(C(File) __this, const char * outputFileName);

extern int M_VTBLID(File, eof);
#define File_eof(__i) \
   VMETHOD(CO(File), File, eof, __i, C(bool), \
      C(File), \
      __i)
extern C(Method) * METHOD(File, eof);
extern C(bool) (* File_flush)(C(File) __this);

extern double (* File_getDouble)(C(File) __this);

extern float (* File_getFloat)(C(File) __this);

extern uint (* File_getHexValue)(C(File) __this);

extern C(bool) (* File_getLine)(C(File) __this, char * s, int max);

extern int (* File_getLineEx)(C(File) __this, char * s, int max, C(bool) * hasNewLineChar);

extern int M_VTBLID(File, getSize);
#define File_getSize(__i) \
   VMETHOD(CO(File), File, getSize, __i, uint, \
      C(File), \
      __i)
extern C(Method) * METHOD(File, getSize);
extern C(bool) (* File_getString)(C(File) __this, char * string, int max);

extern int (* File_getValue)(C(File) __this);

extern int M_VTBLID(File, getc);
#define File_getc(__i, ch) \
   VMETHOD(CO(File), File, getc, __i, C(bool), \
      C(File) _ARG char *, \
      __i _ARG ch)
extern C(Method) * METHOD(File, getc);
extern int M_VTBLID(File, lock);
#define File_lock(__i, type, start, length, wait) \
   VMETHOD(CO(File), File, lock, __i, C(bool), \
      C(File) _ARG C(FileLock) _ARG uint64 _ARG uint64 _ARG C(bool), \
      __i _ARG type _ARG start _ARG length _ARG wait)
extern C(Method) * METHOD(File, lock);
extern void (* File_print)(C(File) __this, C(Class) * class_object, void * object, ...);

extern void (* File_printLn)(C(File) __this, C(Class) * class_object, void * object, ...);

extern int (* File_printf)(C(File) __this, const char * format, ...);

extern int M_VTBLID(File, putc);
#define File_putc(__i, ch) \
   VMETHOD(CO(File), File, putc, __i, C(bool), \
      C(File) _ARG char, \
      __i _ARG ch)
extern C(Method) * METHOD(File, putc);
extern int M_VTBLID(File, puts);
#define File_puts(__i, string) \
   VMETHOD(CO(File), File, puts, __i, C(bool), \
      C(File) _ARG const char *, \
      __i _ARG string)
extern C(Method) * METHOD(File, puts);
extern int M_VTBLID(File, read);
#define File_read(__i, buffer, size, count) \
   VMETHOD(CO(File), File, read, __i, int, \
      C(File) _ARG void * _ARG uint _ARG uint, \
      __i _ARG buffer _ARG size _ARG count)
extern C(Method) * METHOD(File, read);
extern int M_VTBLID(File, seek);
#define File_seek(__i, pos, mode) \
   VMETHOD(CO(File), File, seek, __i, C(bool), \
      C(File) _ARG int _ARG C(FileSeekMode), \
      __i _ARG pos _ARG mode)
extern C(Method) * METHOD(File, seek);
extern int M_VTBLID(File, seek64);
#define File_seek64(__i, pos, mode) \
   VMETHOD(CO(File), File, seek64, __i, C(bool), \
      C(File) _ARG int64 _ARG C(FileSeekMode), \
      __i _ARG pos _ARG mode)
extern C(Method) * METHOD(File, seek64);
extern int M_VTBLID(File, tell);
#define File_tell(__i) \
   VMETHOD(CO(File), File, tell, __i, uint, \
      C(File), \
      __i)
extern C(Method) * METHOD(File, tell);
extern int M_VTBLID(File, truncate);
#define File_truncate(__i, size) \
   VMETHOD(CO(File), File, truncate, __i, C(bool), \
      C(File) _ARG C(FileSize), \
      __i _ARG size)
extern C(Method) * METHOD(File, truncate);
extern int M_VTBLID(File, unlock);
#define File_unlock(__i, start, length, wait) \
   VMETHOD(CO(File), File, unlock, __i, C(bool), \
      C(File) _ARG uint64 _ARG uint64 _ARG C(bool), \
      __i _ARG start _ARG length _ARG wait)
extern C(Method) * METHOD(File, unlock);
extern int M_VTBLID(File, write);
#define File_write(__i, buffer, size, count) \
   VMETHOD(CO(File), File, write, __i, int, \
      C(File) _ARG const void * _ARG uint _ARG uint, \
      __i _ARG buffer _ARG size _ARG count)
extern C(Method) * METHOD(File, write);
extern C(Property) * PROPERTY(File, input);
extern void (* File_set_input)(C(File) f, void * value);
extern void * (* File_get_input)(C(File) f);

extern C(Property) * PROPERTY(File, output);
extern void (* File_set_output)(C(File) f, void * value);
extern void * (* File_get_output)(C(File) f);

extern C(Property) * PROPERTY(File, buffered);
extern void (* File_set_buffered)(C(File) f, C(bool) value);

extern C(Property) * PROPERTY(File, eof);
extern C(bool) (* File_get_eof)(C(File) f);

#define FILEATTRIBS_isFile_SHIFT                         0
#define FILEATTRIBS_isFile_MASK                          0x1
#define FILEATTRIBS_isFile(x)                            ((((FileAttribs)(x)) & FILEATTRIBS_isFile_MASK) >> FILEATTRIBS_isFile_SHIFT)
#define FILEATTRIBS_SET_isFile(x, isFile)                     (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isFile_MASK)) | (((FileAttribs)(isFile)) << FILEATTRIBS_isFile_SHIFT)
#define FILEATTRIBS_isArchive_SHIFT                      1
#define FILEATTRIBS_isArchive_MASK                       0x2
#define FILEATTRIBS_isArchive(x)                         ((((FileAttribs)(x)) & FILEATTRIBS_isArchive_MASK) >> FILEATTRIBS_isArchive_SHIFT)
#define FILEATTRIBS_SET_isArchive(x, isArchive)                  (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isArchive_MASK)) | (((FileAttribs)(isArchive)) << FILEATTRIBS_isArchive_SHIFT)
#define FILEATTRIBS_isHidden_SHIFT                       2
#define FILEATTRIBS_isHidden_MASK                        0x4
#define FILEATTRIBS_isHidden(x)                          ((((FileAttribs)(x)) & FILEATTRIBS_isHidden_MASK) >> FILEATTRIBS_isHidden_SHIFT)
#define FILEATTRIBS_SET_isHidden(x, isHidden)                   (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isHidden_MASK)) | (((FileAttribs)(isHidden)) << FILEATTRIBS_isHidden_SHIFT)
#define FILEATTRIBS_isReadOnly_SHIFT                     3
#define FILEATTRIBS_isReadOnly_MASK                      0x8
#define FILEATTRIBS_isReadOnly(x)                        ((((FileAttribs)(x)) & FILEATTRIBS_isReadOnly_MASK) >> FILEATTRIBS_isReadOnly_SHIFT)
#define FILEATTRIBS_SET_isReadOnly(x, isReadOnly)                 (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isReadOnly_MASK)) | (((FileAttribs)(isReadOnly)) << FILEATTRIBS_isReadOnly_SHIFT)
#define FILEATTRIBS_isSystem_SHIFT                       4
#define FILEATTRIBS_isSystem_MASK                        0x10
#define FILEATTRIBS_isSystem(x)                          ((((FileAttribs)(x)) & FILEATTRIBS_isSystem_MASK) >> FILEATTRIBS_isSystem_SHIFT)
#define FILEATTRIBS_SET_isSystem(x, isSystem)                   (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isSystem_MASK)) | (((FileAttribs)(isSystem)) << FILEATTRIBS_isSystem_SHIFT)
#define FILEATTRIBS_isTemporary_SHIFT                    5
#define FILEATTRIBS_isTemporary_MASK                     0x20
#define FILEATTRIBS_isTemporary(x)                       ((((FileAttribs)(x)) & FILEATTRIBS_isTemporary_MASK) >> FILEATTRIBS_isTemporary_SHIFT)
#define FILEATTRIBS_SET_isTemporary(x, isTemporary)                (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isTemporary_MASK)) | (((FileAttribs)(isTemporary)) << FILEATTRIBS_isTemporary_SHIFT)
#define FILEATTRIBS_isDirectory_SHIFT                    6
#define FILEATTRIBS_isDirectory_MASK                     0x40
#define FILEATTRIBS_isDirectory(x)                       ((((FileAttribs)(x)) & FILEATTRIBS_isDirectory_MASK) >> FILEATTRIBS_isDirectory_SHIFT)
#define FILEATTRIBS_SET_isDirectory(x, isDirectory)                (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isDirectory_MASK)) | (((FileAttribs)(isDirectory)) << FILEATTRIBS_isDirectory_SHIFT)
#define FILEATTRIBS_isDrive_SHIFT                        7
#define FILEATTRIBS_isDrive_MASK                         0x80
#define FILEATTRIBS_isDrive(x)                           ((((FileAttribs)(x)) & FILEATTRIBS_isDrive_MASK) >> FILEATTRIBS_isDrive_SHIFT)
#define FILEATTRIBS_SET_isDrive(x, isDrive)                    (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isDrive_MASK)) | (((FileAttribs)(isDrive)) << FILEATTRIBS_isDrive_SHIFT)
#define FILEATTRIBS_isCDROM_SHIFT                        8
#define FILEATTRIBS_isCDROM_MASK                         0x100
#define FILEATTRIBS_isCDROM(x)                           ((((FileAttribs)(x)) & FILEATTRIBS_isCDROM_MASK) >> FILEATTRIBS_isCDROM_SHIFT)
#define FILEATTRIBS_SET_isCDROM(x, isCDROM)                    (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isCDROM_MASK)) | (((FileAttribs)(isCDROM)) << FILEATTRIBS_isCDROM_SHIFT)
#define FILEATTRIBS_isRemote_SHIFT                       9
#define FILEATTRIBS_isRemote_MASK                        0x200
#define FILEATTRIBS_isRemote(x)                          ((((FileAttribs)(x)) & FILEATTRIBS_isRemote_MASK) >> FILEATTRIBS_isRemote_SHIFT)
#define FILEATTRIBS_SET_isRemote(x, isRemote)                   (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isRemote_MASK)) | (((FileAttribs)(isRemote)) << FILEATTRIBS_isRemote_SHIFT)
#define FILEATTRIBS_isRemovable_SHIFT                    10
#define FILEATTRIBS_isRemovable_MASK                     0x400
#define FILEATTRIBS_isRemovable(x)                       ((((FileAttribs)(x)) & FILEATTRIBS_isRemovable_MASK) >> FILEATTRIBS_isRemovable_SHIFT)
#define FILEATTRIBS_SET_isRemovable(x, isRemovable)                (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isRemovable_MASK)) | (((FileAttribs)(isRemovable)) << FILEATTRIBS_isRemovable_SHIFT)
#define FILEATTRIBS_isServer_SHIFT                       11
#define FILEATTRIBS_isServer_MASK                        0x800
#define FILEATTRIBS_isServer(x)                          ((((FileAttribs)(x)) & FILEATTRIBS_isServer_MASK) >> FILEATTRIBS_isServer_SHIFT)
#define FILEATTRIBS_SET_isServer(x, isServer)                   (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isServer_MASK)) | (((FileAttribs)(isServer)) << FILEATTRIBS_isServer_SHIFT)
#define FILEATTRIBS_isShare_SHIFT                        12
#define FILEATTRIBS_isShare_MASK                         0x1000
#define FILEATTRIBS_isShare(x)                           ((((FileAttribs)(x)) & FILEATTRIBS_isShare_MASK) >> FILEATTRIBS_isShare_SHIFT)
#define FILEATTRIBS_SET_isShare(x, isShare)                    (x) = ((FileAttribs)(x) & ~((FileAttribs)FILEATTRIBS_isShare_MASK)) | (((FileAttribs)(isShare)) << FILEATTRIBS_isShare_SHIFT)


#define FILECHANGE_created_SHIFT                         0
#define FILECHANGE_created_MASK                          0x1
#define FILECHANGE_created(x)                            ((((FileChange)(x)) & FILECHANGE_created_MASK) >> FILECHANGE_created_SHIFT)
#define FILECHANGE_SET_created(x, created)                     (x) = ((FileChange)(x) & ~((FileChange)FILECHANGE_created_MASK)) | (((FileChange)(created)) << FILECHANGE_created_SHIFT)
#define FILECHANGE_renamed_SHIFT                         1
#define FILECHANGE_renamed_MASK                          0x2
#define FILECHANGE_renamed(x)                            ((((FileChange)(x)) & FILECHANGE_renamed_MASK) >> FILECHANGE_renamed_SHIFT)
#define FILECHANGE_SET_renamed(x, renamed)                     (x) = ((FileChange)(x) & ~((FileChange)FILECHANGE_renamed_MASK)) | (((FileChange)(renamed)) << FILECHANGE_renamed_SHIFT)
#define FILECHANGE_modified_SHIFT                        2
#define FILECHANGE_modified_MASK                         0x4
#define FILECHANGE_modified(x)                           ((((FileChange)(x)) & FILECHANGE_modified_MASK) >> FILECHANGE_modified_SHIFT)
#define FILECHANGE_SET_modified(x, modified)                    (x) = ((FileChange)(x) & ~((FileChange)FILECHANGE_modified_MASK)) | (((FileChange)(modified)) << FILECHANGE_modified_SHIFT)
#define FILECHANGE_deleted_SHIFT                         3
#define FILECHANGE_deleted_MASK                          0x8
#define FILECHANGE_deleted(x)                            ((((FileChange)(x)) & FILECHANGE_deleted_MASK) >> FILECHANGE_deleted_SHIFT)
#define FILECHANGE_SET_deleted(x, deleted)                     (x) = ((FileChange)(x) & ~((FileChange)FILECHANGE_deleted_MASK)) | (((FileChange)(deleted)) << FILECHANGE_deleted_SHIFT)
#define FILECHANGE_attribs_SHIFT                         4
#define FILECHANGE_attribs_MASK                          0x10
#define FILECHANGE_attribs(x)                            ((((FileChange)(x)) & FILECHANGE_attribs_MASK) >> FILECHANGE_attribs_SHIFT)
#define FILECHANGE_SET_attribs(x, attribs)                     (x) = ((FileChange)(x) & ~((FileChange)FILECHANGE_attribs_MASK)) | (((FileChange)(attribs)) << FILECHANGE_attribs_SHIFT)


struct C(FileListing)
{
   const char * directory;
   const char * extensions;
};
extern C(bool) (* FileListing_find)(C(FileListing) * __this);

extern void (* FileListing_stop)(C(FileListing) * __this);

extern C(Property) * PROPERTY(FileListing, name);
extern const char * (* FileListing_get_name)(C(FileListing) f);

extern C(Property) * PROPERTY(FileListing, path);
extern const char * (* FileListing_get_path)(C(FileListing) f);

extern C(Property) * PROPERTY(FileListing, stats);
extern void (* FileListing_get_stats)(C(FileListing) f, C(FileStats) * value);

extern int M_VTBLID(FileMonitor, onDirNotify);
#define FileMonitor_onDirNotify(__i, __t, action, fileName, param) \
   VMETHOD(CO(FileMonitor), FileMonitor, onDirNotify, __i, C(bool), \
      C(Class) * _ARG C(FileChange) _ARG const char * _ARG const char *, \
      __t _ARG action _ARG fileName _ARG param)
extern C(Method) * METHOD(FileMonitor, onDirNotify);
extern int M_VTBLID(FileMonitor, onFileNotify);
#define FileMonitor_onFileNotify(__i, __t, action, param) \
   VMETHOD(CO(FileMonitor), FileMonitor, onFileNotify, __i, C(bool), \
      C(Class) * _ARG C(FileChange) _ARG const char *, \
      __t _ARG action _ARG param)
extern C(Method) * METHOD(FileMonitor, onFileNotify);
extern void (* FileMonitor_startMonitoring)(C(FileMonitor) __this);

extern void (* FileMonitor_stopMonitoring)(C(FileMonitor) __this);

extern C(Property) * PROPERTY(FileMonitor, userData);
extern void (* FileMonitor_set_userData)(C(FileMonitor) f, void * value);

extern C(Property) * PROPERTY(FileMonitor, fileChange);
extern void (* FileMonitor_set_fileChange)(C(FileMonitor) f, C(FileChange) value);

extern C(Property) * PROPERTY(FileMonitor, fileName);
extern void (* FileMonitor_set_fileName)(C(FileMonitor) f, const char * value);
extern const char * (* FileMonitor_get_fileName)(C(FileMonitor) f);

extern C(Property) * PROPERTY(FileMonitor, directoryName);
extern void (* FileMonitor_set_directoryName)(C(FileMonitor) f, const char * value);
extern const char * (* FileMonitor_get_directoryName)(C(FileMonitor) f);

extern C(bool) (* GlobalAppSettings_getGlobalValue)(C(GlobalAppSettings) __this, const char * section, const char * name, C(GlobalSettingType) type, void * value);

extern C(bool) (* GlobalAppSettings_putGlobalValue)(C(GlobalAppSettings) __this, const char * section, const char * name, C(GlobalSettingType) type, const void * value);

struct CM(GlobalSettings)
{
   C(GlobalSettingsData) data;
   C(GlobalSettingsData) * dataOwner;
   subclass(GlobalSettingsData) dataClass;
};
extern void (* GlobalSettings_close)(C(GlobalSettings) __this);

extern void (* GlobalSettings_closeAndMonitor)(C(GlobalSettings) __this);

extern int M_VTBLID(GlobalSettings, load);
#define GlobalSettings_load(__i) \
   VMETHOD(CO(GlobalSettings), GlobalSettings, load, __i, C(SettingsIOResult), \
      C(GlobalSettings), \
      __i)
extern C(Method) * METHOD(GlobalSettings, load);
extern int M_VTBLID(GlobalSettings, onAskReloadSettings);
#define GlobalSettings_onAskReloadSettings(__i) \
   VMETHOD(CO(GlobalSettings), GlobalSettings, onAskReloadSettings, __i, void, \
      C(GlobalSettings), \
      __i)
extern C(Method) * METHOD(GlobalSettings, onAskReloadSettings);
extern C(bool) (* GlobalSettings_openAndLock)(C(GlobalSettings) __this, C(FileSize) * fileSize);

extern int M_VTBLID(GlobalSettings, save);
#define GlobalSettings_save(__i) \
   VMETHOD(CO(GlobalSettings), GlobalSettings, save, __i, C(SettingsIOResult), \
      C(GlobalSettings), \
      __i)
extern C(Method) * METHOD(GlobalSettings, save);
extern C(Property) * PROPERTY(GlobalSettings, settingsName);
extern void (* GlobalSettings_set_settingsName)(C(GlobalSettings) g, const char * value);
extern const char * (* GlobalSettings_get_settingsName)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, settingsExtension);
extern void (* GlobalSettings_set_settingsExtension)(C(GlobalSettings) g, const char * value);
extern const char * (* GlobalSettings_get_settingsExtension)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, settingsDirectory);
extern void (* GlobalSettings_set_settingsDirectory)(C(GlobalSettings) g, const char * value);
extern const char * (* GlobalSettings_get_settingsDirectory)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, settingsLocation);
extern void (* GlobalSettings_set_settingsLocation)(C(GlobalSettings) g, const char * value);
extern const char * (* GlobalSettings_get_settingsLocation)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, settingsFilePath);
extern void (* GlobalSettings_set_settingsFilePath)(C(GlobalSettings) g, const char * value);
extern const char * (* GlobalSettings_get_settingsFilePath)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, allowDefaultLocations);
extern void (* GlobalSettings_set_allowDefaultLocations)(C(GlobalSettings) g, C(bool) value);
extern C(bool) (* GlobalSettings_get_allowDefaultLocations)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, allUsers);
extern void (* GlobalSettings_set_allUsers)(C(GlobalSettings) g, C(bool) value);
extern C(bool) (* GlobalSettings_get_allUsers)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, portable);
extern void (* GlobalSettings_set_portable)(C(GlobalSettings) g, C(bool) value);
extern C(bool) (* GlobalSettings_get_portable)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, driver);
extern void (* GlobalSettings_set_driver)(C(GlobalSettings) g, constString value);
extern constString (* GlobalSettings_get_driver)(C(GlobalSettings) g);

extern C(Property) * PROPERTY(GlobalSettings, isGlobalPath);
extern C(bool) (* GlobalSettings_get_isGlobalPath)(C(GlobalSettings) g);

extern int M_VTBLID(GlobalSettingsDriver, load);
#define GlobalSettingsDriver_load(__i, f, globalSettings) \
   VMETHOD(CO(GlobalSettingsDriver), GlobalSettingsDriver, load, __i, C(SettingsIOResult), \
      C(File) _ARG C(GlobalSettings), \
      f _ARG globalSettings)
extern C(Method) * METHOD(GlobalSettingsDriver, load);
extern int M_VTBLID(GlobalSettingsDriver, save);
#define GlobalSettingsDriver_save(__i, f, globalSettings) \
   VMETHOD(CO(GlobalSettingsDriver), GlobalSettingsDriver, save, __i, C(SettingsIOResult), \
      C(File) _ARG C(GlobalSettings), \
      f _ARG globalSettings)
extern C(Method) * METHOD(GlobalSettingsDriver, save);
struct CM(JSONParser)
{
   C(File) f;
};
extern C(JSONResult) (* JSONParser_getObject)(C(JSONParser) __this, C(Class) * objectType, void ** object);

#define Meters(x)  ((C(Distance))(x))
#define Distance_in_Meters(x)  ((double)(x))

extern int (* Month_getNumDays)(C(Month) __this, int year);

#define MOVEFILEOPTIONS_overwrite_SHIFT                  0
#define MOVEFILEOPTIONS_overwrite_MASK                   0x1
#define MOVEFILEOPTIONS_overwrite(x)                     ((((MoveFileOptions)(x)) & MOVEFILEOPTIONS_overwrite_MASK) >> MOVEFILEOPTIONS_overwrite_SHIFT)
#define MOVEFILEOPTIONS_SET_overwrite(x, overwrite)              (x) = ((MoveFileOptions)(x) & ~((MoveFileOptions)MOVEFILEOPTIONS_overwrite_MASK)) | (((MoveFileOptions)(overwrite)) << MOVEFILEOPTIONS_overwrite_SHIFT)
#define MOVEFILEOPTIONS_sync_SHIFT                       1
#define MOVEFILEOPTIONS_sync_MASK                        0x2
#define MOVEFILEOPTIONS_sync(x)                          ((((MoveFileOptions)(x)) & MOVEFILEOPTIONS_sync_MASK) >> MOVEFILEOPTIONS_sync_SHIFT)
#define MOVEFILEOPTIONS_SET_sync(x, sync)                   (x) = ((MoveFileOptions)(x) & ~((MoveFileOptions)MOVEFILEOPTIONS_sync_MASK)) | (((MoveFileOptions)(sync)) << MOVEFILEOPTIONS_sync_SHIFT)
#define MOVEFILEOPTIONS(overwrite, sync)                           ((((MoveFileOptions)(overwrite)) << MOVEFILEOPTIONS_overwrite_SHIFT) | ((MoveFileOptions)(sync)) << MOVEFILEOPTIONS_sync_SHIFT)


#define PIPEOPENMODE_output_SHIFT                        0
#define PIPEOPENMODE_output_MASK                         0x1
#define PIPEOPENMODE_output(x)                           ((((PipeOpenMode)(x)) & PIPEOPENMODE_output_MASK) >> PIPEOPENMODE_output_SHIFT)
#define PIPEOPENMODE_SET_output(x, output)                    (x) = ((PipeOpenMode)(x) & ~((PipeOpenMode)PIPEOPENMODE_output_MASK)) | (((PipeOpenMode)(output)) << PIPEOPENMODE_output_SHIFT)
#define PIPEOPENMODE_error_SHIFT                         1
#define PIPEOPENMODE_error_MASK                          0x2
#define PIPEOPENMODE_error(x)                            ((((PipeOpenMode)(x)) & PIPEOPENMODE_error_MASK) >> PIPEOPENMODE_error_SHIFT)
#define PIPEOPENMODE_SET_error(x, error)                     (x) = ((PipeOpenMode)(x) & ~((PipeOpenMode)PIPEOPENMODE_error_MASK)) | (((PipeOpenMode)(error)) << PIPEOPENMODE_error_SHIFT)
#define PIPEOPENMODE_input_SHIFT                         2
#define PIPEOPENMODE_input_MASK                          0x4
#define PIPEOPENMODE_input(x)                            ((((PipeOpenMode)(x)) & PIPEOPENMODE_input_MASK) >> PIPEOPENMODE_input_SHIFT)
#define PIPEOPENMODE_SET_input(x, input)                     (x) = ((PipeOpenMode)(x) & ~((PipeOpenMode)PIPEOPENMODE_input_MASK)) | (((PipeOpenMode)(input)) << PIPEOPENMODE_input_SHIFT)
#define PIPEOPENMODE_showWindow_SHIFT                    3
#define PIPEOPENMODE_showWindow_MASK                     0x8
#define PIPEOPENMODE_showWindow(x)                       ((((PipeOpenMode)(x)) & PIPEOPENMODE_showWindow_MASK) >> PIPEOPENMODE_showWindow_SHIFT)
#define PIPEOPENMODE_SET_showWindow(x, showWindow)                (x) = ((PipeOpenMode)(x) & ~((PipeOpenMode)PIPEOPENMODE_showWindow_MASK)) | (((PipeOpenMode)(showWindow)) << PIPEOPENMODE_showWindow_SHIFT)
#define PIPEOPENMODE(output, error, input, showWindow)                          ((((((PipeOpenMode)(output)) << PIPEOPENMODE_output_SHIFT) | ((PipeOpenMode)(error)) << PIPEOPENMODE_error_SHIFT) | ((PipeOpenMode)(input)) << PIPEOPENMODE_input_SHIFT) | ((PipeOpenMode)(showWindow)) << PIPEOPENMODE_showWindow_SHIFT)


struct C(Point)
{
   int x;
   int y;
};
struct C(Pointf)
{
   float x;
   float y;
};
#define Radians(x)  ((C(Angle))(x))
#define Angle_in_Radians(x)  ((double)(x))

struct CM(RepButton)
{
   C(bool) pressing;
   C(Timer) timer;
   C(Timer) timer2;
};
extern C(Property) * PROPERTY(RepButton, delay);
extern void (* RepButton_set_delay)(C(RepButton) r, C(Time) value);

extern C(Property) * PROPERTY(RepButton, delay0);
extern void (* RepButton_set_delay0)(C(RepButton) r, C(Time) value);

extern C(Property) * PROPERTY(SecSince1970, global);
extern C(SecSince1970) (* SecSince1970_get_global)(int64 s);

extern C(Property) * PROPERTY(SecSince1970, local);
extern C(SecSince1970) (* SecSince1970_get_local)(int64 s);

#define Seconds(x)  ((C(Time))(x))
#define Time_in_Seconds(x)  ((double)(x))

extern void (* Semaphore_release)(C(Semaphore) * __this);

extern C(bool) (* Semaphore_tryWait)(C(Semaphore) * __this);

extern void (* Semaphore_wait)(C(Semaphore) * __this);

extern C(Property) * PROPERTY(Semaphore, initCount);
extern void (* Semaphore_set_initCount)(C(Semaphore) * s, int value);
extern int (* Semaphore_get_initCount)(C(Semaphore) * s);

extern C(Property) * PROPERTY(Semaphore, maxCount);
extern void (* Semaphore_set_maxCount)(C(Semaphore) * s, int value);
extern int (* Semaphore_get_maxCount)(C(Semaphore) * s);

struct C(Size)
{
   C(MinMaxValue) w;
   C(MinMaxValue) h;
};
extern C(Property) * PROPERTY(TempFile, openMode);
extern void (* TempFile_set_openMode)(C(TempFile) t, C(FileOpenMode) value);
extern C(FileOpenMode) (* TempFile_get_openMode)(C(TempFile) t);

extern C(Property) * PROPERTY(TempFile, buffer);
extern byte * (* TempFile_get_buffer)(C(TempFile) t);

extern void (* Thread_create)(C(Thread) __this);

extern void (* Thread_kill)(C(Thread) __this);

extern int M_VTBLID(Thread, main);
#define Thread_main(__i) \
   VMETHOD(CO(Thread), Thread, main, __i, uint, \
      C(Thread), \
      __i)
extern C(Method) * METHOD(Thread, main);
extern void (* Thread_setPriority)(C(Thread) __this, C(ThreadPriority) priority);

extern void (* Thread_wait)(C(Thread) __this);

extern C(Property) * PROPERTY(Thread, created);
extern C(bool) (* Thread_get_created)(C(Thread) t);

#define TimeStamp(x)  ((C(SecSince1970))(x))
#define SecSince1970_in_TimeStamp(x)  ((int64)(x))

extern C(Archive) (* archiveOpen)(const char * fileName, C(ArchiveOpenFlags) flags);
extern C(bool) (* archiveQuerySize)(const char * fileName, C(FileSize) * size);
extern C(bool) (* changeWorkingDir)(const char * buf);
extern C(bool) (* charMatchCategories)(unichar ch, C(CharCategories) categories);
extern void (* copyBytes)(void * dest, const void * source, uint count);
extern void (* copyBytesBy2)(void * dest, const void * source, uint count);
extern void (* copyBytesBy4)(void * dest, const void * source, uint count);
extern char * (* copySystemPath)(const char * p);
extern char * (* copyUnixPath)(const char * p);
extern void (* createTemporaryDir)(char * tempFileName, const char * _template);
extern C(File) (* createTemporaryFile)(char * tempFileName, const char * _template);
extern C(bool) (* deleteFile)(const char * fileName);
extern C(DualPipe) (* dualPipeOpen)(C(PipeOpenMode) mode, const char * commandLine);
extern C(DualPipe) (* dualPipeOpenEnv)(C(PipeOpenMode) mode, const char * env, const char * commandLine);
extern C(DualPipe) (* dualPipeOpenEnvf)(C(PipeOpenMode) mode, const char * env, const char * command, ...);
extern C(DualPipe) (* dualPipeOpenf)(C(PipeOpenMode) mode, const char * command, ...);
extern void (* dumpErrors)(C(bool) display);
extern C(bool) (* execute)(const char * command, ...);
extern C(bool) (* executeEnv)(const char * env, const char * command, ...);
extern C(bool) (* executeWait)(const char * command, ...);
extern C(FileAttribs) (* fileExists)(const char * fileName);
extern void (* fileFixCase)(char * file);
extern C(bool) (* fileGetSize)(const char * fileName, C(FileSize) * size);
extern C(bool) (* fileGetStats)(const char * fileName, C(FileStats) * stats);
extern C(File) (* fileOpen)(const char * fileName, C(FileOpenMode) mode);
extern C(BufferedFile) (* fileOpenBuffered)(const char * fileName, C(FileOpenMode) mode);
extern C(bool) (* fileSetAttribs)(const char * fileName, C(FileAttribs) attribs);
extern C(bool) (* fileSetTime)(const char * fileName, C(SecSince1970) created, C(SecSince1970) accessed, C(SecSince1970) modified);
extern C(bool) (* fileTruncate)(const char * fileName, C(FileSize) size);
extern void (* fillBytes)(void * area, byte value, uint count);
extern void (* fillBytesBy2)(void * area, uint16 value, uint count);
extern void (* fillBytesBy4)(void * area, uint value, uint count);
extern C(bool) (* getAlNum)(const char ** input, char * string, int max);
extern C(CharCategory) (* getCharCategory)(unichar ch);
extern char * (* getEnvironment)(const char * envName, char * envValue, int max);
extern void (* getFreeSpace)(const char * path, C(FileSize64) * size);
extern uint (* getLastErrorCode)(void);
extern int (* getRandom)(int lo, int hi);
extern char * (* getSlashPathBuffer)(char * d, const char * p);
extern char * (* getSystemPathBuffer)(char * d, const char * p);
extern C(Time) (* getTime)(void);
extern char * (* getWorkingDir)(char * buf, int size);
extern void (* __log)(const char * text);
extern void (* logErrorCode)(C(ErrorCode) errorCode, const char * details);
extern void (* __logf)(const char * format, ...);
extern C(bool) (* makeDir)(const char * path);
extern void (* makeSlashPath)(char * p);
extern void (* makeSystemPath)(char * p);
extern void (* moveBytes)(void * dest, const void * source, uint count);
extern C(bool) (* moveFile)(const char * source, const char * dest);
extern C(bool) (* moveFileEx)(const char * source, const char * dest, C(MoveFileOptions) options);
extern void (* randomSeed)(uint seed);
extern C(bool) (* removeDir)(const char * path);
extern C(bool) (* renameFile)(const char * oldName, const char * newName);
extern void (* resetError)(void);
extern void (* setEnvironment)(const char * envName, const char * envValue);
extern void (* setErrorLevel)(C(ErrorLevel) level);
extern void (* setLoggingMode)(C(LoggingMode) mode, void * where);
extern C(bool) (* shellOpen)(const char * fileName, ...);
extern void (* __sleep)(C(Time) seconds);
extern int (* uTF16BEtoUTF8Buffer)(const uint16 * source, byte * dest, int max);
extern int (* uTF8toISO8859_1)(const char * source, char * dest, int max);
extern int (* uTF8toUTF16BufferLen)(const char * source, uint16 * dest, int max, int len);
extern uint16 * (* uTF8toUTF16Len)(const char * source, int byteCount, int * wordCount);
extern void (* unsetEnvironment)(const char * envName);
extern C(bool) (* writeColorAlpha)(C(File) f, C(Class) * type, C(DataValue) * value, int indent, C(bool) eCON);
extern C(bool) (* writeECONObject)(C(File) f, C(Class) * objectType, void * object, int indent);
extern C(bool) (* writeJSONObject)(C(File) f, C(Class) * objectType, void * object, int indent);

// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||gfx3D  //////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
struct C(Vector3Df)
{
   float x;
   float y;
   float z;
};
typedef struct C(Vector3Df) C(Vector3Df);
struct C(Vector3D)
{
   double x;
   double y;
   double z;
};
typedef struct C(Vector3D) C(Vector3D);
struct C(Quaternion)
{
   double w;
   double x;
   double y;
   double z;
};
typedef struct C(Quaternion) C(Quaternion);
struct C(Transform)
{
   C(Vector3D) position;
   C(Quaternion) orientation;
   C(Vector3Df) scaling;
};
typedef struct C(Transform) C(Transform);
typedef struct C(PrimitiveSingle) C(PrimitiveSingle);
typedef uint32 C(PrimitiveGroupType);
typedef struct C(PrimitiveGroup) C(PrimitiveGroup);
typedef uint32 C(MaterialFlags);
typedef struct C(Material) C(Material);
struct CM(Shader)
{
   byte __ecerePrivateData0[24];
   uint64 state;
   C(bool) uniformsModified;
};
typedef C(Instance) C(Shader);
typedef C(Instance) C(Bitmap);
typedef C(Bitmap) C(CubeMap);
struct C(ColorRGB)
{
   float r;
   float g;
   float b;
};
typedef struct C(ColorRGB) C(ColorRGB);
#if CPP11
enum C(PixelFormat) : int
#else
typedef int C(PixelFormat);
enum C(PixelFormat)
#endif
{
   PixelFormat_pixelFormat4 = 0x0,
   PixelFormat_pixelFormat8 = 0x1,
   PixelFormat_pixelFormat444 = 0x2,
   PixelFormat_pixelFormat555 = 0x3,
   PixelFormat_pixelFormat565 = 0x4,
   PixelFormat_pixelFormat888 = 0x5,
   PixelFormat_pixelFormatAlpha = 0x6,
   PixelFormat_pixelFormatText = 0x7,
   PixelFormat_pixelFormatRGBA = 0x8
};

typedef uint32 C(DisplayFlags);
struct CM(DisplaySystem)
{
   byte __ecerePrivateData0[24];
   C(PixelFormat) pixelFormat;
   C(DisplayFlags) flags;
};
typedef C(Instance) C(DisplaySystem);
typedef uint32 C(ColorAlpha);
struct CM(Bitmap)
{
   int width;
   int height;
   C(PixelFormat) pixelFormat;
   byte * picture;
   uint stride;
   uint size;
   uint sizeBytes;
   C(ColorAlpha) * palette;
   C(bool) allocatePalette;
   C(bool) transparent;
   int shadeShift;
   byte * paletteShades;
   C(bool) alphaBlend;
   C(DisplaySystem) displaySystem;
   subclass(DisplayDriver) driver;
   void * driverData;
   C(bool) keepData;
   C(bool) mipMaps;
};
struct C(Material)
{
   C(Material) * prev;
   C(Material) * next;
   char * name;
   float opacity;
   C(ColorRGB) diffuse;
   C(ColorRGB) ambient;
   C(ColorRGB) specular;
   C(ColorRGB) emissive;
   float power;
   C(Bitmap) baseMap;
   C(Bitmap) bumpMap;
   C(Bitmap) specularMap;
   C(Bitmap) reflectMap;
   C(CubeMap) envMap;
   float reflectivity;
   float refractiveIndex;
   float refractiveIndexContainer;
   C(MaterialFlags) flags;
   float uScale;
   float vScale;
   C(Shader) shader;
};
struct C(PrimitiveGroup)
{
   C(PrimitiveGroup) * prev;
   C(PrimitiveGroup) * next;
   C(PrimitiveGroupType) type;
   union
   {
      struct
      {
         union
         {
            uint16 * indices;
            uint * indices32;
         };
         int nIndices;
      };
      struct
      {
         int first;
         int nVertices;
      };
   };
   C(Material) * material;
};
typedef struct C(Plane) C(Plane);
typedef uint32 C(ObjectFlags);
struct C(Object)
{
   byte __ecerePrivateData0[128];
   C(Transform) transform;
};
typedef struct C(Object) C(Object);
typedef uint32 C(MeshFeatures);
typedef struct C(Mesh) C(Mesh);
struct C(Matrix)
{
   union
   {
      double array[16];
      double m[4][4];
   };
};
typedef struct C(Matrix) C(Matrix);
typedef struct C(Line) C(Line);
#if CPP11
enum C(FovDirection) : int
#else
typedef int C(FovDirection);
enum C(FovDirection)
#endif
{
   FovDirection_widest = 0x0,
   FovDirection_horizontal = 0x1,
   FovDirection_vertical = 0x2
};

struct C(Euler)
{
   C(Angle) yaw;
   C(Angle) pitch;
   C(Angle) roll;
};
typedef struct C(Euler) C(Euler);
#if CPP11
enum C(CameraType) : int
#else
typedef int C(CameraType);
enum C(CameraType)
#endif
{
   CameraType_fixed = 0x0,
   CameraType_fixedQuaternion = 0x1,
   CameraType_attached = 0x2,
   CameraType_attachedQuaternion = 0x3,
   CameraType_lookAt = 0x4,
   CameraType_lookAtObject = 0x5
};

struct CM(Camera)
{
   byte __ecerePrivateData0[24];
   C(Vector3D) position;
};
typedef C(Instance) C(Camera);
typedef uint32 C(LightFlags);
struct C(Light)
{
   C(LightFlags) flags;
   C(ColorRGB) ambient;
   C(ColorRGB) diffuse;
   C(ColorRGB) specular;
   C(Vector3D) direction;
   C(Quaternion) orientation;
   C(Object) * lightObject;
   C(Object) * target;
   C(Angle) fallOff;
   C(Angle) hotSpot;
   float Kc;
   float Kl;
   float Kq;
   C(Angle) start;
   C(Angle) end;
   float multiplier;
};
typedef struct C(Light) C(Light);
typedef struct C(ColorRGBAf) C(ColorRGBAf);
// end -- moved backwards outputs
#if CPP11
enum C(ClippingPlane) : int
#else
typedef int C(ClippingPlane);
enum C(ClippingPlane)
#endif
{
   ClippingPlane_left = 0x0,
   ClippingPlane_right = 0x1,
   ClippingPlane_top = 0x2,
   ClippingPlane_bottom = 0x3,
   ClippingPlane_near = 0x4,
   ClippingPlane_far = 0x5
};

typedef struct C(FrameKey) C(FrameKey);
typedef struct C(FrameTrack) C(FrameTrack);
typedef uint32 C(FrameTrackBits);
#if CPP11
enum C(FrameTrackType) : uint16
#else
typedef uint16 C(FrameTrackType);
enum C(FrameTrackType)
#endif
{
   FrameTrackType_position = 0x1,
   FrameTrackType_rotation = 0x2,
   FrameTrackType_scaling = 0x3,
   FrameTrackType_fov = 0x4,
   FrameTrackType_roll = 0x5,
   FrameTrackType_colorChange = 0x6,
   FrameTrackType_morph = 0x7,
   FrameTrackType_hotSpot = 0x8,
   FrameTrackType_fallOff = 0x9,
   FrameTrackType_hide = 0xA
};

#if CPP11
enum C(FrustumPlacement) : int
#else
typedef int C(FrustumPlacement);
enum C(FrustumPlacement)
#endif
{
   FrustumPlacement_outside = 0x0,
   FrustumPlacement_inside = 0x1,
   FrustumPlacement_intersecting = 0x2
};

typedef C(Instance) C(ObjectFormat);
#if CPP11
enum C(RenderPrimitiveType) : uint
#else
typedef C(PrimitiveGroupType) C(RenderPrimitiveType);
enum C(RenderPrimitiveType)
#endif
{
   RenderPrimitiveType_dot = 0x0,
   RenderPrimitiveType_lines = 0x1,
   RenderPrimitiveType_triangles = 0x2,
   RenderPrimitiveType_triStrip = 0x3,
   RenderPrimitiveType_triFan = 0x4,
   RenderPrimitiveType_quads = 0x5,
   RenderPrimitiveType_quadStrip = 0x6,
   RenderPrimitiveType_lineStrip = 0x7
};

extern void (* Camera_adjustAngle)(C(Camera) __this, C(Quaternion) * angle);

extern void (* Camera_adjustPosition)(C(Camera) __this, C(Vector3D) * position);

extern void (* Camera_move)(C(Camera) __this, C(Vector3D) * direction);

extern C(bool) (* Camera_pointsVisible)(C(Camera) __this, C(Vector3D) * points, int numPoints, double threshold);

extern C(bool) (* Camera_project)(C(Camera) __this, C(Vector3D) * vector, C(Vector3D) * point);

extern C(bool) (* Camera_projectSize)(C(Camera) __this, C(Vector3D) * vector, C(Point) * point);

extern void (* Camera_rotatePitch)(C(Camera) __this, C(Angle) amount, C(Angle) min, C(Angle) max);

extern void (* Camera_rotateRoll)(C(Camera) __this, C(Angle) amount, C(Angle) min, C(Angle) max);

extern void (* Camera_rotateYaw)(C(Camera) __this, C(Angle) amount, C(Angle) min, C(Angle) max);

extern void (* Camera_setup)(C(Camera) __this, int width, int height, C(Point) * origin);

extern void (* Camera_slerp)(C(Camera) __this, float amount);

extern C(bool) (* Camera_sphereVisible)(C(Camera) __this, C(Vector3D) * center, float radius);

extern void (* Camera_transformMatrix)(C(Camera) __this, C(Matrix) * dest, C(Matrix) * src);

extern void (* Camera_transformNormal)(C(Camera) __this, C(Vector3D) * dest, C(Vector3D) * src);

extern void (* Camera_transformPoint)(C(Camera) __this, C(Vector3D) * dest, C(Vector3D) * src);

extern void (* Camera_unproject)(C(Camera) __this, C(Vector3D) * point, C(Vector3D) * vector);

extern void (* Camera_untransform)(C(Camera) __this, C(Vector3D) * src, C(Vector3D) * result);

extern C(bool) (* Camera_update)(C(Camera) __this);

extern void (* Camera_setCPosition)(C(Camera) __this, C(Vector3D) * value);

extern void (* Camera_setViewMatrix)(C(Camera) __this, C(Matrix) * value);

extern C(Property) * PROPERTY(Camera, type);
extern void (* Camera_set_type)(C(Camera) c, C(CameraType) value);
extern C(CameraType) (* Camera_get_type)(C(Camera) c);

extern C(Property) * PROPERTY(Camera, position);
extern void (* Camera_set_position)(C(Camera) c, const C(Vector3D) * value);
extern void (* Camera_get_position)(C(Camera) c, C(Vector3D) * value);

extern C(Property) * PROPERTY(Camera, orientation);
extern void (* Camera_set_orientation)(C(Camera) c, const C(Quaternion) * value);
extern void (* Camera_get_orientation)(C(Camera) c, C(Quaternion) * value);

extern C(Property) * PROPERTY(Camera, eulerOrientation);
extern void (* Camera_set_eulerOrientation)(C(Camera) c, const C(Euler) * value);
extern void (* Camera_get_eulerOrientation)(C(Camera) c, C(Euler) * value);

extern C(Property) * PROPERTY(Camera, cPosition);
extern void (* Camera_get_cPosition)(C(Camera) c, C(Vector3D) * value);

extern C(Property) * PROPERTY(Camera, cOrientation);
extern void (* Camera_get_cOrientation)(C(Camera) c, C(Quaternion) * value);

extern C(Property) * PROPERTY(Camera, fov);
extern void (* Camera_set_fov)(C(Camera) c, C(Angle) value);
extern C(Angle) (* Camera_get_fov)(C(Camera) c);

extern C(Property) * PROPERTY(Camera, zMin);
extern void (* Camera_set_zMin)(C(Camera) c, float value);
extern float (* Camera_get_zMin)(C(Camera) c);

extern C(Property) * PROPERTY(Camera, zMax);
extern void (* Camera_set_zMax)(C(Camera) c, float value);
extern float (* Camera_get_zMax)(C(Camera) c);

extern C(Property) * PROPERTY(Camera, target);
extern void (* Camera_set_target)(C(Camera) c, C(Object) * value);
extern C(Object) * (* Camera_get_target)(C(Camera) c);

extern C(Property) * PROPERTY(Camera, fovDirection);
extern void (* Camera_set_fovDirection)(C(Camera) c, C(FovDirection) value);
extern C(FovDirection) (* Camera_get_fovDirection)(C(Camera) c);

extern C(Property) * PROPERTY(Camera, aspectRatio);
extern void (* Camera_set_aspectRatio)(C(Camera) c, float value);
extern float (* Camera_get_aspectRatio)(C(Camera) c);

extern C(Property) * PROPERTY(Camera, focal);
extern void (* Camera_get_focal)(C(Camera) c, C(Size) * value);

extern void (* Euler_add)(C(Euler) * __this, C(Euler) * e1, C(Euler) * e2);

extern C(Property) * PROPERTY(Euler, Quaternion);
extern void (* Euler_from_Quaternion)(C(Euler) e, const C(Quaternion) * value);
extern void (* Euler_to_Quaternion)(C(Euler) e, C(Quaternion) * value);

struct C(FrameKey)
{
   uint frame;
   float tension;
   float continuity;
   float bias;
   float easeFrom;
   float easeTo;
   union
   {
      C(Vector3Df) position;
      C(Quaternion) orientation;
      C(Vector3Df) scaling;
      float roll;
      float fov;
      C(ColorRGB) color;
      float hotSpot;
      float fallOff;
   };
};
#define FRAMETRACKBITS_type_SHIFT                        0
#define FRAMETRACKBITS_type_MASK                         0xFFFF
#define FRAMETRACKBITS_type(x)                           ((((FrameTrackBits)(x)) & FRAMETRACKBITS_type_MASK) >> FRAMETRACKBITS_type_SHIFT)
#define FRAMETRACKBITS_SET_type(x, type)                    (x) = ((FrameTrackBits)(x) & ~((FrameTrackBits)FRAMETRACKBITS_type_MASK)) | (((FrameTrackBits)(type)) << FRAMETRACKBITS_type_SHIFT)
#define FRAMETRACKBITS_loop_SHIFT                        16
#define FRAMETRACKBITS_loop_MASK                         0x10000
#define FRAMETRACKBITS_loop(x)                           ((((FrameTrackBits)(x)) & FRAMETRACKBITS_loop_MASK) >> FRAMETRACKBITS_loop_SHIFT)
#define FRAMETRACKBITS_SET_loop(x, loop)                    (x) = ((FrameTrackBits)(x) & ~((FrameTrackBits)FRAMETRACKBITS_loop_MASK)) | (((FrameTrackBits)(loop)) << FRAMETRACKBITS_loop_SHIFT)
#define FRAMETRACKBITS(type, loop)                            ((((FrameTrackBits)(type)) << FRAMETRACKBITS_type_SHIFT) | ((FrameTrackBits)(loop)) << FRAMETRACKBITS_loop_SHIFT)


struct C(Line)
{
   C(Vector3D) p0;
   C(Vector3D) delta;
};
extern C(bool) (* Line_intersectSphere)(C(Line) * __this, double radius, double * t);

extern void (* Material_free)(C(Material) * __this);

#define MATERIALFLAGS_doubleSided_SHIFT                  0
#define MATERIALFLAGS_doubleSided_MASK                   0x1
#define MATERIALFLAGS_doubleSided(x)                     ((((MaterialFlags)(x)) & MATERIALFLAGS_doubleSided_MASK) >> MATERIALFLAGS_doubleSided_SHIFT)
#define MATERIALFLAGS_SET_doubleSided(x, doubleSided)              (x) = ((MaterialFlags)(x) & ~((MaterialFlags)MATERIALFLAGS_doubleSided_MASK)) | (((MaterialFlags)(doubleSided)) << MATERIALFLAGS_doubleSided_SHIFT)
#define MATERIALFLAGS_translucent_SHIFT                  1
#define MATERIALFLAGS_translucent_MASK                   0x2
#define MATERIALFLAGS_translucent(x)                     ((((MaterialFlags)(x)) & MATERIALFLAGS_translucent_MASK) >> MATERIALFLAGS_translucent_SHIFT)
#define MATERIALFLAGS_SET_translucent(x, translucent)              (x) = ((MaterialFlags)(x) & ~((MaterialFlags)MATERIALFLAGS_translucent_MASK)) | (((MaterialFlags)(translucent)) << MATERIALFLAGS_translucent_SHIFT)
#define MATERIALFLAGS_tile_SHIFT                         2
#define MATERIALFLAGS_tile_MASK                          0x4
#define MATERIALFLAGS_tile(x)                            ((((MaterialFlags)(x)) & MATERIALFLAGS_tile_MASK) >> MATERIALFLAGS_tile_SHIFT)
#define MATERIALFLAGS_SET_tile(x, tile)                     (x) = ((MaterialFlags)(x) & ~((MaterialFlags)MATERIALFLAGS_tile_MASK)) | (((MaterialFlags)(tile)) << MATERIALFLAGS_tile_SHIFT)
#define MATERIALFLAGS_noFog_SHIFT                        3
#define MATERIALFLAGS_noFog_MASK                         0x8
#define MATERIALFLAGS_noFog(x)                           ((((MaterialFlags)(x)) & MATERIALFLAGS_noFog_MASK) >> MATERIALFLAGS_noFog_SHIFT)
#define MATERIALFLAGS_SET_noFog(x, noFog)                    (x) = ((MaterialFlags)(x) & ~((MaterialFlags)MATERIALFLAGS_noFog_MASK)) | (((MaterialFlags)(noFog)) << MATERIALFLAGS_noFog_SHIFT)
#define MATERIALFLAGS_singleSideLight_SHIFT              4
#define MATERIALFLAGS_singleSideLight_MASK               0x10
#define MATERIALFLAGS_singleSideLight(x)                 ((((MaterialFlags)(x)) & MATERIALFLAGS_singleSideLight_MASK) >> MATERIALFLAGS_singleSideLight_SHIFT)
#define MATERIALFLAGS_SET_singleSideLight(x, singleSideLight)          (x) = ((MaterialFlags)(x) & ~((MaterialFlags)MATERIALFLAGS_singleSideLight_MASK)) | (((MaterialFlags)(singleSideLight)) << MATERIALFLAGS_singleSideLight_SHIFT)
#define MATERIALFLAGS_separateSpecular_SHIFT             5
#define MATERIALFLAGS_separateSpecular_MASK              0x20
#define MATERIALFLAGS_separateSpecular(x)                ((((MaterialFlags)(x)) & MATERIALFLAGS_separateSpecular_MASK) >> MATERIALFLAGS_separateSpecular_SHIFT)
#define MATERIALFLAGS_SET_separateSpecular(x, separateSpecular)         (x) = ((MaterialFlags)(x) & ~((MaterialFlags)MATERIALFLAGS_separateSpecular_MASK)) | (((MaterialFlags)(separateSpecular)) << MATERIALFLAGS_separateSpecular_SHIFT)
#define MATERIALFLAGS_cubeMap_SHIFT                      6
#define MATERIALFLAGS_cubeMap_MASK                       0x40
#define MATERIALFLAGS_cubeMap(x)                         ((((MaterialFlags)(x)) & MATERIALFLAGS_cubeMap_MASK) >> MATERIALFLAGS_cubeMap_SHIFT)
#define MATERIALFLAGS_SET_cubeMap(x, cubeMap)                  (x) = ((MaterialFlags)(x) & ~((MaterialFlags)MATERIALFLAGS_cubeMap_MASK)) | (((MaterialFlags)(cubeMap)) << MATERIALFLAGS_cubeMap_SHIFT)
#define MATERIALFLAGS_noLighting_SHIFT                   7
#define MATERIALFLAGS_noLighting_MASK                    0x80
#define MATERIALFLAGS_noLighting(x)                      ((((MaterialFlags)(x)) & MATERIALFLAGS_noLighting_MASK) >> MATERIALFLAGS_noLighting_SHIFT)
#define MATERIALFLAGS_SET_noLighting(x, noLighting)               (x) = ((MaterialFlags)(x) & ~((MaterialFlags)MATERIALFLAGS_noLighting_MASK)) | (((MaterialFlags)(noLighting)) << MATERIALFLAGS_noLighting_SHIFT)


extern double (* Matrix_determinant)(C(Matrix) * __this);

extern void (* Matrix_identity)(C(Matrix) * __this);

extern void (* Matrix_inverse)(C(Matrix) * __this, C(Matrix) * source);

extern void (* Matrix_multiply)(C(Matrix) * __this, C(Matrix) * a, C(Matrix) * b);

extern void (* Matrix_rotate)(C(Matrix) * __this, C(Quaternion) * quat);

extern void (* Matrix_rotationQuaternion)(C(Matrix) * __this, C(Quaternion) * quat);

extern void (* Matrix_scale)(C(Matrix) * __this, double sx, double sy, double sz);

extern void (* Matrix_toEuler)(C(Matrix) * __this, C(Euler) * euler);

extern void (* Matrix_translate)(C(Matrix) * __this, double tx, double ty, double tz);

extern void (* Matrix_transpose)(C(Matrix) * __this, C(Matrix) * source);

extern C(Property) * PROPERTY(Matrix, Quaternion);
extern void (* Matrix_from_Quaternion)(C(Matrix) m, const C(Quaternion) * value);
extern void (* Matrix_to_Quaternion)(C(Matrix) m, C(Quaternion) * value);

extern C(PrimitiveGroup) * (* Mesh_addPrimitiveGroup)(C(Mesh) * __this, C(PrimitiveGroupType) flags, int nIndices);

extern C(bool) (* Mesh_allocate)(C(Mesh) * __this, C(MeshFeatures) what, int nVertices, C(DisplaySystem) displaySystem);

extern C(bool) (* Mesh_allocatePrimitive)(C(Mesh) * __this, C(PrimitiveSingle) * primitive, C(PrimitiveGroupType) flags, int nIndices);

extern void (* Mesh_applyMaterial)(C(Mesh) * __this, C(Material) * material);

extern C(bool) (* Mesh_applyTranslucency)(C(Mesh) * __this, C(Object) * object);

extern void (* Mesh_computeNormals)(C(Mesh) * __this);

extern void (* Mesh_free)(C(Mesh) * __this, C(MeshFeatures) what);

extern void (* Mesh_freePrimitive)(C(Mesh) * __this, C(PrimitiveSingle) * primitive);

extern void (* Mesh_freePrimitiveGroup)(C(Mesh) * __this, C(PrimitiveGroup) * group);

extern void * (* Mesh_getData)(C(Mesh) * __this);

extern C(bool) (* Mesh_lock)(C(Mesh) * __this, C(MeshFeatures) flags);

extern C(bool) (* Mesh_lockPrimitive)(C(Mesh) * __this, C(PrimitiveSingle) * primitive);

extern C(bool) (* Mesh_lockPrimitiveGroup)(C(Mesh) * __this, C(PrimitiveGroup) * group);

extern void (* Mesh_setData)(C(Mesh) * __this, void * value);

extern void (* Mesh_unlock)(C(Mesh) * __this, C(MeshFeatures) flags);

extern void (* Mesh_unlockPrimitive)(C(Mesh) * __this, C(PrimitiveSingle) * primitive);

extern void (* Mesh_unlockPrimitiveGroup)(C(Mesh) * __this, C(PrimitiveGroup) * group);

extern C(Property) * PROPERTY(Mesh, texCoords);
extern void (* Mesh_set_texCoords)(C(Mesh) * m, C(Pointf) * value);
extern C(Pointf) * (* Mesh_get_texCoords)(C(Mesh) * m);

extern C(Property) * PROPERTY(Mesh, nVertices);
extern void (* Mesh_set_nVertices)(C(Mesh) * m, int value);
extern int (* Mesh_get_nVertices)(C(Mesh) * m);

extern C(Property) * PROPERTY(Mesh, vertices);
extern void (* Mesh_set_vertices)(C(Mesh) * m, C(Vector3Df) * value);
extern C(Vector3Df) * (* Mesh_get_vertices)(C(Mesh) * m);

extern C(Property) * PROPERTY(Mesh, normals);
extern void (* Mesh_set_normals)(C(Mesh) * m, C(Vector3Df) * value);
extern C(Vector3Df) * (* Mesh_get_normals)(C(Mesh) * m);

extern C(Property) * PROPERTY(Mesh, tangents);
extern void (* Mesh_set_tangents)(C(Mesh) * m, C(Vector3Df) * value);
extern C(Vector3Df) * (* Mesh_get_tangents)(C(Mesh) * m);

extern C(Property) * PROPERTY(Mesh, colors);
extern void (* Mesh_set_colors)(C(Mesh) * m, C(ColorRGBAf) * value);
extern C(ColorRGBAf) * (* Mesh_get_colors)(C(Mesh) * m);

extern C(Property) * PROPERTY(Mesh, lightVectors);
extern void (* Mesh_set_lightVectors)(C(Mesh) * m, C(ColorRGB) * value);
extern C(ColorRGB) * (* Mesh_get_lightVectors)(C(Mesh) * m);

extern C(Property) * PROPERTY(Mesh, groups);
extern void (* Mesh_get_groups)(C(Mesh) * m, C(OldList) * value);

extern C(Property) * PROPERTY(Mesh, flags);
extern void (* Mesh_set_flags)(C(Mesh) * m, C(MeshFeatures) value);
extern C(MeshFeatures) (* Mesh_get_flags)(C(Mesh) * m);

#define MESHFEATURES_vertices_SHIFT                      0
#define MESHFEATURES_vertices_MASK                       0x1
#define MESHFEATURES_vertices(x)                         ((((MeshFeatures)(x)) & MESHFEATURES_vertices_MASK) >> MESHFEATURES_vertices_SHIFT)
#define MESHFEATURES_SET_vertices(x, vertices)                  (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_vertices_MASK)) | (((MeshFeatures)(vertices)) << MESHFEATURES_vertices_SHIFT)
#define MESHFEATURES_normals_SHIFT                       1
#define MESHFEATURES_normals_MASK                        0x2
#define MESHFEATURES_normals(x)                          ((((MeshFeatures)(x)) & MESHFEATURES_normals_MASK) >> MESHFEATURES_normals_SHIFT)
#define MESHFEATURES_SET_normals(x, normals)                   (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_normals_MASK)) | (((MeshFeatures)(normals)) << MESHFEATURES_normals_SHIFT)
#define MESHFEATURES_texCoords1_SHIFT                    2
#define MESHFEATURES_texCoords1_MASK                     0x4
#define MESHFEATURES_texCoords1(x)                       ((((MeshFeatures)(x)) & MESHFEATURES_texCoords1_MASK) >> MESHFEATURES_texCoords1_SHIFT)
#define MESHFEATURES_SET_texCoords1(x, texCoords1)                (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_texCoords1_MASK)) | (((MeshFeatures)(texCoords1)) << MESHFEATURES_texCoords1_SHIFT)
#define MESHFEATURES_texCoords2_SHIFT                    3
#define MESHFEATURES_texCoords2_MASK                     0x8
#define MESHFEATURES_texCoords2(x)                       ((((MeshFeatures)(x)) & MESHFEATURES_texCoords2_MASK) >> MESHFEATURES_texCoords2_SHIFT)
#define MESHFEATURES_SET_texCoords2(x, texCoords2)                (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_texCoords2_MASK)) | (((MeshFeatures)(texCoords2)) << MESHFEATURES_texCoords2_SHIFT)
#define MESHFEATURES_doubleNormals_SHIFT                 4
#define MESHFEATURES_doubleNormals_MASK                  0x10
#define MESHFEATURES_doubleNormals(x)                    ((((MeshFeatures)(x)) & MESHFEATURES_doubleNormals_MASK) >> MESHFEATURES_doubleNormals_SHIFT)
#define MESHFEATURES_SET_doubleNormals(x, doubleNormals)             (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_doubleNormals_MASK)) | (((MeshFeatures)(doubleNormals)) << MESHFEATURES_doubleNormals_SHIFT)
#define MESHFEATURES_doubleVertices_SHIFT                5
#define MESHFEATURES_doubleVertices_MASK                 0x20
#define MESHFEATURES_doubleVertices(x)                   ((((MeshFeatures)(x)) & MESHFEATURES_doubleVertices_MASK) >> MESHFEATURES_doubleVertices_SHIFT)
#define MESHFEATURES_SET_doubleVertices(x, doubleVertices)            (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_doubleVertices_MASK)) | (((MeshFeatures)(doubleVertices)) << MESHFEATURES_doubleVertices_SHIFT)
#define MESHFEATURES_colors_SHIFT                        6
#define MESHFEATURES_colors_MASK                         0x40
#define MESHFEATURES_colors(x)                           ((((MeshFeatures)(x)) & MESHFEATURES_colors_MASK) >> MESHFEATURES_colors_SHIFT)
#define MESHFEATURES_SET_colors(x, colors)                    (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_colors_MASK)) | (((MeshFeatures)(colors)) << MESHFEATURES_colors_SHIFT)
#define MESHFEATURES_lightVectors_SHIFT                  7
#define MESHFEATURES_lightVectors_MASK                   0x80
#define MESHFEATURES_lightVectors(x)                     ((((MeshFeatures)(x)) & MESHFEATURES_lightVectors_MASK) >> MESHFEATURES_lightVectors_SHIFT)
#define MESHFEATURES_SET_lightVectors(x, lightVectors)              (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_lightVectors_MASK)) | (((MeshFeatures)(lightVectors)) << MESHFEATURES_lightVectors_SHIFT)
#define MESHFEATURES_tangents_SHIFT                      8
#define MESHFEATURES_tangents_MASK                       0x100
#define MESHFEATURES_tangents(x)                         ((((MeshFeatures)(x)) & MESHFEATURES_tangents_MASK) >> MESHFEATURES_tangents_SHIFT)
#define MESHFEATURES_SET_tangents(x, tangents)                  (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_tangents_MASK)) | (((MeshFeatures)(tangents)) << MESHFEATURES_tangents_SHIFT)
#define MESHFEATURES_intVertices_SHIFT                   9
#define MESHFEATURES_intVertices_MASK                    0x200
#define MESHFEATURES_intVertices(x)                      ((((MeshFeatures)(x)) & MESHFEATURES_intVertices_MASK) >> MESHFEATURES_intVertices_SHIFT)
#define MESHFEATURES_SET_intVertices(x, intVertices)               (x) = ((MeshFeatures)(x) & ~((MeshFeatures)MESHFEATURES_intVertices_MASK)) | (((MeshFeatures)(intVertices)) << MESHFEATURES_intVertices_SHIFT)


extern C(bool) (* Object_addName)(C(Object) * __this, C(Object) * object, const char * name);

extern void (* Object_animate)(C(Object) * __this, uint frame);

extern void (* Object_doubleSided)(C(Object) * __this, C(bool) flag);

extern void (* Object_duplicate)(C(Object) * __this, C(Object) * model);

extern C(Object) * (* Object_find)(C(Object) * __this, const char * name);

extern void (* Object_free)(C(Object) * __this, C(DisplaySystem) displaySystem);

extern void (* Object_freeMesh)(C(Object) * __this, C(DisplaySystem) displaySystem);

extern void (* Object_initialize)(C(Object) * __this);

extern C(Mesh) * (* Object_initializeMesh)(C(Object) * __this, C(DisplaySystem) displaySystem);

extern C(bool) (* Object_intersectsGroundPolygon)(C(Object) * __this, int count, C(Pointf) * pointfs);

extern C(bool) (* Object_load)(C(Object) * __this, const char * fileName, const char * type, C(DisplaySystem) displaySystem);

extern C(bool) (* Object_merge)(C(Object) * __this, C(DisplaySystem) displaySystem);

extern void (* Object_move)(C(Object) * __this, C(Vector3D) * direction);

extern void (* Object_rotateEuler)(C(Object) * __this, C(Euler) * rotation, C(Euler) * min, C(Euler) * max);

extern void (* Object_setMinMaxRadius)(C(Object) * __this, C(bool) processMesh);

extern void (* Object_updateTransform)(C(Object) * __this);

extern C(Property) * PROPERTY(Object, transform);
extern void (* Object_set_transform)(C(Object) * o, const C(Transform) * value);
extern void (* Object_get_transform)(C(Object) * o, C(Transform) * value);

extern C(Property) * PROPERTY(Object, material);
extern void (* Object_set_material)(C(Object) * o, C(Material) * value);
extern C(Material) * (* Object_get_material)(C(Object) * o);

extern C(Property) * PROPERTY(Object, max);
extern void (* Object_get_max)(C(Object) * o, C(Vector3Df) * value);

extern C(Property) * PROPERTY(Object, min);
extern void (* Object_get_min)(C(Object) * o, C(Vector3Df) * value);

extern C(Property) * PROPERTY(Object, center);
extern void (* Object_get_center)(C(Object) * o, C(Vector3Df) * value);

extern C(Property) * PROPERTY(Object, radius);
extern float (* Object_get_radius)(C(Object) * o);

extern C(Property) * PROPERTY(Object, wmax);
extern void (* Object_get_wmax)(C(Object) * o, C(Vector3D) * value);

extern C(Property) * PROPERTY(Object, wmin);
extern void (* Object_get_wmin)(C(Object) * o, C(Vector3D) * value);

extern C(Property) * PROPERTY(Object, wcenter);
extern void (* Object_get_wcenter)(C(Object) * o, C(Vector3D) * value);

extern C(Property) * PROPERTY(Object, wradius);
extern double (* Object_get_wradius)(C(Object) * o);

extern C(Property) * PROPERTY(Object, tag);
extern void (* Object_set_tag)(C(Object) * o, void * value);
extern void * (* Object_get_tag)(C(Object) * o);

extern C(Property) * PROPERTY(Object, frame);
extern void (* Object_set_frame)(C(Object) * o, int value);
extern int (* Object_get_frame)(C(Object) * o);

extern C(Property) * PROPERTY(Object, startFrame);
extern void (* Object_set_startFrame)(C(Object) * o, int value);
extern int (* Object_get_startFrame)(C(Object) * o);

extern C(Property) * PROPERTY(Object, endFrame);
extern void (* Object_set_endFrame)(C(Object) * o, int value);
extern int (* Object_get_endFrame)(C(Object) * o);

extern C(Property) * PROPERTY(Object, mesh);
extern void (* Object_set_mesh)(C(Object) * o, C(Mesh) * value);
extern C(Mesh) * (* Object_get_mesh)(C(Object) * o);

extern C(Property) * PROPERTY(Object, camera);
extern C(Camera) (* Object_get_camera)(C(Object) * o);

extern C(Property) * PROPERTY(Object, firstChild);
extern C(Object) * (* Object_get_firstChild)(C(Object) * o);

extern C(Property) * PROPERTY(Object, next);
extern C(Object) * (* Object_get_next)(C(Object) * o);

extern C(Property) * PROPERTY(Object, name);
extern const char * (* Object_get_name)(C(Object) * o);

extern C(Property) * PROPERTY(Object, matrix);
extern void (* Object_get_matrix)(C(Object) * o, C(Matrix) * value);

extern C(Property) * PROPERTY(Object, cameraTarget);
extern void (* Object_set_cameraTarget)(C(Object) * o, C(Object) * value);
extern C(Object) * (* Object_get_cameraTarget)(C(Object) * o);

extern C(Property) * PROPERTY(Object, tracks);
extern C(OldList) * (* Object_get_tracks)(C(Object) * o);

extern C(Property) * PROPERTY(Object, flags);
extern void (* Object_set_flags)(C(Object) * o, C(ObjectFlags) value);
extern C(ObjectFlags) (* Object_get_flags)(C(Object) * o);

extern C(Property) * PROPERTY(Object, parent);
extern C(Object) * (* Object_get_parent)(C(Object) * o);

extern C(Property) * PROPERTY(Object, numChildren);
extern uint (* Object_get_numChildren)(C(Object) * o);

extern C(Property) * PROPERTY(Object, localMatrixPtr);
extern C(Matrix) * (* Object_get_localMatrixPtr)(C(Object) * o);

extern C(Property) * PROPERTY(Object, matrixPtr);
extern C(Matrix) * (* Object_get_matrixPtr)(C(Object) * o);

extern C(Property) * PROPERTY(Object, light);
extern void (* Object_set_light)(C(Object) * o, const C(Light) * value);
extern void (* Object_get_light)(C(Object) * o, C(Light) * value);

#define OBJECTFLAGS_root_SHIFT                           0
#define OBJECTFLAGS_root_MASK                            0x1
#define OBJECTFLAGS_root(x)                              ((((ObjectFlags)(x)) & OBJECTFLAGS_root_MASK) >> OBJECTFLAGS_root_SHIFT)
#define OBJECTFLAGS_SET_root(x, root)                       (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_root_MASK)) | (((ObjectFlags)(root)) << OBJECTFLAGS_root_SHIFT)
#define OBJECTFLAGS_viewSpace_SHIFT                      1
#define OBJECTFLAGS_viewSpace_MASK                       0x2
#define OBJECTFLAGS_viewSpace(x)                         ((((ObjectFlags)(x)) & OBJECTFLAGS_viewSpace_MASK) >> OBJECTFLAGS_viewSpace_SHIFT)
#define OBJECTFLAGS_SET_viewSpace(x, viewSpace)                  (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_viewSpace_MASK)) | (((ObjectFlags)(viewSpace)) << OBJECTFLAGS_viewSpace_SHIFT)
#define OBJECTFLAGS_ownMesh_SHIFT                        2
#define OBJECTFLAGS_ownMesh_MASK                         0x4
#define OBJECTFLAGS_ownMesh(x)                           ((((ObjectFlags)(x)) & OBJECTFLAGS_ownMesh_MASK) >> OBJECTFLAGS_ownMesh_SHIFT)
#define OBJECTFLAGS_SET_ownMesh(x, ownMesh)                    (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_ownMesh_MASK)) | (((ObjectFlags)(ownMesh)) << OBJECTFLAGS_ownMesh_SHIFT)
#define OBJECTFLAGS_translucent_SHIFT                    3
#define OBJECTFLAGS_translucent_MASK                     0x8
#define OBJECTFLAGS_translucent(x)                       ((((ObjectFlags)(x)) & OBJECTFLAGS_translucent_MASK) >> OBJECTFLAGS_translucent_SHIFT)
#define OBJECTFLAGS_SET_translucent(x, translucent)                (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_translucent_MASK)) | (((ObjectFlags)(translucent)) << OBJECTFLAGS_translucent_SHIFT)
#define OBJECTFLAGS_flipWindings_SHIFT                   4
#define OBJECTFLAGS_flipWindings_MASK                    0x10
#define OBJECTFLAGS_flipWindings(x)                      ((((ObjectFlags)(x)) & OBJECTFLAGS_flipWindings_MASK) >> OBJECTFLAGS_flipWindings_SHIFT)
#define OBJECTFLAGS_SET_flipWindings(x, flipWindings)               (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_flipWindings_MASK)) | (((ObjectFlags)(flipWindings)) << OBJECTFLAGS_flipWindings_SHIFT)
#define OBJECTFLAGS_keysLoaded_SHIFT                     5
#define OBJECTFLAGS_keysLoaded_MASK                      0x20
#define OBJECTFLAGS_keysLoaded(x)                        ((((ObjectFlags)(x)) & OBJECTFLAGS_keysLoaded_MASK) >> OBJECTFLAGS_keysLoaded_SHIFT)
#define OBJECTFLAGS_SET_keysLoaded(x, keysLoaded)                 (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_keysLoaded_MASK)) | (((ObjectFlags)(keysLoaded)) << OBJECTFLAGS_keysLoaded_SHIFT)
#define OBJECTFLAGS_transform_SHIFT                      6
#define OBJECTFLAGS_transform_MASK                       0x40
#define OBJECTFLAGS_transform(x)                         ((((ObjectFlags)(x)) & OBJECTFLAGS_transform_MASK) >> OBJECTFLAGS_transform_SHIFT)
#define OBJECTFLAGS_SET_transform(x, transform)                  (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_transform_MASK)) | (((ObjectFlags)(transform)) << OBJECTFLAGS_transform_SHIFT)
#define OBJECTFLAGS_mesh_SHIFT                           7
#define OBJECTFLAGS_mesh_MASK                            0x80
#define OBJECTFLAGS_mesh(x)                              ((((ObjectFlags)(x)) & OBJECTFLAGS_mesh_MASK) >> OBJECTFLAGS_mesh_SHIFT)
#define OBJECTFLAGS_SET_mesh(x, mesh)                       (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_mesh_MASK)) | (((ObjectFlags)(mesh)) << OBJECTFLAGS_mesh_SHIFT)
#define OBJECTFLAGS_light_SHIFT                          8
#define OBJECTFLAGS_light_MASK                           0x100
#define OBJECTFLAGS_light(x)                             ((((ObjectFlags)(x)) & OBJECTFLAGS_light_MASK) >> OBJECTFLAGS_light_SHIFT)
#define OBJECTFLAGS_SET_light(x, light)                      (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_light_MASK)) | (((ObjectFlags)(light)) << OBJECTFLAGS_light_SHIFT)
#define OBJECTFLAGS_camera_SHIFT                         9
#define OBJECTFLAGS_camera_MASK                          0x200
#define OBJECTFLAGS_camera(x)                            ((((ObjectFlags)(x)) & OBJECTFLAGS_camera_MASK) >> OBJECTFLAGS_camera_SHIFT)
#define OBJECTFLAGS_SET_camera(x, camera)                     (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_camera_MASK)) | (((ObjectFlags)(camera)) << OBJECTFLAGS_camera_SHIFT)
#define OBJECTFLAGS_localMatrixSet_SHIFT                 10
#define OBJECTFLAGS_localMatrixSet_MASK                  0x400
#define OBJECTFLAGS_localMatrixSet(x)                    ((((ObjectFlags)(x)) & OBJECTFLAGS_localMatrixSet_MASK) >> OBJECTFLAGS_localMatrixSet_SHIFT)
#define OBJECTFLAGS_SET_localMatrixSet(x, localMatrixSet)             (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_localMatrixSet_MASK)) | (((ObjectFlags)(localMatrixSet)) << OBJECTFLAGS_localMatrixSet_SHIFT)
#define OBJECTFLAGS_computeLightVectors_SHIFT            11
#define OBJECTFLAGS_computeLightVectors_MASK             0x800
#define OBJECTFLAGS_computeLightVectors(x)               ((((ObjectFlags)(x)) & OBJECTFLAGS_computeLightVectors_MASK) >> OBJECTFLAGS_computeLightVectors_SHIFT)
#define OBJECTFLAGS_SET_computeLightVectors(x, computeLightVectors)        (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_computeLightVectors_MASK)) | (((ObjectFlags)(computeLightVectors)) << OBJECTFLAGS_computeLightVectors_SHIFT)
#define OBJECTFLAGS_hierarchy_SHIFT                      16
#define OBJECTFLAGS_hierarchy_MASK                       0xFFFF0000
#define OBJECTFLAGS_hierarchy(x)                         ((((ObjectFlags)(x)) & OBJECTFLAGS_hierarchy_MASK) >> OBJECTFLAGS_hierarchy_SHIFT)
#define OBJECTFLAGS_SET_hierarchy(x, hierarchy)                  (x) = ((ObjectFlags)(x) & ~((ObjectFlags)OBJECTFLAGS_hierarchy_MASK)) | (((ObjectFlags)(hierarchy)) << OBJECTFLAGS_hierarchy_SHIFT)


struct C(Plane)
{
   union
   {
      struct
      {
         double a;
         double b;
         double c;
      };
      C(Vector3D) normal;
   };
   double d;
};
extern void (* Plane_fromPointNormal)(C(Plane) * __this, C(Vector3D) * normal, C(Vector3D) * point);

extern void (* Plane_fromPoints)(C(Plane) * __this, C(Vector3D) * v1, C(Vector3D) * v2, C(Vector3D) * v3);

extern void (* Plane_fromPointsf)(C(Plane) * __this, C(Vector3Df) * v1, C(Vector3Df) * v2, C(Vector3Df) * v3);

extern void (* Plane_intersectLine)(C(Plane) * __this, C(Line) * line, C(Vector3D) * result);

extern void (* Plane_intersectLinef)(C(Plane) * __this, C(Line) * line, C(Vector3Df) * result);

extern void (* Plane_multMatrix)(C(Plane) * __this, C(Plane) * source, C(Matrix) * inverseTranspose);

#define PRIMITIVEGROUPTYPE_primitiveType_SHIFT           0
#define PRIMITIVEGROUPTYPE_primitiveType_MASK            0xFF
#define PRIMITIVEGROUPTYPE_primitiveType(x)              ((((PrimitiveGroupType)(x)) & PRIMITIVEGROUPTYPE_primitiveType_MASK) >> PRIMITIVEGROUPTYPE_primitiveType_SHIFT)
#define PRIMITIVEGROUPTYPE_SET_primitiveType(x, primitiveType)       (x) = ((PrimitiveGroupType)(x) & ~((PrimitiveGroupType)PRIMITIVEGROUPTYPE_primitiveType_MASK)) | (((PrimitiveGroupType)(primitiveType)) << PRIMITIVEGROUPTYPE_primitiveType_SHIFT)
#define PRIMITIVEGROUPTYPE_vertexRange_SHIFT             8
#define PRIMITIVEGROUPTYPE_vertexRange_MASK              0x100
#define PRIMITIVEGROUPTYPE_vertexRange(x)                ((((PrimitiveGroupType)(x)) & PRIMITIVEGROUPTYPE_vertexRange_MASK) >> PRIMITIVEGROUPTYPE_vertexRange_SHIFT)
#define PRIMITIVEGROUPTYPE_SET_vertexRange(x, vertexRange)         (x) = ((PrimitiveGroupType)(x) & ~((PrimitiveGroupType)PRIMITIVEGROUPTYPE_vertexRange_MASK)) | (((PrimitiveGroupType)(vertexRange)) << PRIMITIVEGROUPTYPE_vertexRange_SHIFT)
#define PRIMITIVEGROUPTYPE_indices32bit_SHIFT            9
#define PRIMITIVEGROUPTYPE_indices32bit_MASK             0x200
#define PRIMITIVEGROUPTYPE_indices32bit(x)               ((((PrimitiveGroupType)(x)) & PRIMITIVEGROUPTYPE_indices32bit_MASK) >> PRIMITIVEGROUPTYPE_indices32bit_SHIFT)
#define PRIMITIVEGROUPTYPE_SET_indices32bit(x, indices32bit)        (x) = ((PrimitiveGroupType)(x) & ~((PrimitiveGroupType)PRIMITIVEGROUPTYPE_indices32bit_MASK)) | (((PrimitiveGroupType)(indices32bit)) << PRIMITIVEGROUPTYPE_indices32bit_SHIFT)
#define PRIMITIVEGROUPTYPE(primitiveType, vertexRange, indices32bit)                      (((((PrimitiveGroupType)(primitiveType)) << PRIMITIVEGROUPTYPE_primitiveType_SHIFT) | ((PrimitiveGroupType)(vertexRange)) << PRIMITIVEGROUPTYPE_vertexRange_SHIFT) | ((PrimitiveGroupType)(indices32bit)) << PRIMITIVEGROUPTYPE_indices32bit_SHIFT)


struct C(PrimitiveSingle)
{
   C(PrimitiveGroupType) type;
   union
   {
      struct
      {
         union
         {
            uint16 * indices;
            uint * indices32;
         };
         int nIndices;
      };
      struct
      {
         int first;
         int nVertices;
      };
   };
   C(Material) * material;
};
extern void (* Quaternion_divide)(C(Quaternion) * __this, C(Quaternion) * q1, C(Quaternion) * q2);

extern void (* Quaternion_identity)(C(Quaternion) * __this);

extern void (* Quaternion_inverse)(C(Quaternion) * __this, C(Quaternion) * source);

extern void (* Quaternion_multiply)(C(Quaternion) * __this, C(Quaternion) * q1, C(Quaternion) * q2);

extern void (* Quaternion_normalize)(C(Quaternion) * __this, C(Quaternion) * source);

extern void (* Quaternion_pitch)(C(Quaternion) * __this, C(Angle) angle);

extern void (* Quaternion_roll)(C(Quaternion) * __this, C(Angle) angle);

extern void (* Quaternion_rotatePitch)(C(Quaternion) * __this, C(Angle) pitch);

extern void (* Quaternion_rotateRoll)(C(Quaternion) * __this, C(Angle) roll);

extern void (* Quaternion_rotateYaw)(C(Quaternion) * __this, C(Angle) yaw);

extern void (* Quaternion_rotateYawPitch)(C(Quaternion) * __this, C(Angle) yaw, C(Angle) pitch);

extern void (* Quaternion_rotationAxis)(C(Quaternion) * __this, C(Vector3D) * axis, C(Angle) angle);

extern void (* Quaternion_rotationDirection)(C(Quaternion) * __this, C(Vector3D) * direction);

extern void (* Quaternion_rotationMatrix)(C(Quaternion) * __this, C(Matrix) * m);

extern void (* Quaternion_rotationYawPitchRoll)(C(Quaternion) * __this, C(Euler) * euler);

extern void (* Quaternion_slerp)(C(Quaternion) * __this, C(Quaternion) * from, C(Quaternion) * to, float t);

extern void (* Quaternion_toDirection)(C(Quaternion) * __this, C(Vector3D) * direction);

extern void (* Quaternion_yaw)(C(Quaternion) * __this, C(Angle) angle);

extern void (* Quaternion_yawPitch)(C(Quaternion) * __this, C(Angle) yaw, C(Angle) pitch);

extern void (* Vector3D_add)(C(Vector3D) * __this, C(Vector3D) * vector1, C(Vector3D) * vector2);

extern void (* Vector3D_crossProduct)(C(Vector3D) * __this, C(Vector3D) * vector1, C(Vector3D) * vector2);

extern void (* Vector3D_divideMatrix)(C(Vector3D) * __this, C(Vector3D) * source, C(Matrix) * matrix);

extern double (* Vector3D_dotProduct)(C(Vector3D) * __this, C(Vector3D) * vector2);

extern double (* Vector3D_dotProductf)(C(Vector3D) * __this, C(Vector3Df) * vector2);

extern void (* Vector3D_multMatrix)(C(Vector3D) * __this, C(Vector3D) * source, C(Matrix) * matrix);

extern void (* Vector3D_multMatrixf)(C(Vector3D) * __this, C(Vector3Df) * source, C(Matrix) * matrix);

extern void (* Vector3D_normalize)(C(Vector3D) * __this, C(Vector3D) * source);

extern void (* Vector3D_scale)(C(Vector3D) * __this, C(Vector3D) * vector1, double s);

extern void (* Vector3D_subtract)(C(Vector3D) * __this, C(Vector3D) * vector1, C(Vector3D) * vector2);

extern C(Property) * PROPERTY(Vector3D, length);
extern double (* Vector3D_get_length)(C(Vector3D) v);

extern C(Property) * PROPERTY(Vector3D, lengthApprox);
extern double (* Vector3D_get_lengthApprox)(C(Vector3D) v);

extern void (* Vector3Df_add)(C(Vector3Df) * __this, C(Vector3Df) * vector1, C(Vector3Df) * vector2);

extern void (* Vector3Df_crossProduct)(C(Vector3Df) * __this, C(Vector3Df) * vector1, C(Vector3Df) * vector2);

extern void (* Vector3Df_divideMatrix)(C(Vector3Df) * __this, C(Vector3Df) * source, C(Matrix) * matrix);

extern double (* Vector3Df_dotProduct)(C(Vector3Df) * __this, C(Vector3Df) * vector2);

extern void (* Vector3Df_multMatrix)(C(Vector3Df) * __this, C(Vector3Df) * source, C(Matrix) * matrix);

extern void (* Vector3Df_normalize)(C(Vector3Df) * __this, C(Vector3Df) * source);

extern void (* Vector3Df_scale)(C(Vector3Df) * __this, C(Vector3Df) * vector1, float s);

extern void (* Vector3Df_subtract)(C(Vector3Df) * __this, C(Vector3Df) * vector1, C(Vector3Df) * vector2);

extern C(Property) * PROPERTY(Vector3Df, length);
extern float (* Vector3Df_get_length)(C(Vector3Df) v);

extern C(Property) * PROPERTY(Vector3Df, lengthApprox);
extern float (* Vector3Df_get_lengthApprox)(C(Vector3Df) v);

extern float (* fastInvSqrt)(float x);
extern double (* fastInvSqrtDouble)(double x);

// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||gfx  ////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
typedef struct C(OldList) C(Extent);
typedef C(Instance) C(Surface);
typedef C(Instance) C(Resource);
#if CPP11
enum C(RenderState) : int
#else
typedef int C(RenderState);
enum C(RenderState)
#endif
{
   RenderState_fillMode = 0x1,
   RenderState_depthTest = 0x2,
   RenderState_depthWrite = 0x3,
   RenderState_fogDensity = 0x4,
   RenderState_fogColor = 0x5,
   RenderState_blend = 0x6,
   RenderState_ambient = 0x7,
   RenderState_alphaWrite = 0x8,
   RenderState_antiAlias = 0x9,
   RenderState_vSync = 0xA
};

typedef struct C(HitRecord) C(HitRecord);
struct C(HitRecord)
{
   C(HitRecord) * prev;
   C(HitRecord) * next;
   uint pos;
   uint numTags;
   C(Vector3D) center;
   void * tags[1];
};
#if CPP11
enum C(GradientDirection) : int
#else
typedef int C(GradientDirection);
enum C(GradientDirection)
#endif
{
   GradientDirection_vertical = 0x0,
   GradientDirection_horizontal = 0x1
};

typedef uint32 C(GLCapabilities);
typedef C(Resource) C(FontResource);
typedef C(Instance) C(FontManagerRenderer);
typedef C(FontManagerRenderer) C(FontRenderer);
typedef C(Instance) C(FontManager);
struct CM(FontManagerRenderer)
{
   C(FontManager) fm;
};
typedef uint32 C(FontFlags);
typedef struct C(Font) C(Font);
#if CPP11
enum C(FillModeValue) : int
#else
typedef int C(FillModeValue);
enum C(FillModeValue)
#endif
{
   FillModeValue_solid = 0x0,
   FillModeValue_wireframe = 0x1
};

typedef struct C(FMPathDraw) C(FMPathDraw);
struct C(FMFont)
{
   C(LinkElement) link;
};
typedef struct C(FMFont) C(FMFont);
typedef C(Instance) C(DrawManager);
typedef struct C(DisplaySystemResPtr) C(DisplaySystemResPtr);
struct CM(Display)
{
   int width;
   int height;
   void * driverData;
};
typedef C(Instance) C(Display);
typedef struct C(ColorKey) C(ColorKey);
typedef uint32 C(Color);
#if CPP11
enum C(ClearType) : int
#else
typedef int C(ClearType);
enum C(ClearType)
#endif
{
   ClearType_colorBuffer = 0x0,
   ClearType_depthBuffer = 0x1,
   ClearType_colorAndDepth = 0x2
};

#if CPP11
enum C(AlphaWriteMode) : int
#else
typedef int C(AlphaWriteMode);
enum C(AlphaWriteMode)
#endif
{
   AlphaWriteMode_dontWrite = 0x0,
   AlphaWriteMode_write = 0x1,
   AlphaWriteMode_blend = 0x2
};

// end -- moved backwards outputs
#define NumberOfLights (8)

typedef C(Instance) C(BitmapFormat);
typedef C(Resource) C(BitmapResource);
typedef uint32 C(Color444);
typedef uint32 C(Color555);
typedef uint32 C(Color565);
typedef struct C(ColorCMYK) C(ColorCMYK);
typedef struct C(ColorHSV) C(ColorHSV);
typedef struct C(ColorLab) C(ColorLab);
typedef uint32 C(ColorRGBA);
#if CPP11
enum C(DefinedColor) : uint
#else
typedef C(Color) C(DefinedColor);
enum C(DefinedColor)
#endif
{
   DefinedColor_black = 0x0,
   DefinedColor_dimGray = 0x696969,
   DefinedColor_gray = 0x808080,
   DefinedColor_darkGray = 0xA9A9A5,
   DefinedColor_silver = 0xC0C0C0,
   DefinedColor_lightGray = 0xD3D3D3,
   DefinedColor_gainsboro = 0xDCDCDC,
   DefinedColor_whiteSmoke = 0xF5F5F5,
   DefinedColor_white = 0xFFFFFF,
   DefinedColor_rosyBrown = 0xBC8F8F,
   DefinedColor_indianRed = 0xCD5C5C,
   DefinedColor_brown = 0xA52A2A,
   DefinedColor_fireBrick = 0xB22222,
   DefinedColor_lightCoral = 0xF08080,
   DefinedColor_maroon = 0x800000,
   DefinedColor_darkRed = 0x8B0000,
   DefinedColor_red = 0xFF0000,
   DefinedColor_snow = 0xFFFAFA,
   DefinedColor_mistyRose = 0xFFE4E1,
   DefinedColor_salmon = 0xFA8072,
   DefinedColor_tomato = 0xFF6347,
   DefinedColor_darkSalmon = 0xE9967A,
   DefinedColor_coral = 0xFF7F50,
   DefinedColor_orangeRed = 0xFF4500,
   DefinedColor_lightSalmon = 0xFFA07A,
   DefinedColor_sienna = 0xA0522D,
   DefinedColor_seaShell = 0xFFF5EE,
   DefinedColor_chocolate = 0xD2691E,
   DefinedColor_saddleBrown = 0x8B4513,
   DefinedColor_sandyBrown = 0xF4A460,
   DefinedColor_peachPuff = 0xFFDAB9,
   DefinedColor_peru = 0xCD853F,
   DefinedColor_linen = 0xFAF0E6,
   DefinedColor_bisque = 0xFFE4C4,
   DefinedColor_darkOrange = 0xFF8C00,
   DefinedColor_burlyWood = 0xDEB887,
   DefinedColor_tan = 0xD2B48C,
   DefinedColor_antiqueWhite = 0xFAEBD7,
   DefinedColor_navajoWhite = 0xFFDEAD,
   DefinedColor_blanchedAlmond = 0xFFEBCD,
   DefinedColor_papayaWhip = 0xFFEFD5,
   DefinedColor_mocassin = 0xFFE4B5,
   DefinedColor_orange = 0xFFA500,
   DefinedColor_wheat = 0xF5DEB3,
   DefinedColor_oldLace = 0xFDF5E6,
   DefinedColor_floralWhite = 0xFFFAF0,
   DefinedColor_darkGoldenrod = 0xB8860B,
   DefinedColor_goldenrod = 0xDAA520,
   DefinedColor_cornsilk = 0xFFF8DC,
   DefinedColor_gold = 0xFFD700,
   DefinedColor_khaki = 0xF0E68C,
   DefinedColor_lemonChiffon = 0xFFFACD,
   DefinedColor_paleGoldenrod = 0xEEE8AA,
   DefinedColor_darkKhaki = 0xBDB76B,
   DefinedColor_beige = 0xF5F5DC,
   DefinedColor_lightGoldenRodYellow = 0xFAFAD2,
   DefinedColor_olive = 0x808000,
   DefinedColor_yellow = 0xFFFF00,
   DefinedColor_lightYellow = 0xFFFFE0,
   DefinedColor_ivory = 0xFFFFF0,
   DefinedColor_oliveDrab = 0x6B8E23,
   DefinedColor_yellowGreen = 0x9ACD32,
   DefinedColor_darkOliveGreen = 0x556B2F,
   DefinedColor_greenYellow = 0xADFF2F,
   DefinedColor_chartreuse = 0x7FFF00,
   DefinedColor_lawnGreen = 0x7CFC00,
   DefinedColor_darkSeaGreen = 0x8FBC8B,
   DefinedColor_forestGreen = 0x228B22,
   DefinedColor_limeGreen = 0x32CD32,
   DefinedColor_lightGreen = 0x90EE90,
   DefinedColor_paleGreen = 0x98FB98,
   DefinedColor_darkGreen = 0x6400,
   DefinedColor_green = 0x8000,
   DefinedColor_lime = 0xFF00,
   DefinedColor_honeyDew = 0xF0FFF0,
   DefinedColor_seaGreen = 0x2E8B57,
   DefinedColor_mediumSeaGreen = 0x3CB371,
   DefinedColor_springGreen = 0xFF7F,
   DefinedColor_mintCream = 0xF5FFFA,
   DefinedColor_mediumSpringGreen = 0xFA9A,
   DefinedColor_mediumAquaMarine = 0x66CDAA,
   DefinedColor_aquamarine = 0x7FFFD4,
   DefinedColor_turquoise = 0x40E0D0,
   DefinedColor_lightSeaGreen = 0x20B2AA,
   DefinedColor_mediumTurquoise = 0x48D1CC,
   DefinedColor_darkSlateGray = 0x2F4F4F,
   DefinedColor_paleTurquoise = 0xAFEEEE,
   DefinedColor_teal = 0x8080,
   DefinedColor_darkCyan = 0x8B8B,
   DefinedColor_aqua = 0xFFFF,
   DefinedColor_cyan = 0xFFFF,
   DefinedColor_lightCyan = 0xE0FFFF,
   DefinedColor_azure = 0xF0FFFF,
   DefinedColor_darkTurquoise = 0xCED1,
   DefinedColor_cadetBlue = 0x5F9EA0,
   DefinedColor_powderBlue = 0xB0E0E6,
   DefinedColor_lightBlue = 0xADD8E6,
   DefinedColor_deepSkyBlue = 0xBFFF,
   DefinedColor_skyBlue = 0x87CEEB,
   DefinedColor_lightSkyBlue = 0x87CEFA,
   DefinedColor_steelBlue = 0x4682B4,
   DefinedColor_aliceBlue = 0xF0F8FF,
   DefinedColor_dodgerBlue = 0x1E90FF,
   DefinedColor_slateGray = 0x708090,
   DefinedColor_lightSlateGray = 0x778899,
   DefinedColor_lightSteelBlue = 0xB0C4DE,
   DefinedColor_cornflowerBlue = 0x6495ED,
   DefinedColor_royalBlue = 0x4169E1,
   DefinedColor_midnightBlue = 0x191970,
   DefinedColor_lavender = 0xE6E6FA,
   DefinedColor_navy = 0x80,
   DefinedColor_darkBlue = 0x8B,
   DefinedColor_mediumBlue = 0xCD,
   DefinedColor_blue = 0xFF,
   DefinedColor_ghostWhite = 0xF8F8FF,
   DefinedColor_slateBlue = 0x6A5ACD,
   DefinedColor_darkSlateBlue = 0x483D8B,
   DefinedColor_mediumSlateBlue = 0x7B68EE,
   DefinedColor_mediumPurple = 0x9370DB,
   DefinedColor_blueViolet = 0x8A2BE2,
   DefinedColor_indigo = 0x4B0082,
   DefinedColor_darkOrchid = 0x9932CC,
   DefinedColor_darkViolet = 0x9400D3,
   DefinedColor_mediumOrchid = 0xBA55D3,
   DefinedColor_thistle = 0xD8BFD8,
   DefinedColor_plum = 0xDDA0DD,
   DefinedColor_violet = 0xEE82EE,
   DefinedColor_purple = 0x800080,
   DefinedColor_darkMagenta = 0x8B008B,
   DefinedColor_magenta = 0xFF00FF,
   DefinedColor_fuschia = 0xFF00FF,
   DefinedColor_orchid = 0xDA70D6,
   DefinedColor_mediumVioletRed = 0xC71585,
   DefinedColor_deepPink = 0xFF1493,
   DefinedColor_hotPink = 0xFF9BB4,
   DefinedColor_lavenderBlush = 0xFFF0F5,
   DefinedColor_paleVioletRed = 0xDB7093,
   DefinedColor_crimson = 0xDC143C,
   DefinedColor_pink = 0xFFC0CB,
   DefinedColor_lightPink = 0xFFB6C1
};

typedef C(Instance) C(DisplayDriver);
typedef uint32 C(FMTextAlignment);
#if CPP11
enum C(FMVerticalAlignment) : int
#else
typedef int C(FMVerticalAlignment);
enum C(FMVerticalAlignment)
#endif
{
   FMVerticalAlignment_baseline = 0x0,
   FMVerticalAlignment_top = 0x1,
   FMVerticalAlignment_middle = 0x2,
   FMVerticalAlignment_bottom = 0x3
};

typedef struct C(FaceInfo) C(FaceInfo);
typedef struct C(FontInfo) C(FontInfo);
typedef struct C(RenderStateFloat) C(RenderStateFloat);
#if CPP11
enum C(Resolution) : int
#else
typedef int C(Resolution);
enum C(Resolution)
#endif
{
   Resolution_resText80x25 = 0x0,
   Resolution_res320x200 = 0x1,
   Resolution_res320x240 = 0x2,
   Resolution_res320x400 = 0x3,
   Resolution_res360x480 = 0x4,
   Resolution_res400x256 = 0x5,
   Resolution_res400x300 = 0x6,
   Resolution_res512x256 = 0x7,
   Resolution_res512x384 = 0x8,
   Resolution_res640x200 = 0x9,
   Resolution_res640x350 = 0xA,
   Resolution_res640x400 = 0xB,
   Resolution_res640x480 = 0xC,
   Resolution_res720x348 = 0xD,
   Resolution_res800x600 = 0xE,
   Resolution_res856x480 = 0xF,
   Resolution_res960x720 = 0x10,
   Resolution_res1024x768 = 0x11,
   Resolution_res1152x864 = 0x12,
   Resolution_res1280x1024 = 0x13,
   Resolution_res1600x1200 = 0x14,
   Resolution_res768x480 = 0x15
};

#if CPP11
enum C(SystemColor) : uint
#else
typedef C(Color) C(SystemColor);
enum C(SystemColor)
#endif
{
   SystemColor_formColor = 0xE5EAF5,
   SystemColor_activeBorder = 0xE5EAF5,
   SystemColor_control = 0xD4D0C8,
   SystemColor_controlLight = 0xD4D0C8,
   SystemColor_inactiveBorder = 0xD4D0C8,
   SystemColor_inactiveCaptionText = 0xD4D0C8,
   SystemColor_menu = 0xD4D0C8,
   SystemColor_scrollBar = 0xD4D0C8
};

extern C(bool) (* Bitmap_allocate)(C(Bitmap) __this, const char * driverName, int width, int height, int stride, C(PixelFormat) format, C(bool) allocatePalette);

extern C(bool) (* Bitmap_allocateDD)(C(Bitmap) __this, C(DisplaySystem) displaySystem, int width, int height);

extern C(bool) (* Bitmap_convert)(C(Bitmap) __this, C(DisplaySystem) displaySystem, C(PixelFormat) format, C(ColorAlpha) * palette);

extern C(bool) (* Bitmap_copy)(C(Bitmap) __this, C(Bitmap) source);

extern void (* Bitmap_free)(C(Bitmap) __this);

extern C(Surface) (* Bitmap_getSurface)(C(Bitmap) __this, int x, int y, C(Box) * clip);

extern void (* Bitmap_grab)(C(Bitmap) __this, C(Bitmap) src, int x, int y);

extern C(bool) (* Bitmap_load)(C(Bitmap) __this, const char * fileName, const char * type, C(DisplaySystem) displaySystem);

extern C(bool) (* Bitmap_loadFromFile)(C(Bitmap) __this, C(File) file, const char * type, C(DisplaySystem) displaySystem);

extern C(bool) (* Bitmap_loadGrayed)(C(Bitmap) __this, const char * fileName, const char * type, C(DisplaySystem) displaySystem);

extern C(bool) (* Bitmap_loadMipMaps)(C(Bitmap) __this, const char * fileName, const char * type, C(DisplaySystem) displaySystem);

extern C(bool) (* Bitmap_loadMonochrome)(C(Bitmap) __this, const char * fileName, const char * type, C(DisplaySystem) displaySystem);

extern C(bool) (* Bitmap_loadT)(C(Bitmap) __this, const char * fileName, const char * type, C(DisplaySystem) displaySystem);

extern C(bool) (* Bitmap_loadTMipMaps)(C(Bitmap) __this, const char * fileName, const char * type, C(DisplaySystem) displaySystem);

extern C(bool) (* Bitmap_makeDD)(C(Bitmap) __this, C(DisplaySystem) displaySystem);

extern C(bool) (* Bitmap_makeMipMaps)(C(Bitmap) __this, C(DisplaySystem) displaySystem);

extern C(ColorAlpha) * (* Bitmap_quantize)(C(Bitmap) __this, uint start, uint end);

extern C(bool) (* Bitmap_save)(C(Bitmap) __this, const char * fileName, const char * type, void * options);

extern void (* Bitmap_smoothEdges)(C(Bitmap) __this, int size);

extern C(Property) * PROPERTY(BitmapResource, fileName);
extern void (* BitmapResource_set_fileName)(C(BitmapResource) b, const char * value);
extern const char * (* BitmapResource_get_fileName)(C(BitmapResource) b);

extern C(Property) * PROPERTY(BitmapResource, grayed);
extern void (* BitmapResource_set_grayed)(C(BitmapResource) b, C(bool) value);
extern C(bool) (* BitmapResource_get_grayed)(C(BitmapResource) b);

extern C(Property) * PROPERTY(BitmapResource, monochrome);
extern void (* BitmapResource_set_monochrome)(C(BitmapResource) b, C(bool) value);
extern C(bool) (* BitmapResource_get_monochrome)(C(BitmapResource) b);

extern C(Property) * PROPERTY(BitmapResource, transparent);
extern void (* BitmapResource_set_transparent)(C(BitmapResource) b, C(bool) value);
extern C(bool) (* BitmapResource_get_transparent)(C(BitmapResource) b);
extern bool (* BitmapResource_isSet_transparent)(C(BitmapResource) b);

extern C(Property) * PROPERTY(BitmapResource, alphaBlend);
extern void (* BitmapResource_set_alphaBlend)(C(BitmapResource) b, C(bool) value);
extern C(bool) (* BitmapResource_get_alphaBlend)(C(BitmapResource) b);
extern bool (* BitmapResource_isSet_alphaBlend)(C(BitmapResource) b);

extern C(Property) * PROPERTY(BitmapResource, mipMaps);
extern void (* BitmapResource_set_mipMaps)(C(BitmapResource) b, C(bool) value);
extern C(bool) (* BitmapResource_get_mipMaps)(C(BitmapResource) b);
extern bool (* BitmapResource_isSet_mipMaps)(C(BitmapResource) b);

extern C(Property) * PROPERTY(BitmapResource, keepData);
extern void (* BitmapResource_set_keepData)(C(BitmapResource) b, C(bool) value);
extern C(bool) (* BitmapResource_get_keepData)(C(BitmapResource) b);

extern C(Property) * PROPERTY(BitmapResource, bitmap);
extern void (* BitmapResource_set_bitmap)(C(BitmapResource) b, C(Bitmap) value);
extern C(Bitmap) (* BitmapResource_get_bitmap)(C(BitmapResource) b);

extern C(Property) * PROPERTY(BitmapResource, window);
extern void (* BitmapResource_set_window)(C(BitmapResource) b, C(Window) value);

#define COLOR_r_SHIFT                                    16
#define COLOR_r_MASK                                     0xFF0000
#define COLOR_r(x)                                       ((((Color)(x)) & COLOR_r_MASK) >> COLOR_r_SHIFT)
#define COLOR_SET_r(x, r)                                (x) = ((Color)(x) & ~((Color)COLOR_r_MASK)) | (((Color)(r)) << COLOR_r_SHIFT)
#define COLOR_g_SHIFT                                    8
#define COLOR_g_MASK                                     0xFF00
#define COLOR_g(x)                                       ((((Color)(x)) & COLOR_g_MASK) >> COLOR_g_SHIFT)
#define COLOR_SET_g(x, g)                                (x) = ((Color)(x) & ~((Color)COLOR_g_MASK)) | (((Color)(g)) << COLOR_g_SHIFT)
#define COLOR_b_SHIFT                                    0
#define COLOR_b_MASK                                     0xFF
#define COLOR_b(x)                                       ((((Color)(x)) & COLOR_b_MASK) >> COLOR_b_SHIFT)
#define COLOR_SET_b(x, b)                                (x) = ((Color)(x) & ~((Color)COLOR_b_MASK)) | (((Color)(b)) << COLOR_b_SHIFT)
#define COLOR(r, g, b)                                   (((((Color)(r)) << COLOR_r_SHIFT) | ((Color)(g)) << COLOR_g_SHIFT) | ((Color)(b)) << COLOR_b_SHIFT)


extern C(Property) * PROPERTY(Color, ColorRGB);
extern C(Color) (* Color_from_ColorRGB)(C(ColorRGB) colorRGB);
extern void (* Color_to_ColorRGB)(C(Color) color, C(ColorRGB) * value);

#define COLOR444_r_SHIFT                                 8
#define COLOR444_r_MASK                                  0xF00
#define COLOR444_r(x)                                    ((((Color444)(x)) & COLOR444_r_MASK) >> COLOR444_r_SHIFT)
#define COLOR444_SET_r(x, r)                             (x) = ((Color444)(x) & ~((Color444)COLOR444_r_MASK)) | (((Color444)(r)) << COLOR444_r_SHIFT)
#define COLOR444_g_SHIFT                                 4
#define COLOR444_g_MASK                                  0xF0
#define COLOR444_g(x)                                    ((((Color444)(x)) & COLOR444_g_MASK) >> COLOR444_g_SHIFT)
#define COLOR444_SET_g(x, g)                             (x) = ((Color444)(x) & ~((Color444)COLOR444_g_MASK)) | (((Color444)(g)) << COLOR444_g_SHIFT)
#define COLOR444_b_SHIFT                                 0
#define COLOR444_b_MASK                                  0xF
#define COLOR444_b(x)                                    ((((Color444)(x)) & COLOR444_b_MASK) >> COLOR444_b_SHIFT)
#define COLOR444_SET_b(x, b)                             (x) = ((Color444)(x) & ~((Color444)COLOR444_b_MASK)) | (((Color444)(b)) << COLOR444_b_SHIFT)
#define COLOR444(r, g, b)                                (((((Color444)(r)) << COLOR444_r_SHIFT) | ((Color444)(g)) << COLOR444_g_SHIFT) | ((Color444)(b)) << COLOR444_b_SHIFT)


extern C(Property) * PROPERTY(Color444, Color);
extern C(Color444) (* Color444_from_Color)(C(Color) color);
extern C(Color) (* Color444_to_Color)(C(Color444) color444);

#define COLOR555_r_SHIFT                                 10
#define COLOR555_r_MASK                                  0x7C00
#define COLOR555_r(x)                                    ((((Color555)(x)) & COLOR555_r_MASK) >> COLOR555_r_SHIFT)
#define COLOR555_SET_r(x, r)                             (x) = ((Color555)(x) & ~((Color555)COLOR555_r_MASK)) | (((Color555)(r)) << COLOR555_r_SHIFT)
#define COLOR555_g_SHIFT                                 5
#define COLOR555_g_MASK                                  0x3E0
#define COLOR555_g(x)                                    ((((Color555)(x)) & COLOR555_g_MASK) >> COLOR555_g_SHIFT)
#define COLOR555_SET_g(x, g)                             (x) = ((Color555)(x) & ~((Color555)COLOR555_g_MASK)) | (((Color555)(g)) << COLOR555_g_SHIFT)
#define COLOR555_b_SHIFT                                 0
#define COLOR555_b_MASK                                  0x1F
#define COLOR555_b(x)                                    ((((Color555)(x)) & COLOR555_b_MASK) >> COLOR555_b_SHIFT)
#define COLOR555_SET_b(x, b)                             (x) = ((Color555)(x) & ~((Color555)COLOR555_b_MASK)) | (((Color555)(b)) << COLOR555_b_SHIFT)
#define COLOR555(r, g, b)                                (((((Color555)(r)) << COLOR555_r_SHIFT) | ((Color555)(g)) << COLOR555_g_SHIFT) | ((Color555)(b)) << COLOR555_b_SHIFT)


extern C(Property) * PROPERTY(Color555, Color);
extern C(Color555) (* Color555_from_Color)(C(Color) color);
extern C(Color) (* Color555_to_Color)(C(Color555) color555);

#define COLOR565_r_SHIFT                                 11
#define COLOR565_r_MASK                                  0xF800
#define COLOR565_r(x)                                    ((((Color565)(x)) & COLOR565_r_MASK) >> COLOR565_r_SHIFT)
#define COLOR565_SET_r(x, r)                             (x) = ((Color565)(x) & ~((Color565)COLOR565_r_MASK)) | (((Color565)(r)) << COLOR565_r_SHIFT)
#define COLOR565_g_SHIFT                                 5
#define COLOR565_g_MASK                                  0x7E0
#define COLOR565_g(x)                                    ((((Color565)(x)) & COLOR565_g_MASK) >> COLOR565_g_SHIFT)
#define COLOR565_SET_g(x, g)                             (x) = ((Color565)(x) & ~((Color565)COLOR565_g_MASK)) | (((Color565)(g)) << COLOR565_g_SHIFT)
#define COLOR565_b_SHIFT                                 0
#define COLOR565_b_MASK                                  0x1F
#define COLOR565_b(x)                                    ((((Color565)(x)) & COLOR565_b_MASK) >> COLOR565_b_SHIFT)
#define COLOR565_SET_b(x, b)                             (x) = ((Color565)(x) & ~((Color565)COLOR565_b_MASK)) | (((Color565)(b)) << COLOR565_b_SHIFT)
#define COLOR565(r, g, b)                                (((((Color565)(r)) << COLOR565_r_SHIFT) | ((Color565)(g)) << COLOR565_g_SHIFT) | ((Color565)(b)) << COLOR565_b_SHIFT)


extern C(Property) * PROPERTY(Color565, Color);
extern C(Color565) (* Color565_from_Color)(C(Color) color);
extern C(Color) (* Color565_to_Color)(C(Color565) color565);

#define COLORALPHA_a_SHIFT                               24
#define COLORALPHA_a_MASK                                0xFF000000
#define COLORALPHA_a(x)                                  ((((ColorAlpha)(x)) & COLORALPHA_a_MASK) >> COLORALPHA_a_SHIFT)
#define COLORALPHA_SET_a(x, a)                           (x) = ((ColorAlpha)(x) & ~((ColorAlpha)COLORALPHA_a_MASK)) | (((ColorAlpha)(a)) << COLORALPHA_a_SHIFT)
#define COLORALPHA_color_SHIFT                           0
#define COLORALPHA_color_MASK                            0xFFFFFF
#define COLORALPHA_color(x)                              ((((ColorAlpha)(x)) & COLORALPHA_color_MASK) >> COLORALPHA_color_SHIFT)
#define COLORALPHA_SET_color(x, color)                       (x) = ((ColorAlpha)(x) & ~((ColorAlpha)COLORALPHA_color_MASK)) | (((ColorAlpha)(color)) << COLORALPHA_color_SHIFT)
#define COLORALPHA(a, color)                                ((((ColorAlpha)(a)) << COLORALPHA_a_SHIFT) | ((ColorAlpha)(color)) << COLORALPHA_color_SHIFT)


extern C(Property) * PROPERTY(ColorAlpha, Color);
extern C(ColorAlpha) (* ColorAlpha_from_Color)(C(Color) color);
extern C(Color) (* ColorAlpha_to_Color)(C(ColorAlpha) colorAlpha);

struct C(ColorCMYK)
{
   float c;
   float m;
   float y;
   float k;
};
extern C(Property) * PROPERTY(ColorCMYK, ColorRGB);
extern void (* ColorCMYK_from_ColorRGB)(C(ColorCMYK) c, const C(ColorRGB) * value);
extern void (* ColorCMYK_to_ColorRGB)(C(ColorCMYK) c, C(ColorRGB) * value);

struct C(ColorHSV)
{
   C(Angle) h;
   float s;
   float v;
};
extern C(Property) * PROPERTY(ColorHSV, ColorRGB);
extern void (* ColorHSV_from_ColorRGB)(C(ColorHSV) c, const C(ColorRGB) * value);
extern void (* ColorHSV_to_ColorRGB)(C(ColorHSV) c, C(ColorRGB) * value);

struct C(ColorKey)
{
   C(ColorAlpha) color;
   float percent;
};
struct C(ColorLab)
{
   float l;
   float a;
   float b;
};
extern C(Property) * PROPERTY(ColorLab, ColorRGB);
extern void (* ColorLab_from_ColorRGB)(C(ColorLab) c, const C(ColorRGB) * value);
extern void (* ColorLab_to_ColorRGB)(C(ColorLab) c, C(ColorRGB) * value);

#define COLORRGBA_r_SHIFT                                0
#define COLORRGBA_r_MASK                                 0xFF
#define COLORRGBA_r(x)                                   ((((ColorRGBA)(x)) & COLORRGBA_r_MASK) >> COLORRGBA_r_SHIFT)
#define COLORRGBA_SET_r(x, r)                            (x) = ((ColorRGBA)(x) & ~((ColorRGBA)COLORRGBA_r_MASK)) | (((ColorRGBA)(r)) << COLORRGBA_r_SHIFT)
#define COLORRGBA_g_SHIFT                                8
#define COLORRGBA_g_MASK                                 0xFF00
#define COLORRGBA_g(x)                                   ((((ColorRGBA)(x)) & COLORRGBA_g_MASK) >> COLORRGBA_g_SHIFT)
#define COLORRGBA_SET_g(x, g)                            (x) = ((ColorRGBA)(x) & ~((ColorRGBA)COLORRGBA_g_MASK)) | (((ColorRGBA)(g)) << COLORRGBA_g_SHIFT)
#define COLORRGBA_b_SHIFT                                16
#define COLORRGBA_b_MASK                                 0xFF0000
#define COLORRGBA_b(x)                                   ((((ColorRGBA)(x)) & COLORRGBA_b_MASK) >> COLORRGBA_b_SHIFT)
#define COLORRGBA_SET_b(x, b)                            (x) = ((ColorRGBA)(x) & ~((ColorRGBA)COLORRGBA_b_MASK)) | (((ColorRGBA)(b)) << COLORRGBA_b_SHIFT)
#define COLORRGBA_a_SHIFT                                24
#define COLORRGBA_a_MASK                                 0xFF000000
#define COLORRGBA_a(x)                                   ((((ColorRGBA)(x)) & COLORRGBA_a_MASK) >> COLORRGBA_a_SHIFT)
#define COLORRGBA_SET_a(x, a)                            (x) = ((ColorRGBA)(x) & ~((ColorRGBA)COLORRGBA_a_MASK)) | (((ColorRGBA)(a)) << COLORRGBA_a_SHIFT)
#define COLORRGBA(r, g, b, a)                             ((((((ColorRGBA)(r)) << COLORRGBA_r_SHIFT) | ((ColorRGBA)(g)) << COLORRGBA_g_SHIFT) | ((ColorRGBA)(b)) << COLORRGBA_b_SHIFT) | ((ColorRGBA)(a)) << COLORRGBA_a_SHIFT)


extern C(Property) * PROPERTY(ColorRGBA, ColorAlpha);
extern C(ColorRGBA) (* ColorRGBA_from_ColorAlpha)(C(ColorAlpha) colorAlpha);
extern C(ColorAlpha) (* ColorRGBA_to_ColorAlpha)(C(ColorRGBA) colorRGBA);

extern C(Property) * PROPERTY(ColorRGBA, Color);
extern C(ColorRGBA) (* ColorRGBA_from_Color)(C(Color) color);
extern C(Color) (* ColorRGBA_to_Color)(C(ColorRGBA) colorRGBA);

struct C(ColorRGBAf)
{
   float r;
   float g;
   float b;
   float a;
};
extern C(Property) * PROPERTY(ColorRGBAf, ColorAlpha);
extern void (* ColorRGBAf_from_ColorAlpha)(C(ColorRGBAf) c, C(ColorAlpha) value);
extern C(ColorAlpha) (* ColorRGBAf_to_ColorAlpha)(C(ColorRGBAf) c);

extern C(Property) * PROPERTY(ColorRGBAf, Color);
extern void (* ColorRGBAf_from_Color)(C(ColorRGBAf) c, C(Color) value);
extern C(Color) (* ColorRGBAf_to_Color)(C(ColorRGBAf) c);

extern C(bool) (* CubeMap_load)(C(CubeMap) __this, C(DisplaySystem) displaySystem, constString * names, constString extension, C(bool) oldStyle);

extern void (* Display_applyMaterial)(C(Display) __this, C(Material) * material, C(Mesh) * mesh);

extern void (* Display_collectHits)(C(Display) __this);

extern C(bool) (* Display_create)(C(Display) __this, C(DisplaySystem) displaySystem, void * window);

extern C(bool) (* Display_drawMesh)(C(Display) __this, C(Object) * object);

extern C(bool) (* Display_drawObject)(C(Display) __this, C(Object) * object);

extern void (* Display_drawPrimitives)(C(Display) __this, C(PrimitiveSingle) * primitive, C(Mesh) * mesh);

extern void (* Display_drawTranslucency)(C(Display) __this);

extern void (* Display_endUpdate)(C(Display) __this);

extern void (* Display_fontExtent)(C(Display) __this, C(Font) * font, const char * text, int len, int * width, int * height);

extern void (* Display_fontExtent2)(C(Display) __this, C(Font) * font, const char * text, int len, int * width, int * height, int prevGlyph, int * rPrevGlyph, int * overHang);

extern int (* Display_getHits)(C(Display) __this, C(OldList) * list);

extern C(bool) (* Display_getIntersect)(C(Display) __this, C(Vector3D) * intersect);

extern C(Surface) (* Display_getSurface)(C(Display) __this, int x, int y, C(Box) * clip);

extern C(bool) (* Display_grab)(C(Display) __this, C(Bitmap) bitmap, int x, int y, int w, int h);

extern void (* Display_intersectPolygons)(C(Display) __this);

extern C(bool) (* Display_isObjectVisible)(C(Display) __this, C(Object) * object);

extern C(bool) (* Display_lock)(C(Display) __this, C(bool) render);

extern void (* Display_nextPage)(C(Display) __this);

extern void (* Display_popMatrix)(C(Display) __this);

extern void (* Display_position)(C(Display) __this, int x, int y);

extern void (* Display_pushMatrix)(C(Display) __this);

extern C(bool) (* Display_resize)(C(Display) __this, int width, int height);

extern void (* Display_restorePalette)(C(Display) __this);

extern void (* Display_scroll)(C(Display) __this, C(Box) * scroll, int x, int y, C(Extent) * dirty);

extern void (* Display_selectMesh)(C(Display) __this, C(Mesh) * mesh);

extern void (* Display_setCamera)(C(Display) __this, C(Surface) surface, C(Camera) camera);

extern void (* Display_setLight)(C(Display) __this, int id, C(Light) * light);

extern void (* Display_setLights)(C(Display) __this, C(Object) * object);

extern void (* Display_setPalette)(C(Display) __this, C(ColorAlpha) * palette, C(bool) colorMatch);

extern void (* Display_setTransform)(C(Display) __this, C(Matrix) * matrix, C(bool) viewSpace);

extern void (* Display_startSelection)(C(Display) __this, int pickX, int pickY, int pickW, int pickH);

extern void (* Display_startUpdate)(C(Display) __this);

extern void (* Display_stopSelection)(C(Display) __this);

extern void (* Display_unlock)(C(Display) __this);

extern void (* Display_update)(C(Display) __this, C(Box) * updateBox);

extern C(Property) * PROPERTY(Display, fillMode);
extern void (* Display_set_fillMode)(C(Display) d, C(FillModeValue) value);

extern C(Property) * PROPERTY(Display, depthTest);
extern void (* Display_set_depthTest)(C(Display) d, C(bool) value);

extern C(Property) * PROPERTY(Display, depthWrite);
extern void (* Display_set_depthWrite)(C(Display) d, C(bool) value);

extern C(Property) * PROPERTY(Display, fogDensity);
extern void (* Display_set_fogDensity)(C(Display) d, float value);

extern C(Property) * PROPERTY(Display, fogColor);
extern void (* Display_set_fogColor)(C(Display) d, C(Color) value);

extern C(Property) * PROPERTY(Display, blend);
extern void (* Display_set_blend)(C(Display) d, C(bool) value);

extern C(Property) * PROPERTY(Display, ambient);
extern void (* Display_set_ambient)(C(Display) d, C(Color) value);

extern C(Property) * PROPERTY(Display, alphaWrite);
extern void (* Display_set_alphaWrite)(C(Display) d, C(bool) value);

extern C(Property) * PROPERTY(Display, antiAlias);
extern void (* Display_set_antiAlias)(C(Display) d, C(bool) value);

extern C(Property) * PROPERTY(Display, vSync);
extern void (* Display_set_vSync)(C(Display) d, C(bool) value);

extern C(Property) * PROPERTY(Display, pickingPlanes);
extern void (* Display_set_pickingPlanes)(C(Display) d, C(bool) value);

extern C(Property) * PROPERTY(Display, flags);
extern C(DisplayFlags) (* Display_get_flags)(C(Display) d);

extern C(Property) * PROPERTY(Display, pixelFormat);
extern C(PixelFormat) (* Display_get_pixelFormat)(C(Display) d);

extern C(Property) * PROPERTY(Display, alphaBlend);
extern void (* Display_set_alphaBlend)(C(Display) d, C(bool) value);
extern C(bool) (* Display_get_alphaBlend)(C(Display) d);

extern C(Property) * PROPERTY(Display, useSharedMemory);
extern void (* Display_set_useSharedMemory)(C(Display) d, C(bool) value);
extern C(bool) (* Display_get_useSharedMemory)(C(Display) d);

extern C(Property) * PROPERTY(Display, systemWindow);
extern void * (* Display_get_systemWindow)(C(Display) d);

extern C(Property) * PROPERTY(Display, displaySystem);
extern C(DisplaySystem) (* Display_get_displaySystem)(C(Display) d);

extern C(Property) * PROPERTY(Display, glCapabilities);
extern void (* Display_set_glCapabilities)(C(Display) d, C(GLCapabilities) value);
extern C(GLCapabilities) (* Display_get_glCapabilities)(C(Display) d);

extern int M_VTBLID(DisplayDriver, allocateBitmap);
#define DisplayDriver_allocateBitmap(__i, ap1, ap2, ap3, ap4, ap5, ap6, ap7) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, allocateBitmap, __i, C(bool), \
      C(DisplaySystem) _ARG C(Bitmap) _ARG int _ARG int _ARG int _ARG C(PixelFormat) _ARG C(bool), \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4 _ARG ap5 _ARG ap6 _ARG ap7)
extern C(Method) * METHOD(DisplayDriver, allocateBitmap);
extern int M_VTBLID(DisplayDriver, allocateIndices);
#define DisplayDriver_allocateIndices(__i, ap1, nIndices, indices32bit) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, allocateIndices, __i, void *, \
      C(DisplaySystem) _ARG int _ARG C(bool), \
      ap1 _ARG nIndices _ARG indices32bit)
extern C(Method) * METHOD(DisplayDriver, allocateIndices);
extern int M_VTBLID(DisplayDriver, allocateMesh);
#define DisplayDriver_allocateMesh(__i, ap1, ap2, ap3, nVertices) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, allocateMesh, __i, C(bool), \
      C(DisplaySystem) _ARG C(Mesh) * _ARG C(MeshFeatures) _ARG int, \
      ap1 _ARG ap2 _ARG ap3 _ARG nVertices)
extern C(Method) * METHOD(DisplayDriver, allocateMesh);
extern int M_VTBLID(DisplayDriver, applyMaterial);
#define DisplayDriver_applyMaterial(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, applyMaterial, __i, void, \
      C(Display) _ARG C(Material) * _ARG C(Mesh) *, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, applyMaterial);
extern int M_VTBLID(DisplayDriver, area);
#define DisplayDriver_area(__i, ap1, ap2, x1, y1, x2, y2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, area, __i, void, \
      C(Display) _ARG C(Surface) _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG x1 _ARG y1 _ARG x2 _ARG y2)
extern C(Method) * METHOD(DisplayDriver, area);
extern int M_VTBLID(DisplayDriver, blit);
#define DisplayDriver_blit(__i, ap1, ap2, ap3, dx, dy, sx, sy, w, h) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, blit, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Bitmap) _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3 _ARG dx _ARG dy _ARG sx _ARG sy _ARG w _ARG h)
extern C(Method) * METHOD(DisplayDriver, blit);
extern int M_VTBLID(DisplayDriver, blitDI);
#define DisplayDriver_blitDI(__i, ap1, ap2, ap3, dx, dy, sx, sy, w, h) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, blitDI, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Bitmap) _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3 _ARG dx _ARG dy _ARG sx _ARG sy _ARG w _ARG h)
extern C(Method) * METHOD(DisplayDriver, blitDI);
extern int M_VTBLID(DisplayDriver, clear);
#define DisplayDriver_clear(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, clear, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(ClearType), \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, clear);
extern int M_VTBLID(DisplayDriver, clip);
#define DisplayDriver_clip(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, clip, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Box) *, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, clip);
extern int M_VTBLID(DisplayDriver, convertBitmap);
#define DisplayDriver_convertBitmap(__i, ap1, ap2, ap3, ap4) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, convertBitmap, __i, C(bool), \
      C(DisplaySystem) _ARG C(Bitmap) _ARG C(PixelFormat) _ARG C(ColorAlpha) *, \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4)
extern C(Method) * METHOD(DisplayDriver, convertBitmap);
extern int M_VTBLID(DisplayDriver, createDisplay);
#define DisplayDriver_createDisplay(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, createDisplay, __i, C(bool), \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, createDisplay);
extern int M_VTBLID(DisplayDriver, createDisplaySystem);
#define DisplayDriver_createDisplaySystem(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, createDisplaySystem, __i, C(bool), \
      C(DisplaySystem), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, createDisplaySystem);
extern int M_VTBLID(DisplayDriver, destroyDisplay);
#define DisplayDriver_destroyDisplay(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, destroyDisplay, __i, void, \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, destroyDisplay);
extern int M_VTBLID(DisplayDriver, destroyDisplaySystem);
#define DisplayDriver_destroyDisplaySystem(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, destroyDisplaySystem, __i, void, \
      C(DisplaySystem), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, destroyDisplaySystem);
extern int M_VTBLID(DisplayDriver, displayPosition);
#define DisplayDriver_displayPosition(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, displayPosition, __i, void, \
      C(Display) _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, displayPosition);
extern int M_VTBLID(DisplayDriver, displaySize);
#define DisplayDriver_displaySize(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, displaySize, __i, C(bool), \
      C(Display) _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, displaySize);
extern int M_VTBLID(DisplayDriver, drawLine);
#define DisplayDriver_drawLine(__i, ap1, ap2, x1, y1, x2, y2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, drawLine, __i, void, \
      C(Display) _ARG C(Surface) _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG x1 _ARG y1 _ARG x2 _ARG y2)
extern C(Method) * METHOD(DisplayDriver, drawLine);
extern int M_VTBLID(DisplayDriver, drawPrimitives);
#define DisplayDriver_drawPrimitives(__i, ap1, ap2, mesh) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, drawPrimitives, __i, void, \
      C(Display) _ARG C(PrimitiveSingle) * _ARG C(Mesh) *, \
      ap1 _ARG ap2 _ARG mesh)
extern C(Method) * METHOD(DisplayDriver, drawPrimitives);
extern int M_VTBLID(DisplayDriver, drawingChar);
#define DisplayDriver_drawingChar(__i, ap1, ap2, ch) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, drawingChar, __i, void, \
      C(Display) _ARG C(Surface) _ARG char, \
      ap1 _ARG ap2 _ARG ch)
extern C(Method) * METHOD(DisplayDriver, drawingChar);
extern int M_VTBLID(DisplayDriver, endUpdate);
#define DisplayDriver_endUpdate(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, endUpdate, __i, void, \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, endUpdate);
extern int M_VTBLID(DisplayDriver, filter);
#define DisplayDriver_filter(__i, ap1, ap2, ap3, dx, dy, sx, sy, w, h, sw, sh) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, filter, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Bitmap) _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3 _ARG dx _ARG dy _ARG sx _ARG sy _ARG w _ARG h _ARG sw _ARG sh)
extern C(Method) * METHOD(DisplayDriver, filter);
extern int M_VTBLID(DisplayDriver, filterDI);
#define DisplayDriver_filterDI(__i, ap1, ap2, ap3, dx, dy, sx, sy, w, h, sw, sh) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, filterDI, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Bitmap) _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3 _ARG dx _ARG dy _ARG sx _ARG sy _ARG w _ARG h _ARG sw _ARG sh)
extern C(Method) * METHOD(DisplayDriver, filterDI);
extern int M_VTBLID(DisplayDriver, fontExtent);
#define DisplayDriver_fontExtent(__i, ap1, ap2, text, len, tw, th, prevGlyph, rPrevGlyph, overHang) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, fontExtent, __i, void, \
      C(DisplaySystem) _ARG C(Font) * _ARG constString _ARG int _ARG int * _ARG int * _ARG int _ARG int * _ARG int *, \
      ap1 _ARG ap2 _ARG text _ARG len _ARG tw _ARG th _ARG prevGlyph _ARG rPrevGlyph _ARG overHang)
extern C(Method) * METHOD(DisplayDriver, fontExtent);
extern int M_VTBLID(DisplayDriver, freeBitmap);
#define DisplayDriver_freeBitmap(__i, ap1, ap2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, freeBitmap, __i, void, \
      C(DisplaySystem) _ARG C(Bitmap), \
      ap1 _ARG ap2)
extern C(Method) * METHOD(DisplayDriver, freeBitmap);
extern int M_VTBLID(DisplayDriver, freeIndices);
#define DisplayDriver_freeIndices(__i, ap1, indices) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, freeIndices, __i, void, \
      C(DisplaySystem) _ARG void *, \
      ap1 _ARG indices)
extern C(Method) * METHOD(DisplayDriver, freeIndices);
extern int M_VTBLID(DisplayDriver, freeMesh);
#define DisplayDriver_freeMesh(__i, ap1, ap2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, freeMesh, __i, void, \
      C(DisplaySystem) _ARG C(Mesh) *, \
      ap1 _ARG ap2)
extern C(Method) * METHOD(DisplayDriver, freeMesh);
extern int M_VTBLID(DisplayDriver, getBitmapSurface);
#define DisplayDriver_getBitmapSurface(__i, displaySystem, surface, bitmap, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, getBitmapSurface, __i, C(bool), \
      C(DisplaySystem) _ARG C(Surface) _ARG C(Bitmap) _ARG int _ARG int _ARG C(Box) *, \
      displaySystem _ARG surface _ARG bitmap _ARG ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, getBitmapSurface);
extern int M_VTBLID(DisplayDriver, getPixel);
#define DisplayDriver_getPixel(__i, ap1, ap2, x, y) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, getPixel, __i, C(ColorAlpha), \
      C(Display) _ARG C(Surface) _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG x _ARG y)
extern C(Method) * METHOD(DisplayDriver, getPixel);
extern int M_VTBLID(DisplayDriver, getSurface);
#define DisplayDriver_getSurface(__i, ap1, surface, ap2, ap3, ap4) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, getSurface, __i, C(bool), \
      C(Display) _ARG C(Surface) _ARG int _ARG int _ARG C(Box) *, \
      ap1 _ARG surface _ARG ap2 _ARG ap3 _ARG ap4)
extern C(Method) * METHOD(DisplayDriver, getSurface);
extern int M_VTBLID(DisplayDriver, grabScreen);
#define DisplayDriver_grabScreen(__i, ap1, ap2, ap3, ap4, ap5, ap6) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, grabScreen, __i, C(bool), \
      C(Display) _ARG C(Bitmap) _ARG int _ARG int _ARG uint _ARG uint, \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4 _ARG ap5 _ARG ap6)
extern C(Method) * METHOD(DisplayDriver, grabScreen);
extern int M_VTBLID(DisplayDriver, lineStipple);
#define DisplayDriver_lineStipple(__i, ap1, ap2, pattern) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, lineStipple, __i, void, \
      C(Display) _ARG C(Surface) _ARG uint, \
      ap1 _ARG ap2 _ARG pattern)
extern C(Method) * METHOD(DisplayDriver, lineStipple);
extern int M_VTBLID(DisplayDriver, loadFont);
#define DisplayDriver_loadFont(__i, displaySystem, faceName, size, flags, outlineSize, outlineFade) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, loadFont, __i, C(Font) *, \
      C(DisplaySystem) _ARG const char * _ARG float _ARG C(FontFlags) _ARG float _ARG float, \
      displaySystem _ARG faceName _ARG size _ARG flags _ARG outlineSize _ARG outlineFade)
extern C(Method) * METHOD(DisplayDriver, loadFont);
extern int M_VTBLID(DisplayDriver, lock);
#define DisplayDriver_lock(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, lock, __i, C(bool), \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, lock);
extern int M_VTBLID(DisplayDriver, lockIndices);
#define DisplayDriver_lockIndices(__i, ap1, indices) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, lockIndices, __i, uint16 *, \
      C(DisplaySystem) _ARG void *, \
      ap1 _ARG indices)
extern C(Method) * METHOD(DisplayDriver, lockIndices);
extern int M_VTBLID(DisplayDriver, lockMesh);
#define DisplayDriver_lockMesh(__i, ap1, ap2, flags) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, lockMesh, __i, C(bool), \
      C(DisplaySystem) _ARG C(Mesh) * _ARG C(MeshFeatures), \
      ap1 _ARG ap2 _ARG flags)
extern C(Method) * METHOD(DisplayDriver, lockMesh);
extern int M_VTBLID(DisplayDriver, lockSystem);
#define DisplayDriver_lockSystem(__i, displaySystem) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, lockSystem, __i, C(bool), \
      C(DisplaySystem), \
      displaySystem)
extern C(Method) * METHOD(DisplayDriver, lockSystem);
extern int M_VTBLID(DisplayDriver, makeDDBitmap);
#define DisplayDriver_makeDDBitmap(__i, ap1, ap2, mipMaps, cubeMapFace) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, makeDDBitmap, __i, C(bool), \
      C(DisplaySystem) _ARG C(Bitmap) _ARG C(bool) _ARG int, \
      ap1 _ARG ap2 _ARG mipMaps _ARG cubeMapFace)
extern C(Method) * METHOD(DisplayDriver, makeDDBitmap);
extern int M_VTBLID(DisplayDriver, nextPage);
#define DisplayDriver_nextPage(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, nextPage, __i, void, \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, nextPage);
extern int M_VTBLID(DisplayDriver, popMatrix);
#define DisplayDriver_popMatrix(__i, ap1, ap2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, popMatrix, __i, void, \
      C(Display) _ARG C(bool), \
      ap1 _ARG ap2)
extern C(Method) * METHOD(DisplayDriver, popMatrix);
extern int M_VTBLID(DisplayDriver, pushMatrix);
#define DisplayDriver_pushMatrix(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, pushMatrix, __i, void, \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, pushMatrix);
extern int M_VTBLID(DisplayDriver, putPixel);
#define DisplayDriver_putPixel(__i, ap1, ap2, x, y) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, putPixel, __i, void, \
      C(Display) _ARG C(Surface) _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG x _ARG y)
extern C(Method) * METHOD(DisplayDriver, putPixel);
extern int M_VTBLID(DisplayDriver, rectangle);
#define DisplayDriver_rectangle(__i, ap1, ap2, x1, y1, x2, y2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, rectangle, __i, void, \
      C(Display) _ARG C(Surface) _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG x1 _ARG y1 _ARG x2 _ARG y2)
extern C(Method) * METHOD(DisplayDriver, rectangle);
extern int M_VTBLID(DisplayDriver, releaseSurface);
#define DisplayDriver_releaseSurface(__i, this, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, releaseSurface, __i, void, \
      C(Display) _ARG C(Surface), \
      this _ARG ap1)
extern C(Method) * METHOD(DisplayDriver, releaseSurface);
extern int M_VTBLID(DisplayDriver, restorePalette);
#define DisplayDriver_restorePalette(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, restorePalette, __i, void, \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, restorePalette);
extern int M_VTBLID(DisplayDriver, scroll);
#define DisplayDriver_scroll(__i, ap1, ap2, ap3, ap4, ap5) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, scroll, __i, void, \
      C(Display) _ARG C(Box) * _ARG int _ARG int _ARG C(Extent) *, \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4 _ARG ap5)
extern C(Method) * METHOD(DisplayDriver, scroll);
extern int M_VTBLID(DisplayDriver, selectMesh);
#define DisplayDriver_selectMesh(__i, ap1, ap2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, selectMesh, __i, void, \
      C(Display) _ARG C(Mesh) *, \
      ap1 _ARG ap2)
extern C(Method) * METHOD(DisplayDriver, selectMesh);
extern int M_VTBLID(DisplayDriver, setBackground);
#define DisplayDriver_setBackground(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, setBackground, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(ColorAlpha), \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, setBackground);
extern int M_VTBLID(DisplayDriver, setBlitTint);
#define DisplayDriver_setBlitTint(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, setBlitTint, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(ColorAlpha), \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, setBlitTint);
extern int M_VTBLID(DisplayDriver, setCamera);
#define DisplayDriver_setCamera(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, setCamera, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Camera), \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, setCamera);
extern int M_VTBLID(DisplayDriver, setForeground);
#define DisplayDriver_setForeground(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, setForeground, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(ColorAlpha), \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, setForeground);
extern int M_VTBLID(DisplayDriver, setLight);
#define DisplayDriver_setLight(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, setLight, __i, void, \
      C(Display) _ARG int _ARG C(Light) *, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, setLight);
extern int M_VTBLID(DisplayDriver, setPalette);
#define DisplayDriver_setPalette(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, setPalette, __i, void, \
      C(Display) _ARG C(ColorAlpha) * _ARG C(bool), \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, setPalette);
extern int M_VTBLID(DisplayDriver, setRenderState);
#define DisplayDriver_setRenderState(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, setRenderState, __i, void, \
      C(Display) _ARG C(RenderState) _ARG uint, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, setRenderState);
extern int M_VTBLID(DisplayDriver, setTransform);
#define DisplayDriver_setTransform(__i, ap1, ap2, ap3, ap4) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, setTransform, __i, void, \
      C(Display) _ARG C(Matrix) * _ARG C(bool) _ARG C(bool), \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4)
extern C(Method) * METHOD(DisplayDriver, setTransform);
extern int M_VTBLID(DisplayDriver, startUpdate);
#define DisplayDriver_startUpdate(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, startUpdate, __i, void, \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, startUpdate);
extern int M_VTBLID(DisplayDriver, stretch);
#define DisplayDriver_stretch(__i, ap1, ap2, ap3, dx, dy, sx, sy, w, h, sw, sh) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, stretch, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Bitmap) _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3 _ARG dx _ARG dy _ARG sx _ARG sy _ARG w _ARG h _ARG sw _ARG sh)
extern C(Method) * METHOD(DisplayDriver, stretch);
extern int M_VTBLID(DisplayDriver, stretchDI);
#define DisplayDriver_stretchDI(__i, ap1, ap2, ap3, dx, dy, sx, sy, w, h, sw, sh) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, stretchDI, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Bitmap) _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3 _ARG dx _ARG dy _ARG sx _ARG sy _ARG w _ARG h _ARG sw _ARG sh)
extern C(Method) * METHOD(DisplayDriver, stretchDI);
extern int M_VTBLID(DisplayDriver, textExtent);
#define DisplayDriver_textExtent(__i, ap1, ap2, text, len, tw, th, prevGlyph, rPrevGlyph, overHang) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, textExtent, __i, void, \
      C(Display) _ARG C(Surface) _ARG constString _ARG int _ARG int * _ARG int * _ARG int _ARG int * _ARG int *, \
      ap1 _ARG ap2 _ARG text _ARG len _ARG tw _ARG th _ARG prevGlyph _ARG rPrevGlyph _ARG overHang)
extern C(Method) * METHOD(DisplayDriver, textExtent);
extern int M_VTBLID(DisplayDriver, textFont);
#define DisplayDriver_textFont(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, textFont, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(Font) *, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, textFont);
extern int M_VTBLID(DisplayDriver, textOpacity);
#define DisplayDriver_textOpacity(__i, ap1, ap2, ap3) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, textOpacity, __i, void, \
      C(Display) _ARG C(Surface) _ARG C(bool), \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(DisplayDriver, textOpacity);
extern int M_VTBLID(DisplayDriver, unloadFont);
#define DisplayDriver_unloadFont(__i, ap1, ap2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, unloadFont, __i, void, \
      C(DisplaySystem) _ARG C(Font) *, \
      ap1 _ARG ap2)
extern C(Method) * METHOD(DisplayDriver, unloadFont);
extern int M_VTBLID(DisplayDriver, unlock);
#define DisplayDriver_unlock(__i, ap1) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, unlock, __i, void, \
      C(Display), \
      ap1)
extern C(Method) * METHOD(DisplayDriver, unlock);
extern int M_VTBLID(DisplayDriver, unlockIndices);
#define DisplayDriver_unlockIndices(__i, ap1, indices, indices32bit, nIndices) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, unlockIndices, __i, void, \
      C(DisplaySystem) _ARG void * _ARG C(bool) _ARG int, \
      ap1 _ARG indices _ARG indices32bit _ARG nIndices)
extern C(Method) * METHOD(DisplayDriver, unlockIndices);
extern int M_VTBLID(DisplayDriver, unlockMesh);
#define DisplayDriver_unlockMesh(__i, ap1, ap2, flags) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, unlockMesh, __i, void, \
      C(DisplaySystem) _ARG C(Mesh) * _ARG C(MeshFeatures), \
      ap1 _ARG ap2 _ARG flags)
extern C(Method) * METHOD(DisplayDriver, unlockMesh);
extern int M_VTBLID(DisplayDriver, unlockSystem);
#define DisplayDriver_unlockSystem(__i, displaySystem) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, unlockSystem, __i, void, \
      C(DisplaySystem), \
      displaySystem)
extern C(Method) * METHOD(DisplayDriver, unlockSystem);
extern int M_VTBLID(DisplayDriver, update);
#define DisplayDriver_update(__i, ap1, ap2) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, update, __i, void, \
      C(Display) _ARG C(Box) *, \
      ap1 _ARG ap2)
extern C(Method) * METHOD(DisplayDriver, update);
extern int M_VTBLID(DisplayDriver, writeText);
#define DisplayDriver_writeText(__i, ap1, ap2, x, y, text, len, prevGlyph, rPrevGlyph) \
   VMETHOD(CO(DisplayDriver), DisplayDriver, writeText, __i, void, \
      C(Display) _ARG C(Surface) _ARG int _ARG int _ARG constString _ARG int _ARG int _ARG int *, \
      ap1 _ARG ap2 _ARG x _ARG y _ARG text _ARG len _ARG prevGlyph _ARG rPrevGlyph)
extern C(Method) * METHOD(DisplayDriver, writeText);
#define DISPLAYFLAGS_fullScreen_SHIFT                    0
#define DISPLAYFLAGS_fullScreen_MASK                     0x1
#define DISPLAYFLAGS_fullScreen(x)                       ((((DisplayFlags)(x)) & DISPLAYFLAGS_fullScreen_MASK) >> DISPLAYFLAGS_fullScreen_SHIFT)
#define DISPLAYFLAGS_SET_fullScreen(x, fullScreen)                (x) = ((DisplayFlags)(x) & ~((DisplayFlags)DISPLAYFLAGS_fullScreen_MASK)) | (((DisplayFlags)(fullScreen)) << DISPLAYFLAGS_fullScreen_SHIFT)
#define DISPLAYFLAGS_flipping_SHIFT                      1
#define DISPLAYFLAGS_flipping_MASK                       0x2
#define DISPLAYFLAGS_flipping(x)                         ((((DisplayFlags)(x)) & DISPLAYFLAGS_flipping_MASK) >> DISPLAYFLAGS_flipping_SHIFT)
#define DISPLAYFLAGS_SET_flipping(x, flipping)                  (x) = ((DisplayFlags)(x) & ~((DisplayFlags)DISPLAYFLAGS_flipping_MASK)) | (((DisplayFlags)(flipping)) << DISPLAYFLAGS_flipping_SHIFT)
#define DISPLAYFLAGS_alpha_SHIFT                         2
#define DISPLAYFLAGS_alpha_MASK                          0x4
#define DISPLAYFLAGS_alpha(x)                            ((((DisplayFlags)(x)) & DISPLAYFLAGS_alpha_MASK) >> DISPLAYFLAGS_alpha_SHIFT)
#define DISPLAYFLAGS_SET_alpha(x, alpha)                     (x) = ((DisplayFlags)(x) & ~((DisplayFlags)DISPLAYFLAGS_alpha_MASK)) | (((DisplayFlags)(alpha)) << DISPLAYFLAGS_alpha_SHIFT)
#define DISPLAYFLAGS_memBackBuffer_SHIFT                 3
#define DISPLAYFLAGS_memBackBuffer_MASK                  0x8
#define DISPLAYFLAGS_memBackBuffer(x)                    ((((DisplayFlags)(x)) & DISPLAYFLAGS_memBackBuffer_MASK) >> DISPLAYFLAGS_memBackBuffer_SHIFT)
#define DISPLAYFLAGS_SET_memBackBuffer(x, memBackBuffer)             (x) = ((DisplayFlags)(x) & ~((DisplayFlags)DISPLAYFLAGS_memBackBuffer_MASK)) | (((DisplayFlags)(memBackBuffer)) << DISPLAYFLAGS_memBackBuffer_SHIFT)
#define DISPLAYFLAGS_text_SHIFT                          4
#define DISPLAYFLAGS_text_MASK                           0x10
#define DISPLAYFLAGS_text(x)                             ((((DisplayFlags)(x)) & DISPLAYFLAGS_text_MASK) >> DISPLAYFLAGS_text_SHIFT)
#define DISPLAYFLAGS_SET_text(x, text)                      (x) = ((DisplayFlags)(x) & ~((DisplayFlags)DISPLAYFLAGS_text_MASK)) | (((DisplayFlags)(text)) << DISPLAYFLAGS_text_SHIFT)
#define DISPLAYFLAGS_scrolling_SHIFT                     5
#define DISPLAYFLAGS_scrolling_MASK                      0x20
#define DISPLAYFLAGS_scrolling(x)                        ((((DisplayFlags)(x)) & DISPLAYFLAGS_scrolling_MASK) >> DISPLAYFLAGS_scrolling_SHIFT)
#define DISPLAYFLAGS_SET_scrolling(x, scrolling)                 (x) = ((DisplayFlags)(x) & ~((DisplayFlags)DISPLAYFLAGS_scrolling_MASK)) | (((DisplayFlags)(scrolling)) << DISPLAYFLAGS_scrolling_SHIFT)
#define DISPLAYFLAGS_printer_SHIFT                       6
#define DISPLAYFLAGS_printer_MASK                        0x40
#define DISPLAYFLAGS_printer(x)                          ((((DisplayFlags)(x)) & DISPLAYFLAGS_printer_MASK) >> DISPLAYFLAGS_printer_SHIFT)
#define DISPLAYFLAGS_SET_printer(x, printer)                   (x) = ((DisplayFlags)(x) & ~((DisplayFlags)DISPLAYFLAGS_printer_MASK)) | (((DisplayFlags)(printer)) << DISPLAYFLAGS_printer_SHIFT)


extern C(bool) (* DisplaySystem_addMaterial)(C(DisplaySystem) __this, C(Material) * material);

extern C(OldLink) * (* DisplaySystem_addMesh)(C(DisplaySystem) __this, C(Mesh) * mesh);

extern C(Material) * (* DisplaySystem_addNamedMaterial)(C(DisplaySystem) __this, const char * name);

extern C(NamedLink) * (* DisplaySystem_addTexture)(C(DisplaySystem) __this, const char * name, C(Bitmap) bitmap);

extern void (* DisplaySystem_clearMaterials)(C(DisplaySystem) __this);

extern void (* DisplaySystem_clearMeshes)(C(DisplaySystem) __this);

extern void (* DisplaySystem_clearTextures)(C(DisplaySystem) __this);

extern C(bool) (* DisplaySystem_create)(C(DisplaySystem) __this, const char * driverName, void * window, C(bool) fullScreen);

extern void (* DisplaySystem_fontExtent)(C(DisplaySystem) __this, C(Font) * font, const char * text, int len, int * width, int * height);

extern void (* DisplaySystem_fontExtent2)(C(DisplaySystem) __this, C(Font) * font, const char * text, int len, int * width, int * height, int prevGlyph, int * rPrevGlyph, int * overHang);

extern C(Material) * (* DisplaySystem_getMaterial)(C(DisplaySystem) __this, const char * name);

extern C(Bitmap) (* DisplaySystem_getTexture)(C(DisplaySystem) __this, const char * name);

extern C(Font) * (* DisplaySystem_loadFont)(C(DisplaySystem) __this, const char * faceName, float size, C(FontFlags) flags);

extern C(Font) * (* DisplaySystem_loadOutlineFont)(C(DisplaySystem) __this, const char * faceName, float size, C(FontFlags) flags, float outlineSize, float outlineFade);

extern void * (* DisplaySystem_loadResource)(C(DisplaySystem) __this, C(Resource) resource);

extern void * (* DisplaySystem_loadResourceFM)(C(DisplaySystem) __this, C(Resource) resource, C(FontManager) fm);

extern C(bool) (* DisplaySystem_lock)(C(DisplaySystem) __this);

extern C(bool) (* DisplaySystem_removeMaterial)(C(DisplaySystem) __this, C(Material) * material);

extern C(bool) (* DisplaySystem_removeMesh)(C(DisplaySystem) __this, C(Mesh) * mesh);

extern C(bool) (* DisplaySystem_removeTexture)(C(DisplaySystem) __this, const char * name);

extern void (* DisplaySystem_unloadFont)(C(DisplaySystem) __this, C(Font) * font);

extern void (* DisplaySystem_unloadResource)(C(DisplaySystem) __this, C(Resource) resource, C(DisplaySystemResPtr) * res);

extern void (* DisplaySystem_unlock)(C(DisplaySystem) __this);

extern void * (* DisplaySystem__LoadResource)(C(DisplaySystem) __this, C(Resource) resource, void * fm);

extern void (* DrawManager_clear)(C(DrawManager) __this);

extern void (* DrawManager_drawBarrier)(C(DrawManager) __this);

extern void (* DrawManager_drawImage)(C(DrawManager) __this, int index, float offsetx, float offsety, float angsin, float angcos, C(ColorAlpha) color);

extern void (* DrawManager_end)(C(DrawManager) __this);

extern void (* DrawManager_finish)(C(DrawManager) __this);

extern int M_VTBLID(DrawManager, flush);
#define DrawManager_flush(__i) \
   VMETHOD(CO(DrawManager), DrawManager, flush, __i, void, \
      C(DrawManager), \
      __i)
extern C(Method) * METHOD(DrawManager, flush);
extern C(bool) (* DrawManager_init)(C(DrawManager) __this);

extern void (* DrawManager_ready)(C(DrawManager) __this, int viewportWidth, int viewportHeight);

extern C(Property) * PROPERTY(DrawManager, renderingFlipped);
extern void (* DrawManager_set_renderingFlipped)(C(DrawManager) d, C(bool) value);

extern void (* FMFont_setOutline)(C(FMFont) * __this, float size, float fade);

struct C(FMPathDraw)
{
   int prevGlyphIndex;
   float middleAlign;
};
#define FMTEXTALIGNMENT_horzAlignment_SHIFT              0
#define FMTEXTALIGNMENT_horzAlignment_MASK               0x3
#define FMTEXTALIGNMENT_horzAlignment(x)                 ((((FMTextAlignment)(x)) & FMTEXTALIGNMENT_horzAlignment_MASK) >> FMTEXTALIGNMENT_horzAlignment_SHIFT)
#define FMTEXTALIGNMENT_SET_horzAlignment(x, horzAlignment)          (x) = ((FMTextAlignment)(x) & ~((FMTextAlignment)FMTEXTALIGNMENT_horzAlignment_MASK)) | (((FMTextAlignment)(horzAlignment)) << FMTEXTALIGNMENT_horzAlignment_SHIFT)
#define FMTEXTALIGNMENT_vertAlignment_SHIFT              2
#define FMTEXTALIGNMENT_vertAlignment_MASK               0xC
#define FMTEXTALIGNMENT_vertAlignment(x)                 ((((FMTextAlignment)(x)) & FMTEXTALIGNMENT_vertAlignment_MASK) >> FMTEXTALIGNMENT_vertAlignment_SHIFT)
#define FMTEXTALIGNMENT_SET_vertAlignment(x, vertAlignment)          (x) = ((FMTextAlignment)(x) & ~((FMTextAlignment)FMTEXTALIGNMENT_vertAlignment_MASK)) | (((FMTextAlignment)(vertAlignment)) << FMTEXTALIGNMENT_vertAlignment_SHIFT)
#define FMTEXTALIGNMENT(horzAlignment, vertAlignment)                           ((((FMTextAlignment)(horzAlignment)) << FMTEXTALIGNMENT_horzAlignment_SHIFT) | ((FMTextAlignment)(vertAlignment)) << FMTEXTALIGNMENT_vertAlignment_SHIFT)


extern C(Property) * PROPERTY(Font, ascent);
extern int (* Font_get_ascent)(C(Font) * f);

extern C(Property) * PROPERTY(Font, descent);
extern int (* Font_get_descent)(C(Font) * f);

#define FONTFLAGS_bold_SHIFT                             0
#define FONTFLAGS_bold_MASK                              0x1
#define FONTFLAGS_bold(x)                                ((((FontFlags)(x)) & FONTFLAGS_bold_MASK) >> FONTFLAGS_bold_SHIFT)
#define FONTFLAGS_SET_bold(x, bold)                         (x) = ((FontFlags)(x) & ~((FontFlags)FONTFLAGS_bold_MASK)) | (((FontFlags)(bold)) << FONTFLAGS_bold_SHIFT)
#define FONTFLAGS_italic_SHIFT                           1
#define FONTFLAGS_italic_MASK                            0x2
#define FONTFLAGS_italic(x)                              ((((FontFlags)(x)) & FONTFLAGS_italic_MASK) >> FONTFLAGS_italic_SHIFT)
#define FONTFLAGS_SET_italic(x, italic)                       (x) = ((FontFlags)(x) & ~((FontFlags)FONTFLAGS_italic_MASK)) | (((FontFlags)(italic)) << FONTFLAGS_italic_SHIFT)
#define FONTFLAGS_underline_SHIFT                        2
#define FONTFLAGS_underline_MASK                         0x4
#define FONTFLAGS_underline(x)                           ((((FontFlags)(x)) & FONTFLAGS_underline_MASK) >> FONTFLAGS_underline_SHIFT)
#define FONTFLAGS_SET_underline(x, underline)                    (x) = ((FontFlags)(x) & ~((FontFlags)FONTFLAGS_underline_MASK)) | (((FontFlags)(underline)) << FONTFLAGS_underline_SHIFT)
#define FONTFLAGS(bold, italic, underline)                               (((((FontFlags)(bold)) << FONTFLAGS_bold_SHIFT) | ((FontFlags)(italic)) << FONTFLAGS_italic_SHIFT) | ((FontFlags)(underline)) << FONTFLAGS_underline_SHIFT)


struct C(FontInfo)
{
   C(bool) fixedPitch;
   C(bool) defaultOrAnsiCharSet;
};
extern C(FMFont) * (* FontManager_addFont)(C(FontManager) __this, constString path, int glyphPaddingWidth);

extern C(FMFont) * (* FontManager_addFontData)(C(FontManager) __this, byte * data, int dataSize, int glyphPaddingWidth);

extern void (* FontManager_clearState)(C(FontManager) __this);

extern C(bool) (* FontManager_create)(C(FontManager) __this, int width, int height, int channelCount, int channelIndex, C(FontManagerRenderer) renderer);

extern int (* FontManager_drawText)(C(FontManager) __this, int x, int y, const char * string, int stringlength);

extern int (* FontManager_drawTextTruncate)(C(FontManager) __this, int x, int y, int truncatewidth, const char * string, int stringlength, char * extstring, int extwidth);

extern int (* FontManager_drawTextWithCursor)(C(FontManager) __this, int x, int y, const char * string, int stringlength, int cursoroffset);

extern C(bool) (* FontManager_expandAtlas)(C(FontManager) __this, int width, int height);

extern void (* FontManager_flush)(C(FontManager) __this, C(bool) rendererFlush);

extern void (* FontManager_flushUpdate)(C(FontManager) __this);

extern void (* FontManager_freeFont)(C(FontManager) __this, C(FMFont) * font);

extern void (* FontManager_getAtlasSize)(C(FontManager) __this, int * retwidth, int * retheight);

extern C(FMFont) * (* FontManager_getFont)(C(FontManager) __this, C(FontResource) fontResource);

extern void (* FontManager_getFontExtent)(C(FontManager) __this, int * retascent, int * retdescent);

extern void (* FontManager_getFontLimits)(C(FontManager) __this, int * retlimitminy, int * retlimitmaxy);

extern int (* FontManager_getFontLineHeight)(C(FontManager) __this);

extern int (* FontManager_getTextBounds)(C(FontManager) __this, int x, int y, const char * string, int stringlength, int * bounds);

extern int (* FontManager_getTextNearestOffset)(C(FontManager) __this, int targetwidth, const char * string, int stringlength);

extern int (* FontManager_getTextTruncateOffset)(C(FontManager) __this, int truncatewidth, const char * string, int stringlength, int extwidth, int * retextflag, int * retfullwidth);

extern int (* FontManager_getTextWidth)(C(FontManager) __this, const char * string, int stringlength);

extern int (* FontManager_getTextWidthTruncate)(C(FontManager) __this, const char * string, int stringlength, int truncatewidth);

extern const byte * (* FontManager_getTextureData)(C(FontManager) __this, int * width, int * height);

extern C(bool) (* FontManager_initPathDraw)(C(FontManager) __this, C(FMPathDraw) * pathdraw);

extern int M_VTBLID(FontManager, onAtlasFull);
#define FontManager_onAtlasFull(__i) \
   VMETHOD(CO(FontManager), FontManager, onAtlasFull, __i, void, \
      C(FontManager), \
      __i)
extern C(Method) * METHOD(FontManager, onAtlasFull);
extern float (* FontManager_pathDrawCharacter)(C(FontManager) __this, C(FMPathDraw) * pathdraw, float x, float y, float vectorx, float vectory, int unicode);

extern float (* FontManager_pathDrawPredictAdvance)(C(FontManager) __this, C(FMPathDraw) * pathdraw, unichar unicode);

extern void (* FontManager_popState)(C(FontManager) __this);

extern void (* FontManager_pushState)(C(FontManager) __this);

extern void (* FontManager_removeFont)(C(FontManager) __this, C(FMFont) * font);

extern C(bool) (* FontManager_resetAtlas)(C(FontManager) __this, int width, int height);

extern void (* FontManager_setAlign)(C(FontManager) __this, int align);

extern void (* FontManager_setFont)(C(FontManager) __this, C(FMFont) * font);

extern void (* FontManager_setFontImageProcessing)(C(FontManager) __this, C(FMFont) * font, void (* processImage)(byte * image, int width, int height, int bytesperpixel, int bytesperline, int paddingwidth, void * opaquecontext), void * opaquecontext);

extern void (* FontManager_setSize)(C(FontManager) __this, int size);

extern void (* FontManager_setState)(C(FontManager) __this, C(FMFont) * font, int size, int align);

extern C(bool) (* FontManager_validateTexture)(C(FontManager) __this, int * retdirtyrect);

extern C(Property) * PROPERTY(FontManager, renderer);
extern void (* FontManager_set_renderer)(C(FontManager) f, C(FontManagerRenderer) value);
extern C(FontManagerRenderer) (* FontManager_get_renderer)(C(FontManager) f);

extern int M_VTBLID(FontManagerRenderer, createTexture);
#define FontManagerRenderer_createTexture(__i, width, height) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, createTexture, __i, int, \
      C(FontManagerRenderer) _ARG int _ARG int, \
      __i _ARG width _ARG height)
extern C(Method) * METHOD(FontManagerRenderer, createTexture);
extern int M_VTBLID(FontManagerRenderer, drawImage);
#define FontManagerRenderer_drawImage(__i, targetx, targety, imageIndex, useExtColor) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, drawImage, __i, void, \
      C(FontManagerRenderer) _ARG int _ARG int _ARG int _ARG C(bool), \
      __i _ARG targetx _ARG targety _ARG imageIndex _ARG useExtColor)
extern C(Method) * METHOD(FontManagerRenderer, drawImage);
extern int M_VTBLID(FontManagerRenderer, drawImageAlt);
#define FontManagerRenderer_drawImageAlt(__i, texdata, targetx, targety, offsetx, offsety, width, height) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, drawImageAlt, __i, void, \
      C(FontManagerRenderer) _ARG byte * _ARG int _ARG int _ARG int _ARG int _ARG int _ARG int, \
      __i _ARG texdata _ARG targetx _ARG targety _ARG offsetx _ARG offsety _ARG width _ARG height)
extern C(Method) * METHOD(FontManagerRenderer, drawImageAlt);
extern int M_VTBLID(FontManagerRenderer, drawImageCursor);
#define FontManagerRenderer_drawImageCursor(__i, targetx, targety, imageIndex) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, drawImageCursor, __i, void, \
      C(FontManagerRenderer) _ARG int _ARG int _ARG int, \
      __i _ARG targetx _ARG targety _ARG imageIndex)
extern C(Method) * METHOD(FontManagerRenderer, drawImageCursor);
extern int M_VTBLID(FontManagerRenderer, drawImageFloat);
#define FontManagerRenderer_drawImageFloat(__i, targetx, targety, angsin, angcos, imageIndex, useExtColor) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, drawImageFloat, __i, void, \
      C(FontManagerRenderer) _ARG float _ARG float _ARG float _ARG float _ARG int _ARG C(bool), \
      __i _ARG targetx _ARG targety _ARG angsin _ARG angcos _ARG imageIndex _ARG useExtColor)
extern C(Method) * METHOD(FontManagerRenderer, drawImageFloat);
extern int M_VTBLID(FontManagerRenderer, flush);
#define FontManagerRenderer_flush(__i) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, flush, __i, void, \
      C(FontManagerRenderer), \
      __i)
extern C(Method) * METHOD(FontManagerRenderer, flush);
extern int M_VTBLID(FontManagerRenderer, init);
#define FontManagerRenderer_init(__i, channelCount) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, init, __i, C(bool), \
      C(FontManagerRenderer) _ARG int, \
      __i _ARG channelCount)
extern C(Method) * METHOD(FontManagerRenderer, init);
extern int M_VTBLID(FontManagerRenderer, registerImage);
#define FontManagerRenderer_registerImage(__i, offsetx, offsety, width, height) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, registerImage, __i, int, \
      C(FontManagerRenderer) _ARG int _ARG int _ARG int _ARG int, \
      __i _ARG offsetx _ARG offsety _ARG width _ARG height)
extern C(Method) * METHOD(FontManagerRenderer, registerImage);
extern int M_VTBLID(FontManagerRenderer, resetImages);
#define FontManagerRenderer_resetImages(__i) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, resetImages, __i, void, \
      C(FontManagerRenderer), \
      __i)
extern C(Method) * METHOD(FontManagerRenderer, resetImages);
extern int M_VTBLID(FontManagerRenderer, resizeTexture);
#define FontManagerRenderer_resizeTexture(__i, width, height) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, resizeTexture, __i, int, \
      C(FontManagerRenderer) _ARG int _ARG int, \
      __i _ARG width _ARG height)
extern C(Method) * METHOD(FontManagerRenderer, resizeTexture);
extern int M_VTBLID(FontManagerRenderer, setLayer);
#define FontManagerRenderer_setLayer(__i, layerIndex) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, setLayer, __i, void, \
      C(FontManagerRenderer) _ARG uint32, \
      __i _ARG layerIndex)
extern C(Method) * METHOD(FontManagerRenderer, setLayer);
extern int M_VTBLID(FontManagerRenderer, updateTexture);
#define FontManagerRenderer_updateTexture(__i, rect, data) \
   VMETHOD(CO(FontManagerRenderer), FontManagerRenderer, updateTexture, __i, void, \
      C(FontManagerRenderer) _ARG int * _ARG const byte *, \
      __i _ARG rect _ARG data)
extern C(Method) * METHOD(FontManagerRenderer, updateTexture);
extern void (* FontRenderer_setColor)(C(FontRenderer) __this, C(ColorAlpha) color);

extern void (* FontRenderer_setCursorColor)(C(FontRenderer) __this, C(ColorAlpha) color);

extern void (* FontRenderer_setExtColor)(C(FontRenderer) __this, C(ColorAlpha) color);

extern C(Property) * PROPERTY(FontRenderer, drawManager);
extern void (* FontRenderer_set_drawManager)(C(FontRenderer) f, C(DrawManager) value);

extern C(Property) * PROPERTY(FontResource, faceName);
extern void (* FontResource_set_faceName)(C(FontResource) f, const char * value);
extern const char * (* FontResource_get_faceName)(C(FontResource) f);

extern C(Property) * PROPERTY(FontResource, size);
extern void (* FontResource_set_size)(C(FontResource) f, float value);
extern float (* FontResource_get_size)(C(FontResource) f);

extern C(Property) * PROPERTY(FontResource, bold);
extern void (* FontResource_set_bold)(C(FontResource) f, C(bool) value);
extern C(bool) (* FontResource_get_bold)(C(FontResource) f);

extern C(Property) * PROPERTY(FontResource, italic);
extern void (* FontResource_set_italic)(C(FontResource) f, C(bool) value);
extern C(bool) (* FontResource_get_italic)(C(FontResource) f);

extern C(Property) * PROPERTY(FontResource, underline);
extern void (* FontResource_set_underline)(C(FontResource) f, C(bool) value);
extern C(bool) (* FontResource_get_underline)(C(FontResource) f);

extern C(Property) * PROPERTY(FontResource, font);
extern C(Font) * (* FontResource_get_font)(C(FontResource) f);

extern C(Property) * PROPERTY(FontResource, window);
extern void (* FontResource_set_window)(C(FontResource) f, C(Window) value);

extern C(Property) * PROPERTY(FontResource, outlineSize);
extern void (* FontResource_set_outlineSize)(C(FontResource) f, float value);
extern float (* FontResource_get_outlineSize)(C(FontResource) f);

extern C(Property) * PROPERTY(FontResource, outlineFade);
extern void (* FontResource_set_outlineFade)(C(FontResource) f, float value);
extern float (* FontResource_get_outlineFade)(C(FontResource) f);

extern C(Property) * PROPERTY(FontResource, fmFont);
extern C(FMFont) * (* FontResource_get_fmFont)(C(FontResource) f);

#define GLCAPABILITIES_compatible_SHIFT                  0
#define GLCAPABILITIES_compatible_MASK                   0x1
#define GLCAPABILITIES_compatible(x)                     ((((GLCapabilities)(x)) & GLCAPABILITIES_compatible_MASK) >> GLCAPABILITIES_compatible_SHIFT)
#define GLCAPABILITIES_SET_compatible(x, compatible)              (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_compatible_MASK)) | (((GLCapabilities)(compatible)) << GLCAPABILITIES_compatible_SHIFT)
#define GLCAPABILITIES_vertexBuffer_SHIFT                1
#define GLCAPABILITIES_vertexBuffer_MASK                 0x2
#define GLCAPABILITIES_vertexBuffer(x)                   ((((GLCapabilities)(x)) & GLCAPABILITIES_vertexBuffer_MASK) >> GLCAPABILITIES_vertexBuffer_SHIFT)
#define GLCAPABILITIES_SET_vertexBuffer(x, vertexBuffer)            (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_vertexBuffer_MASK)) | (((GLCapabilities)(vertexBuffer)) << GLCAPABILITIES_vertexBuffer_SHIFT)
#define GLCAPABILITIES_quads_SHIFT                       2
#define GLCAPABILITIES_quads_MASK                        0x4
#define GLCAPABILITIES_quads(x)                          ((((GLCapabilities)(x)) & GLCAPABILITIES_quads_MASK) >> GLCAPABILITIES_quads_SHIFT)
#define GLCAPABILITIES_SET_quads(x, quads)                   (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_quads_MASK)) | (((GLCapabilities)(quads)) << GLCAPABILITIES_quads_SHIFT)
#define GLCAPABILITIES_intAndDouble_SHIFT                3
#define GLCAPABILITIES_intAndDouble_MASK                 0x8
#define GLCAPABILITIES_intAndDouble(x)                   ((((GLCapabilities)(x)) & GLCAPABILITIES_intAndDouble_MASK) >> GLCAPABILITIES_intAndDouble_SHIFT)
#define GLCAPABILITIES_SET_intAndDouble(x, intAndDouble)            (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_intAndDouble_MASK)) | (((GLCapabilities)(intAndDouble)) << GLCAPABILITIES_intAndDouble_SHIFT)
#define GLCAPABILITIES_legacyFormats_SHIFT               4
#define GLCAPABILITIES_legacyFormats_MASK                0x10
#define GLCAPABILITIES_legacyFormats(x)                  ((((GLCapabilities)(x)) & GLCAPABILITIES_legacyFormats_MASK) >> GLCAPABILITIES_legacyFormats_SHIFT)
#define GLCAPABILITIES_SET_legacyFormats(x, legacyFormats)           (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_legacyFormats_MASK)) | (((GLCapabilities)(legacyFormats)) << GLCAPABILITIES_legacyFormats_SHIFT)
#define GLCAPABILITIES_nonPow2Textures_SHIFT             5
#define GLCAPABILITIES_nonPow2Textures_MASK              0x20
#define GLCAPABILITIES_nonPow2Textures(x)                ((((GLCapabilities)(x)) & GLCAPABILITIES_nonPow2Textures_MASK) >> GLCAPABILITIES_nonPow2Textures_SHIFT)
#define GLCAPABILITIES_SET_nonPow2Textures(x, nonPow2Textures)         (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_nonPow2Textures_MASK)) | (((GLCapabilities)(nonPow2Textures)) << GLCAPABILITIES_nonPow2Textures_SHIFT)
#define GLCAPABILITIES_vertexPointer_SHIFT               6
#define GLCAPABILITIES_vertexPointer_MASK                0x40
#define GLCAPABILITIES_vertexPointer(x)                  ((((GLCapabilities)(x)) & GLCAPABILITIES_vertexPointer_MASK) >> GLCAPABILITIES_vertexPointer_SHIFT)
#define GLCAPABILITIES_SET_vertexPointer(x, vertexPointer)           (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_vertexPointer_MASK)) | (((GLCapabilities)(vertexPointer)) << GLCAPABILITIES_vertexPointer_SHIFT)
#define GLCAPABILITIES_legacy_SHIFT                      7
#define GLCAPABILITIES_legacy_MASK                       0x80
#define GLCAPABILITIES_legacy(x)                         ((((GLCapabilities)(x)) & GLCAPABILITIES_legacy_MASK) >> GLCAPABILITIES_legacy_SHIFT)
#define GLCAPABILITIES_SET_legacy(x, legacy)                  (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_legacy_MASK)) | (((GLCapabilities)(legacy)) << GLCAPABILITIES_legacy_SHIFT)
#define GLCAPABILITIES_shaders_SHIFT                     8
#define GLCAPABILITIES_shaders_MASK                      0x100
#define GLCAPABILITIES_shaders(x)                        ((((GLCapabilities)(x)) & GLCAPABILITIES_shaders_MASK) >> GLCAPABILITIES_shaders_SHIFT)
#define GLCAPABILITIES_SET_shaders(x, shaders)                 (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_shaders_MASK)) | (((GLCapabilities)(shaders)) << GLCAPABILITIES_shaders_SHIFT)
#define GLCAPABILITIES_fixedFunction_SHIFT               9
#define GLCAPABILITIES_fixedFunction_MASK                0x200
#define GLCAPABILITIES_fixedFunction(x)                  ((((GLCapabilities)(x)) & GLCAPABILITIES_fixedFunction_MASK) >> GLCAPABILITIES_fixedFunction_SHIFT)
#define GLCAPABILITIES_SET_fixedFunction(x, fixedFunction)           (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_fixedFunction_MASK)) | (((GLCapabilities)(fixedFunction)) << GLCAPABILITIES_fixedFunction_SHIFT)
#define GLCAPABILITIES_immediate_SHIFT                   10
#define GLCAPABILITIES_immediate_MASK                    0x400
#define GLCAPABILITIES_immediate(x)                      ((((GLCapabilities)(x)) & GLCAPABILITIES_immediate_MASK) >> GLCAPABILITIES_immediate_SHIFT)
#define GLCAPABILITIES_SET_immediate(x, immediate)               (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_immediate_MASK)) | (((GLCapabilities)(immediate)) << GLCAPABILITIES_immediate_SHIFT)
#define GLCAPABILITIES_frameBuffer_SHIFT                 11
#define GLCAPABILITIES_frameBuffer_MASK                  0x800
#define GLCAPABILITIES_frameBuffer(x)                    ((((GLCapabilities)(x)) & GLCAPABILITIES_frameBuffer_MASK) >> GLCAPABILITIES_frameBuffer_SHIFT)
#define GLCAPABILITIES_SET_frameBuffer(x, frameBuffer)             (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_frameBuffer_MASK)) | (((GLCapabilities)(frameBuffer)) << GLCAPABILITIES_frameBuffer_SHIFT)
#define GLCAPABILITIES_pointSize_SHIFT                   12
#define GLCAPABILITIES_pointSize_MASK                    0x1000
#define GLCAPABILITIES_pointSize(x)                      ((((GLCapabilities)(x)) & GLCAPABILITIES_pointSize_MASK) >> GLCAPABILITIES_pointSize_SHIFT)
#define GLCAPABILITIES_SET_pointSize(x, pointSize)               (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_pointSize_MASK)) | (((GLCapabilities)(pointSize)) << GLCAPABILITIES_pointSize_SHIFT)
#define GLCAPABILITIES_vao_SHIFT                         13
#define GLCAPABILITIES_vao_MASK                          0x2000
#define GLCAPABILITIES_vao(x)                            ((((GLCapabilities)(x)) & GLCAPABILITIES_vao_MASK) >> GLCAPABILITIES_vao_SHIFT)
#define GLCAPABILITIES_SET_vao(x, vao)                     (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_vao_MASK)) | (((GLCapabilities)(vao)) << GLCAPABILITIES_vao_SHIFT)
#define GLCAPABILITIES_select_SHIFT                      14
#define GLCAPABILITIES_select_MASK                       0x4000
#define GLCAPABILITIES_select(x)                         ((((GLCapabilities)(x)) & GLCAPABILITIES_select_MASK) >> GLCAPABILITIES_select_SHIFT)
#define GLCAPABILITIES_SET_select(x, select)                  (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_select_MASK)) | (((GLCapabilities)(select)) << GLCAPABILITIES_select_SHIFT)
#define GLCAPABILITIES_debug_SHIFT                       15
#define GLCAPABILITIES_debug_MASK                        0x8000
#define GLCAPABILITIES_debug(x)                          ((((GLCapabilities)(x)) & GLCAPABILITIES_debug_MASK) >> GLCAPABILITIES_debug_SHIFT)
#define GLCAPABILITIES_SET_debug(x, debug)                   (x) = ((GLCapabilities)(x) & ~((GLCapabilities)GLCAPABILITIES_debug_MASK)) | (((GLCapabilities)(debug)) << GLCAPABILITIES_debug_SHIFT)


extern int (* HitRecord_compare)(C(HitRecord) * __this, C(HitRecord) * recordB, void * unused);

#define LIGHTFLAGS_off_SHIFT                             0
#define LIGHTFLAGS_off_MASK                              0x1
#define LIGHTFLAGS_off(x)                                ((((LightFlags)(x)) & LIGHTFLAGS_off_MASK) >> LIGHTFLAGS_off_SHIFT)
#define LIGHTFLAGS_SET_off(x, off)                         (x) = ((LightFlags)(x) & ~((LightFlags)LIGHTFLAGS_off_MASK)) | (((LightFlags)(off)) << LIGHTFLAGS_off_SHIFT)
#define LIGHTFLAGS_spot_SHIFT                            1
#define LIGHTFLAGS_spot_MASK                             0x2
#define LIGHTFLAGS_spot(x)                               ((((LightFlags)(x)) & LIGHTFLAGS_spot_MASK) >> LIGHTFLAGS_spot_SHIFT)
#define LIGHTFLAGS_SET_spot(x, spot)                        (x) = ((LightFlags)(x) & ~((LightFlags)LIGHTFLAGS_spot_MASK)) | (((LightFlags)(spot)) << LIGHTFLAGS_spot_SHIFT)
#define LIGHTFLAGS_omni_SHIFT                            2
#define LIGHTFLAGS_omni_MASK                             0x4
#define LIGHTFLAGS_omni(x)                               ((((LightFlags)(x)) & LIGHTFLAGS_omni_MASK) >> LIGHTFLAGS_omni_SHIFT)
#define LIGHTFLAGS_SET_omni(x, omni)                        (x) = ((LightFlags)(x) & ~((LightFlags)LIGHTFLAGS_omni_MASK)) | (((LightFlags)(omni)) << LIGHTFLAGS_omni_SHIFT)
#define LIGHTFLAGS_attenuation_SHIFT                     3
#define LIGHTFLAGS_attenuation_MASK                      0x8
#define LIGHTFLAGS_attenuation(x)                        ((((LightFlags)(x)) & LIGHTFLAGS_attenuation_MASK) >> LIGHTFLAGS_attenuation_SHIFT)
#define LIGHTFLAGS_SET_attenuation(x, attenuation)                 (x) = ((LightFlags)(x) & ~((LightFlags)LIGHTFLAGS_attenuation_MASK)) | (((LightFlags)(attenuation)) << LIGHTFLAGS_attenuation_SHIFT)
#define LIGHTFLAGS(off, spot, omni, attenuation)                            ((((((LightFlags)(off)) << LIGHTFLAGS_off_SHIFT) | ((LightFlags)(spot)) << LIGHTFLAGS_spot_SHIFT) | ((LightFlags)(omni)) << LIGHTFLAGS_omni_SHIFT) | ((LightFlags)(attenuation)) << LIGHTFLAGS_attenuation_SHIFT)


struct C(RenderStateFloat)
{
   union
   {
      float f;
      uint ui;
   };
};
struct CM(Surface)
{
   int width;
   int height;
   C(Point) offset;
   C(Box) box;
   C(Box) unclippedBox;
   void * driverData;
};
extern void (* Surface_area)(C(Surface) __this, int x1, int y1, int x2, int y2);

extern void (* Surface_bevel)(C(Surface) __this, C(bool) inner, int x, int y, int w, int h);

extern void (* Surface_blit)(C(Surface) __this, C(Bitmap) src, int dx, int dy, int sx, int sy, int w, int h);

extern void (* Surface_centerTextf)(C(Surface) __this, int x, int y, const char * format, ...);

extern void (* Surface_clear)(C(Surface) __this, C(ClearType) type);

extern void (* Surface_clip)(C(Surface) __this, C(Box) * box);

extern void (* Surface_drawLine)(C(Surface) __this, int x1, int y1, int x2, int y2);

extern void (* Surface_drawingChar)(C(Surface) __this, char value);

extern void (* Surface_filter)(C(Surface) __this, C(Bitmap) src, int dx, int dy, int sx, int sy, int w, int h, int sw, int sh);

extern void (* Surface_filterHTile)(C(Surface) __this, C(Bitmap) src, int dx, int dy, int w, int h);

extern void (* Surface_filterVTile)(C(Surface) __this, C(Bitmap) src, int dx, int dy, int w, int h);

extern C(Color) (* Surface_getBackground)(C(Surface) __this);

extern void (* Surface_getBox)(C(Surface) __this, C(Box) * value);

extern C(Display) (* Surface_getDisplay)(C(Surface) __this);

extern C(Font) * (* Surface_getFont)(C(Surface) __this);

extern C(Color) (* Surface_getForeground)(C(Surface) __this);

extern C(ColorAlpha) (* Surface_getPixel)(C(Surface) __this, int x, int y);

extern void (* Surface_getSize)(C(Surface) __this, int * w, int * h);

extern C(bool) (* Surface_getTextOpacity)(C(Surface) __this);

extern void (* Surface_gradient)(C(Surface) __this, C(ColorKey) * keys, int numKeys, float smoothness, C(GradientDirection) direction, int x1, int y1, int x2, int y2);

extern void (* Surface_hLine)(C(Surface) __this, int x1, int x2, int y);

extern void (* Surface_hTile)(C(Surface) __this, C(Bitmap) src, int dx, int dy, int w, int h);

extern void (* Surface_lineStipple)(C(Surface) __this, uint value);

extern void (* Surface_putPixel)(C(Surface) __this, int x, int y);

extern void (* Surface_rectangle)(C(Surface) __this, int x1, int y1, int x2, int y2);

extern void (* Surface_setBackground)(C(Surface) __this, C(ColorAlpha) value);

extern void (* Surface_setForeground)(C(Surface) __this, C(ColorAlpha) value);

extern void (* Surface_stretch)(C(Surface) __this, C(Bitmap) src, int dx, int dy, int sx, int sy, int w, int h, int sw, int sh);

extern void (* Surface_textExtent)(C(Surface) __this, const char * text, int len, int * width, int * height);

extern void (* Surface_textExtent2)(C(Surface) __this, const char * text, int len, int * width, int * height, int prevGlyph, int * rPrevGlyph, int * overHang);

extern void (* Surface_textFont)(C(Surface) __this, C(Font) * value);

extern void (* Surface_textOpacity)(C(Surface) __this, C(bool) value);

extern void (* Surface_thinBevel)(C(Surface) __this, C(bool) inner, int x, int y, int w, int h);

extern void (* Surface_tile)(C(Surface) __this, C(Bitmap) src, int dx, int dy, int w, int h);

extern void (* Surface_vLine)(C(Surface) __this, int y1, int y2, int x);

extern void (* Surface_vTile)(C(Surface) __this, C(Bitmap) src, int dx, int dy, int w, int h);

extern void (* Surface_writeText)(C(Surface) __this, int x, int y, const char * text, int len);

extern void (* Surface_writeText2)(C(Surface) __this, int x, int y, const char * text, int len, int prevGlyph, int * rPrevGlyph);

extern void (* Surface_writeTextDots)(C(Surface) __this, C(Alignment) alignment, int x, int y, int width, const char * text, int len);

extern void (* Surface_writeTextDotsf)(C(Surface) __this, C(Alignment) alignment, int x, int y, int width, const char * format, ...);

extern void (* Surface_writeTextf)(C(Surface) __this, int x, int y, const char * format, ...);

extern C(Property) * PROPERTY(Surface, alphaWrite);
extern void (* Surface_set_alphaWrite)(C(Surface) s, C(AlphaWriteMode) value);
extern C(AlphaWriteMode) (* Surface_get_alphaWrite)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, blend);
extern void (* Surface_set_blend)(C(Surface) s, C(bool) value);
extern C(bool) (* Surface_get_blend)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, bitmap);
extern C(Bitmap) (* Surface_get_bitmap)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, outlineColor);
extern void (* Surface_set_outlineColor)(C(Surface) s, C(ColorAlpha) value);
extern C(ColorAlpha) (* Surface_get_outlineColor)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, foreground);
extern void (* Surface_set_foreground)(C(Surface) s, C(ColorAlpha) value);
extern C(ColorAlpha) (* Surface_get_foreground)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, background);
extern void (* Surface_set_background)(C(Surface) s, C(ColorAlpha) value);
extern C(ColorAlpha) (* Surface_get_background)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, blitTint);
extern void (* Surface_set_blitTint)(C(Surface) s, C(ColorAlpha) value);
extern C(ColorAlpha) (* Surface_get_blitTint)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, lineStipple);
extern void (* Surface_set_lineStipple)(C(Surface) s, uint value);

extern C(Property) * PROPERTY(Surface, size);
extern void (* Surface_get_size)(C(Surface) s, C(Size) * value);

extern C(Property) * PROPERTY(Surface, display);
extern C(Display) (* Surface_get_display)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, font);
extern void (* Surface_set_font)(C(Surface) s, C(Font) * value);
extern C(Font) * (* Surface_get_font)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, textOpacity);
extern void (* Surface_set_textOpacity)(C(Surface) s, C(bool) value);
extern C(bool) (* Surface_get_textOpacity)(C(Surface) s);

extern C(Property) * PROPERTY(Surface, drawingChar);
extern void (* Surface_set_drawingChar)(C(Surface) s, byte value);

extern C(Property) * PROPERTY(Surface, clipping);
extern void (* Surface_set_clipping)(C(Surface) s, const C(Box) * value);

extern int (* bestColorMatch)(C(ColorAlpha) * palette, int start, int end, C(Color) rgb);
extern byte (* getColorDepthShifts)(C(PixelFormat) format);
extern C(Material) * (* getDefaultMaterial)(void);
extern C(ColorAlpha) * (* getDefaultPalette)(void);
extern int (* getDepthBits)(C(PixelFormat) colorDepth);
extern int (* getResolutionHeight)(C(Resolution) resolution);
extern int (* getResolutionWidth)(C(Resolution) resolution);
extern C(Map) (* listAvailableFonts)(void);
extern C(ColorAlpha) * (* loadPalette)(const char * fileName, const char * type);
extern void (* paletteGradient)(C(ColorAlpha) * palette, int numColors, C(ColorKey) * keys, int numKeys, float smoothness);
extern C(FaceInfo) * (* resolveCharFont)(constString faceName, float size, C(FontFlags) flags, constString lang, unichar testChar);
extern C(Array) (* resolveFont)(constString faceName, float size, C(FontFlags) flags);
extern void (* setPrintingDocumentName)(constString name);

// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||gfx||drivers  ///////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
#if CPP11
enum C(SwizzleMode) : int
#else
typedef int C(SwizzleMode);
enum C(SwizzleMode)
#endif
{
   SwizzleMode_off = 0x0,
   SwizzleMode_alpha = 0x1,
   SwizzleMode_red = 0x2
};

#if CPP11
enum C(MatrixMode) : int
#else
typedef int C(MatrixMode);
enum C(MatrixMode)
#endif
{
   MatrixMode_modelView = 0x1700,
   MatrixMode_projection = 0x1701,
   MatrixMode_texture = 0x1702
};

typedef struct C(GLEAB) C(GLEAB);
#if CPP11
enum C(GLBufferUsage) : int
#else
typedef int C(GLBufferUsage);
enum C(GLBufferUsage)
#endif
{
   GLBufferUsage_staticDraw = 0x0,
   GLBufferUsage_dynamicDraw = 0x1,
   GLBufferUsage_streamDraw = 0x2
};

#if CPP11
enum C(GLBufferContents) : int
#else
typedef int C(GLBufferContents);
enum C(GLBufferContents)
#endif
{
   GLBufferContents_vertex = 0x0,
   GLBufferContents_normal = 0x1,
   GLBufferContents_texCoord = 0x2,
   GLBufferContents_color = 0x3,
   GLBufferContents_tangent1 = 0x4,
   GLBufferContents_tangent2 = 0x5,
   GLBufferContents_lightVector = 0x6
};

typedef struct C(GLAB) C(GLAB);
typedef uint32 C(DefaultShaderBits);
typedef C(Shader) C(DefaultShader);
typedef struct C(CompiledShader) C(CompiledShader);
typedef struct C(CompiledDefaultShader) C(CompiledDefaultShader);
// end -- moved backwards outputs
#define LIGHTSHIFT (5)

#define LIGHTSTEPS (1 << LIGHTSHIFT)

#define noAB (__extension__ ({ GLAB __simpleStruct0 = { 0 };  __simpleStruct0; }))

#define noEAB (__extension__ ({ GLEAB __simpleStruct0 = { 0 };  __simpleStruct0; }))

#if CPP11
enum C(GLIMTKMode) : int
#else
typedef int C(GLIMTKMode);
enum C(GLIMTKMode)
#endif
{
   GLIMTKMode_unset = -1,
   GLIMTKMode_points = 0x0,
   GLIMTKMode_lines = 0x1,
   GLIMTKMode_lineLoop = 0x2,
   GLIMTKMode_lineStrip = 0x3,
   GLIMTKMode_triangles = 0x4,
   GLIMTKMode_triangleStrip = 0x5,
   GLIMTKMode_triangleFan = 0x6,
   GLIMTKMode_quads = 0x7,
   GLIMTKMode_quadStrip = 0x8,
   GLIMTKMode_polygon = 0x9
};

#if CPP11
enum C(GLMSWhatToGet) : int
#else
typedef int C(GLMSWhatToGet);
enum C(GLMSWhatToGet)
#endif
{
   GLMSWhatToGet_modelViewMatrix = 0xBA6,
   GLMSWhatToGet_projectionMatrix = 0xBA7,
   GLMSWhatToGet_textureMatrix = 0xBA8
};

typedef struct C(LFBDisplay) C(LFBDisplay);
typedef C(DisplayDriver) C(LFBDisplayDriver);
typedef struct C(LFBSurface) C(LFBSurface);
typedef struct C(LFBSystem) C(LFBSystem);
#if CPP11
enum C(LightMode) : int
#else
typedef int C(LightMode);
enum C(LightMode)
#endif
{
   LightMode_off = 0x0,
   LightMode_dir = 0x1,
   LightMode_pos = 0x2,
   LightMode_posAtt = 0x3,
   LightMode_posSpot = 0x4,
   LightMode_posSpotAtt = 0x5
};

struct C(CompiledDefaultShader)
{
   int program;
   int vertex;
   int fragment;
   int uPrjMatrix;
   int uMVMatrix;
   int uTextureMatrix;
   int uNormalsMatrix;
   int uFogDensity;
   int uFogColor;
   int uGlobalAmbient;
   int uNearPlane;
   int uLightsPos[8];
   int uLightsDiffuse[8];
   int uLightsAmbient[8];
   int uLightsSpecular[8];
   int uLightsAtt[8];
   int uLightsSpotDir[8];
   int uLightsSpotCutOffCos[8];
   int uLightsSpotExp[8];
   int uMatDiffuse;
   int uMatAmbient;
   int uMatSpecular;
   int uMatEmissive;
   int uMatPower;
   int uMatOpacity;
   int uDiffuseTex;
   int uBumpTex;
   int uSpecularTex;
   int uEnvTex;
   int uReflectTex;
   int uRefractionETA;
   int uMatReflectivity;
   int uCubeMapMatrix;
};
extern void (* CompiledDefaultShader_registerUniforms)(C(CompiledDefaultShader) * __this, int program, C(DefaultShaderBits) state);

struct C(CompiledShader)
{
   int program;
   int vertex;
   int fragment;
};
extern void (* CompiledShader_free)(C(CompiledShader) * __this);

struct CM(DefaultShader)
{
   float modelView[16];
   float projection[16];
   float matTexture[16];
   float cubemap_matrix[9];
   float normalsMatrix[9];
   float nearPlane;
   float globalAmbient[3];
   float lDiffuse[8][4];
   float lAmbient[8][3];
   float lSpecular[8][3];
   float lPosition[8][3];
   float lAtt[8][3];
   float lCutOffCos[8];
   float lSpotDir[8][3];
   float lSpotExp[8];
   float diffuse[4];
   float ambient[3];
   float specular[3];
   float emissive[3];
   float power;
   float refractionETA;
   float reflectivity;
   C(bool) fogOn;
   uint lightBits;
   float fogDensity;
   float fogColor[3];
   float color[4];
   C(DefaultShaderBits) backLightState;
};
extern void (* DefaultShader_debugging)(C(DefaultShader) __this, C(bool) on);

extern void (* DefaultShader_fog)(C(DefaultShader) __this, C(bool) on);

extern void (* DefaultShader_lighting)(C(DefaultShader) __this, C(bool) on);

extern void (* DefaultShader_setCamera)(C(DefaultShader) __this, C(Camera) camera);

extern void (* DefaultShader_setColor)(C(DefaultShader) __this, float r, float g, float b, float a);

extern void (* DefaultShader_setFogColor)(C(DefaultShader) __this, float r, float g, float b);

extern void (* DefaultShader_setFogDensity)(C(DefaultShader) __this, float density);

extern void (* DefaultShader_setGlobalAmbient)(C(DefaultShader) __this, float r, float g, float b, float a);

extern void (* DefaultShader_setLight)(C(DefaultShader) __this, C(Display) display, uint id, C(Light) * light);

extern void (* DefaultShader_setPerVertexColor)(C(DefaultShader) __this, C(bool) perVertexColor);

extern void (* DefaultShader_setSimpleMaterial)(C(DefaultShader) __this, C(ColorAlpha) color, C(bool) twoSided);

extern C(DefaultShader) (* DefaultShader_shader)();

extern void (* DefaultShader_swizzle)(C(DefaultShader) __this, C(SwizzleMode) swizzle);

extern void (* DefaultShader_texturing)(C(DefaultShader) __this, C(bool) on);

#define DEFAULTSHADERBITS_lighting_SHIFT                 0
#define DEFAULTSHADERBITS_lighting_MASK                  0x1
#define DEFAULTSHADERBITS_lighting(x)                    ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_lighting_MASK) >> DEFAULTSHADERBITS_lighting_SHIFT)
#define DEFAULTSHADERBITS_SET_lighting(x, lighting)             (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_lighting_MASK)) | (((DefaultShaderBits)(lighting)) << DEFAULTSHADERBITS_lighting_SHIFT)
#define DEFAULTSHADERBITS_nonLocalViewer_SHIFT           1
#define DEFAULTSHADERBITS_nonLocalViewer_MASK            0x2
#define DEFAULTSHADERBITS_nonLocalViewer(x)              ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_nonLocalViewer_MASK) >> DEFAULTSHADERBITS_nonLocalViewer_SHIFT)
#define DEFAULTSHADERBITS_SET_nonLocalViewer(x, nonLocalViewer)       (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_nonLocalViewer_MASK)) | (((DefaultShaderBits)(nonLocalViewer)) << DEFAULTSHADERBITS_nonLocalViewer_SHIFT)
#define DEFAULTSHADERBITS_twoSided_SHIFT                 2
#define DEFAULTSHADERBITS_twoSided_MASK                  0x4
#define DEFAULTSHADERBITS_twoSided(x)                    ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_twoSided_MASK) >> DEFAULTSHADERBITS_twoSided_SHIFT)
#define DEFAULTSHADERBITS_SET_twoSided(x, twoSided)             (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_twoSided_MASK)) | (((DefaultShaderBits)(twoSided)) << DEFAULTSHADERBITS_twoSided_SHIFT)
#define DEFAULTSHADERBITS_specular_SHIFT                 3
#define DEFAULTSHADERBITS_specular_MASK                  0x8
#define DEFAULTSHADERBITS_specular(x)                    ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_specular_MASK) >> DEFAULTSHADERBITS_specular_SHIFT)
#define DEFAULTSHADERBITS_SET_specular(x, specular)             (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_specular_MASK)) | (((DefaultShaderBits)(specular)) << DEFAULTSHADERBITS_specular_SHIFT)
#define DEFAULTSHADERBITS_separateSpecular_SHIFT         4
#define DEFAULTSHADERBITS_separateSpecular_MASK          0x10
#define DEFAULTSHADERBITS_separateSpecular(x)            ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_separateSpecular_MASK) >> DEFAULTSHADERBITS_separateSpecular_SHIFT)
#define DEFAULTSHADERBITS_SET_separateSpecular(x, separateSpecular)     (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_separateSpecular_MASK)) | (((DefaultShaderBits)(separateSpecular)) << DEFAULTSHADERBITS_separateSpecular_SHIFT)
#define DEFAULTSHADERBITS_blinnSpecular_SHIFT            5
#define DEFAULTSHADERBITS_blinnSpecular_MASK             0x20
#define DEFAULTSHADERBITS_blinnSpecular(x)               ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_blinnSpecular_MASK) >> DEFAULTSHADERBITS_blinnSpecular_SHIFT)
#define DEFAULTSHADERBITS_SET_blinnSpecular(x, blinnSpecular)        (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_blinnSpecular_MASK)) | (((DefaultShaderBits)(blinnSpecular)) << DEFAULTSHADERBITS_blinnSpecular_SHIFT)
#define DEFAULTSHADERBITS_lightBits_SHIFT                6
#define DEFAULTSHADERBITS_lightBits_MASK                 0x3FFFFFC0
#define DEFAULTSHADERBITS_lightBits(x)                   ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_lightBits_MASK) >> DEFAULTSHADERBITS_lightBits_SHIFT)
#define DEFAULTSHADERBITS_SET_lightBits(x, lightBits)            (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_lightBits_MASK)) | (((DefaultShaderBits)(lightBits)) << DEFAULTSHADERBITS_lightBits_SHIFT)
#define DEFAULTSHADERBITS_perVertexColor_SHIFT           30
#define DEFAULTSHADERBITS_perVertexColor_MASK            0x40000000
#define DEFAULTSHADERBITS_perVertexColor(x)              ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_perVertexColor_MASK) >> DEFAULTSHADERBITS_perVertexColor_SHIFT)
#define DEFAULTSHADERBITS_SET_perVertexColor(x, perVertexColor)       (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_perVertexColor_MASK)) | (((DefaultShaderBits)(perVertexColor)) << DEFAULTSHADERBITS_perVertexColor_SHIFT)
#define DEFAULTSHADERBITS_swizzle_SHIFT                  31
#define DEFAULTSHADERBITS_swizzle_MASK                   0x180000000
#define DEFAULTSHADERBITS_swizzle(x)                     ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_swizzle_MASK) >> DEFAULTSHADERBITS_swizzle_SHIFT)
#define DEFAULTSHADERBITS_SET_swizzle(x, swizzle)              (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_swizzle_MASK)) | (((DefaultShaderBits)(swizzle)) << DEFAULTSHADERBITS_swizzle_SHIFT)
#define DEFAULTSHADERBITS_textureMatrix_SHIFT            33
#define DEFAULTSHADERBITS_textureMatrix_MASK             0x200000000
#define DEFAULTSHADERBITS_textureMatrix(x)               ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_textureMatrix_MASK) >> DEFAULTSHADERBITS_textureMatrix_SHIFT)
#define DEFAULTSHADERBITS_SET_textureMatrix(x, textureMatrix)        (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_textureMatrix_MASK)) | (((DefaultShaderBits)(textureMatrix)) << DEFAULTSHADERBITS_textureMatrix_SHIFT)
#define DEFAULTSHADERBITS_texturing_SHIFT                34
#define DEFAULTSHADERBITS_texturing_MASK                 0x400000000
#define DEFAULTSHADERBITS_texturing(x)                   ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_texturing_MASK) >> DEFAULTSHADERBITS_texturing_SHIFT)
#define DEFAULTSHADERBITS_SET_texturing(x, texturing)            (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_texturing_MASK)) | (((DefaultShaderBits)(texturing)) << DEFAULTSHADERBITS_texturing_SHIFT)
#define DEFAULTSHADERBITS_cubeMap_SHIFT                  35
#define DEFAULTSHADERBITS_cubeMap_MASK                   0x800000000
#define DEFAULTSHADERBITS_cubeMap(x)                     ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_cubeMap_MASK) >> DEFAULTSHADERBITS_cubeMap_SHIFT)
#define DEFAULTSHADERBITS_SET_cubeMap(x, cubeMap)              (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_cubeMap_MASK)) | (((DefaultShaderBits)(cubeMap)) << DEFAULTSHADERBITS_cubeMap_SHIFT)
#define DEFAULTSHADERBITS_modelView_SHIFT                36
#define DEFAULTSHADERBITS_modelView_MASK                 0x1000000000
#define DEFAULTSHADERBITS_modelView(x)                   ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_modelView_MASK) >> DEFAULTSHADERBITS_modelView_SHIFT)
#define DEFAULTSHADERBITS_SET_modelView(x, modelView)            (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_modelView_MASK)) | (((DefaultShaderBits)(modelView)) << DEFAULTSHADERBITS_modelView_SHIFT)
#define DEFAULTSHADERBITS_fog_SHIFT                      37
#define DEFAULTSHADERBITS_fog_MASK                       0x2000000000
#define DEFAULTSHADERBITS_fog(x)                         ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_fog_MASK) >> DEFAULTSHADERBITS_fog_SHIFT)
#define DEFAULTSHADERBITS_SET_fog(x, fog)                  (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_fog_MASK)) | (((DefaultShaderBits)(fog)) << DEFAULTSHADERBITS_fog_SHIFT)
#define DEFAULTSHADERBITS_normalsMapping_SHIFT           38
#define DEFAULTSHADERBITS_normalsMapping_MASK            0x4000000000
#define DEFAULTSHADERBITS_normalsMapping(x)              ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_normalsMapping_MASK) >> DEFAULTSHADERBITS_normalsMapping_SHIFT)
#define DEFAULTSHADERBITS_SET_normalsMapping(x, normalsMapping)       (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_normalsMapping_MASK)) | (((DefaultShaderBits)(normalsMapping)) << DEFAULTSHADERBITS_normalsMapping_SHIFT)
#define DEFAULTSHADERBITS_specularMapping_SHIFT          39
#define DEFAULTSHADERBITS_specularMapping_MASK           0x8000000000
#define DEFAULTSHADERBITS_specularMapping(x)             ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_specularMapping_MASK) >> DEFAULTSHADERBITS_specularMapping_SHIFT)
#define DEFAULTSHADERBITS_SET_specularMapping(x, specularMapping)      (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_specularMapping_MASK)) | (((DefaultShaderBits)(specularMapping)) << DEFAULTSHADERBITS_specularMapping_SHIFT)
#define DEFAULTSHADERBITS_environmentMapping_SHIFT       40
#define DEFAULTSHADERBITS_environmentMapping_MASK        0x10000000000
#define DEFAULTSHADERBITS_environmentMapping(x)          ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_environmentMapping_MASK) >> DEFAULTSHADERBITS_environmentMapping_SHIFT)
#define DEFAULTSHADERBITS_SET_environmentMapping(x, environmentMapping)   (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_environmentMapping_MASK)) | (((DefaultShaderBits)(environmentMapping)) << DEFAULTSHADERBITS_environmentMapping_SHIFT)
#define DEFAULTSHADERBITS_reflection_SHIFT               41
#define DEFAULTSHADERBITS_reflection_MASK                0x20000000000
#define DEFAULTSHADERBITS_reflection(x)                  ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_reflection_MASK) >> DEFAULTSHADERBITS_reflection_SHIFT)
#define DEFAULTSHADERBITS_SET_reflection(x, reflection)           (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_reflection_MASK)) | (((DefaultShaderBits)(reflection)) << DEFAULTSHADERBITS_reflection_SHIFT)
#define DEFAULTSHADERBITS_reflectionMap_SHIFT            42
#define DEFAULTSHADERBITS_reflectionMap_MASK             0x40000000000
#define DEFAULTSHADERBITS_reflectionMap(x)               ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_reflectionMap_MASK) >> DEFAULTSHADERBITS_reflectionMap_SHIFT)
#define DEFAULTSHADERBITS_SET_reflectionMap(x, reflectionMap)        (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_reflectionMap_MASK)) | (((DefaultShaderBits)(reflectionMap)) << DEFAULTSHADERBITS_reflectionMap_SHIFT)
#define DEFAULTSHADERBITS_refraction_SHIFT               43
#define DEFAULTSHADERBITS_refraction_MASK                0x80000000000
#define DEFAULTSHADERBITS_refraction(x)                  ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_refraction_MASK) >> DEFAULTSHADERBITS_refraction_SHIFT)
#define DEFAULTSHADERBITS_SET_refraction(x, refraction)           (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_refraction_MASK)) | (((DefaultShaderBits)(refraction)) << DEFAULTSHADERBITS_refraction_SHIFT)
#define DEFAULTSHADERBITS_debugging_SHIFT                44
#define DEFAULTSHADERBITS_debugging_MASK                 0x100000000000
#define DEFAULTSHADERBITS_debugging(x)                   ((((DefaultShaderBits)(x)) & DEFAULTSHADERBITS_debugging_MASK) >> DEFAULTSHADERBITS_debugging_SHIFT)
#define DEFAULTSHADERBITS_SET_debugging(x, debugging)            (x) = ((DefaultShaderBits)(x) & ~((DefaultShaderBits)DEFAULTSHADERBITS_debugging_MASK)) | (((DefaultShaderBits)(debugging)) << DEFAULTSHADERBITS_debugging_SHIFT)


struct C(GLAB)
{
   uint buffer;
};
extern void (* GLAB_allocate)(C(GLAB) * __this, uint size, void * data, C(GLBufferUsage) usage);

extern void (* GLAB_deleteBuffers)(int count, C(GLAB) * buffers);

extern void (* GLAB_free)(C(GLAB) * __this);

extern void (* GLAB_upload)(C(GLAB) * __this, uint offset, uint size, void * data);

extern void (* GLAB_use)(C(GLAB) * __this, C(GLBufferContents) contents, int n, int type, uint stride, void * pointer);

extern void (* GLAB_useVertTrans)(C(GLAB) * __this, uint count, int n, int type, uint stride, void * pointer);

struct C(GLEAB)
{
   uint buffer;
};
extern void (* GLEAB_allocate)(C(GLEAB) * __this, uint size, void * data, C(GLBufferUsage) usage);

extern void (* GLEAB_draw)(C(GLEAB) * __this, int primType, int count, int type, void * indices);

extern void (* GLEAB_free)(C(GLEAB) * __this);

extern void (* GLEAB_upload)(C(GLEAB) * __this, uint offset, uint size, void * data);

struct C(LFBDisplay)
{
   C(Bitmap) bitmap;
   byte rgbLookup[32768];
   byte lightTable[256][LIGHTSTEPS];
   C(OldList) updateBoxes;
   int x;
   int y;
   C(bool) selfManaged;
   void (* displayCallback)(C(Display) display, C(Box) updateBox);
};
struct C(LFBSurface)
{
   C(Font) * font;
   C(bool) opaqueText;
   int xOffset;
   C(bool) writingText;
   C(bool) writingOutline;
   C(Bitmap) bitmap;
   uint foreground;
   uint background;
   C(ColorAlpha) foregroundRgb;
   uint16 stipple;
   byte drawingChar;
   byte * paletteShades;
   C(bool) clearing;
};
struct C(LFBSystem)
{
   int format;
   C(ColorAlpha) * palette;
   byte rgbLookup[32768];
};
extern C(bool) (* Shader_activate)(C(Shader) __this);

extern int M_VTBLID(Shader, bindAttribs);
#define Shader_bindAttribs(__i, program) \
   VMETHOD(CO(Shader), Shader, bindAttribs, __i, void, \
      C(Shader) _ARG int, \
      __i _ARG program)
extern C(Method) * METHOD(Shader, bindAttribs);
extern void (* Shader_free)(C(Shader) __this);

extern int M_VTBLID(Shader, getDefinitions);
#define Shader_getDefinitions(__i, state) \
   VMETHOD(CO(Shader), Shader, getDefinitions, __i, C(ZString), \
      C(Shader) _ARG uint64, \
      __i _ARG state)
extern C(Method) * METHOD(Shader, getDefinitions);
extern C(CompiledShader) * (* Shader_load)(C(Shader) __this, uint64 state);

extern int M_VTBLID(Shader, registerShader);
#define Shader_registerShader(__i, program, state) \
   VMETHOD(CO(Shader), Shader, registerShader, __i, C(CompiledShader) *, \
      C(Shader) _ARG int _ARG uint64, \
      __i _ARG program _ARG state)
extern C(Method) * METHOD(Shader, registerShader);
extern void (* Shader_select)(C(Shader) __this);

extern int M_VTBLID(Shader, setMaterial);
#define Shader_setMaterial(__i, material, flags) \
   VMETHOD(CO(Shader), Shader, setMaterial, __i, void, \
      C(Shader) _ARG C(Material) * _ARG C(MeshFeatures), \
      __i _ARG material _ARG flags)
extern C(Method) * METHOD(Shader, setMaterial);
extern int M_VTBLID(Shader, updateMatrix);
#define Shader_updateMatrix(__i, mode, matrix, isIdentity) \
   VMETHOD(CO(Shader), Shader, updateMatrix, __i, void, \
      C(Shader) _ARG C(MatrixMode) _ARG C(Matrix) * _ARG C(bool), \
      __i _ARG mode _ARG matrix _ARG isIdentity)
extern C(Method) * METHOD(Shader, updateMatrix);
extern int M_VTBLID(Shader, uploadUniforms);
#define Shader_uploadUniforms(__i, shader) \
   VMETHOD(CO(Shader), Shader, uploadUniforms, __i, void, \
      C(Shader) _ARG C(CompiledShader) *, \
      __i _ARG shader)
extern C(Method) * METHOD(Shader, uploadUniforms);
extern C(Property) * PROPERTY(Shader, vertexShaderFile);
extern void (* Shader_set_vertexShaderFile)(C(Shader) s, constString value);

extern C(Property) * PROPERTY(Shader, fragmentShaderFile);
extern void (* Shader_set_fragmentShaderFile)(C(Shader) s, constString value);

extern C(Property) * PROPERTY(Shader, vertexShader);
extern void (* Shader_set_vertexShader)(C(Shader) s, constString value);

extern C(Property) * PROPERTY(Shader, fragmentShader);
extern void (* Shader_set_fragmentShader)(C(Shader) s, constString value);

extern void (* gLABBindBuffer)(int target, uint buffer);
extern void (* gLSetupFog)(C(bool) enable);
extern void (* gLSetupLighting)(C(bool) enable);
extern void (* gLSetupTexturing)(C(bool) enable);
extern void (* useSingleGLContext)(C(bool) useSingle);
extern void (* glimtkBegin)(C(GLIMTKMode) mode);
extern void (* glimtkColor3f)(float r, float g, float b);
extern void (* glimtkColor4f)(float r, float g, float b, float a);
extern void (* glimtkColor4fv)(float * a);
extern void (* glimtkColor4ub)(byte r, byte g, byte b, byte a);
extern void (* glimtkEnd)(void);
extern void (* glimtkNormal3d)(double x, double y, double z);
extern void (* glimtkNormal3f)(float x, float y, float z);
extern void (* glimtkNormal3fd)(double * coords);
extern void (* glimtkNormal3fv)(float * coords);
extern void (* glimtkRecti)(int a, int b, int c, int d);
extern void (* glimtkTexCoord2d)(double x, double y);
extern void (* glimtkTexCoord2f)(float x, float y);
extern void (* glimtkTexCoord2fv)(float * a);
extern void (* glimtkTexCoord2i)(int x, int y);
extern void (* glimtkVertex2d)(double x, double y);
extern void (* glimtkVertex2f)(float x, float y);
extern void (* glimtkVertex2i)(int x, int y);
extern void (* glimtkVertex3d)(double x, double y, double z);
extern void (* glimtkVertex3dv)(double * coords);
extern void (* glimtkVertex3f)(float x, float y, float z);
extern void (* glimtkVertex3fv)(float * coords);
extern void (* glmsFlushMatrices)(void);
extern void (* glmsFrustum)(double l, double r, double b, double t, double n, double f);
extern void (* glmsGetDoublev)(C(GLMSWhatToGet) what, double * i);
extern double (* glmsGetNearPlane)(void);
extern void (* glmsLoadIdentity)(void);
extern void (* glmsLoadMatrix)(C(Matrix) * matrix);
extern void (* glmsLoadMatrixd)(double * i);
extern void (* glmsLoadMatrixf)(float * i);
extern void (* glmsMatrixMode)(C(MatrixMode) mode);
extern void (* glmsMultMatrixd)(double * i);
extern void (* glmsOrtho)(double l, double r, double b, double t, double n, double f);
extern void (* glmsPopMatrix)(void);
extern void (* glmsPushMatrix)(void);
extern void (* glmsRotated)(double angle, double x, double y, double z);
extern void (* glmsScaled)(double a, double b, double c);
extern void (* glmsSetNearPlane)(double value);
extern void (* glmsTranslated)(double a, double b, double c);
extern void (* glsupLightModeli)(uint pname, int param);
extern void (* glsupLineStipple)(int i, uint16 j);

// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||gfx3D||meshes  //////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
typedef struct C(Object) C(Sphere);
typedef struct C(Object) C(SkyBox);
typedef struct C(Object) C(Cube);
// end -- moved backwards outputs
extern C(bool) (* Cube_create)(C(Cube) * __this, C(DisplaySystem) displaySystem);

extern C(Property) * PROPERTY(Cube, size);
extern void (* Cube_set_size)(C(Cube) * c, const C(Vector3Df) * value);

extern C(bool) (* SkyBox_create)(C(SkyBox) * __this, C(DisplaySystem) displaySystem);

extern void (* SkyBox_render)(C(SkyBox) * __this, C(Camera) camera, C(Display) display);

extern C(Property) * PROPERTY(SkyBox, size);
extern void (* SkyBox_set_size)(C(SkyBox) * s, const C(Vector3Df) * value);

extern C(Property) * PROPERTY(SkyBox, folder);
extern void (* SkyBox_set_folder)(C(SkyBox) * s, const char * value);

extern C(Property) * PROPERTY(SkyBox, extension);
extern void (* SkyBox_set_extension)(C(SkyBox) * s, const char * value);

extern C(Property) * PROPERTY(SkyBox, newStyle);
extern void (* SkyBox_set_newStyle)(C(SkyBox) * s, C(bool) value);

extern C(Property) * PROPERTY(SkyBox, cubeMap);
extern void (* SkyBox_set_cubeMap)(C(SkyBox) * s, C(CubeMap) value);

extern C(bool) (* Sphere_create)(C(Sphere) * __this, C(DisplaySystem) displaySystem);

extern C(Property) * PROPERTY(Sphere, numLat);
extern void (* Sphere_set_numLat)(C(Sphere) * s, int value);

extern C(Property) * PROPERTY(Sphere, numLon);
extern void (* Sphere_set_numLon)(C(Sphere) * s, int value);

extern C(Property) * PROPERTY(Sphere, flattenedBody);
extern void (* Sphere_set_flattenedBody)(C(Sphere) * s, float value);


// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||gui||dialogs  ///////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
#if CPP11
enum C(MessageBoxType) : int
#else
typedef int C(MessageBoxType);
enum C(MessageBoxType)
#endif
{
   MessageBoxType_ok = 0x0,
   MessageBoxType_yesNo = 0x1,
   MessageBoxType_okCancel = 0x2,
   MessageBoxType_yesNoCancel = 0x3
};

typedef struct C(FileType) C(FileType);
#if CPP11
enum C(FileNameType) : int
#else
typedef int C(FileNameType);
enum C(FileNameType)
#endif
{
   FileNameType_folder = 0x0,
   FileNameType_folderOpen = 0x1,
   FileNameType_computer = 0x2,
   FileNameType_drive = 0x3,
   FileNameType_netDrive = 0x4,
   FileNameType_cdrom = 0x5,
   FileNameType_removable = 0x6,
   FileNameType_floppy = 0x7,
   FileNameType_network = 0x8,
   FileNameType_server = 0x9,
   FileNameType_share = 0xA,
   FileNameType_normalFile = 0xB,
   FileNameType_ewsFile = 0xC,
   FileNameType_epjFile = 0xD,
   FileNameType_ecFile = 0xE,
   FileNameType_ehFile = 0xF,
   FileNameType_cFile = 0x10,
   FileNameType_hFile = 0x11,
   FileNameType_cppFile = 0x12,
   FileNameType_hppFile = 0x13,
   FileNameType_textFile = 0x14,
   FileNameType_webFile = 0x15,
   FileNameType_pictureFile = 0x16,
   FileNameType_soundFile = 0x17,
   FileNameType_archiveFile = 0x18,
   FileNameType_packageFile = 0x19,
   FileNameType_opticalMediaImageFile = 0x1A
};

#if CPP11
enum C(FileForceExtension) : int
#else
typedef int C(FileForceExtension);
enum C(FileForceExtension)
#endif
{
   FileForceExtension_never = 0x0,
   FileForceExtension_always = 0x1,
   FileForceExtension_whenNoneGiven = 0x2
};

typedef struct C(FileFilter) C(FileFilter);
#if CPP11
enum C(FileDialogType) : int
#else
typedef int C(FileDialogType);
enum C(FileDialogType)
#endif
{
   FileDialogType_open = 0x0,
   FileDialogType_save = 0x1,
   FileDialogType_selectDir = 0x2,
   FileDialogType_multiOpen = 0x3
};

typedef C(CommonControl) C(EditBox);
// end -- moved backwards outputs
typedef C(Window) C(ColorPicker);
typedef C(Window) C(CreateDirectoryDialog);
typedef C(Window) C(FileDialog);
typedef struct C(FileName) C(FileName);
typedef C(Window) C(FindDialog);
typedef C(Window) C(GoToDialog);
typedef C(Window) C(MessageBox);
typedef C(Window) C(ReplaceDialog);
typedef C(Window) C(WindowList);
extern C(Property) * PROPERTY(ColorPicker, color);
extern void (* ColorPicker_set_color)(C(ColorPicker) c, C(Color) value);
extern C(Color) (* ColorPicker_get_color)(C(ColorPicker) c);

extern C(Property) * PROPERTY(ColorPicker, hasAlpha);
extern void (* ColorPicker_set_hasAlpha)(C(ColorPicker) c, C(bool) value);
extern C(bool) (* ColorPicker_get_hasAlpha)(C(ColorPicker) c);

extern C(Property) * PROPERTY(CreateDirectoryDialog, currentDirectory);
extern void (* CreateDirectoryDialog_set_currentDirectory)(C(CreateDirectoryDialog) c, const char * value);
extern const char * (* CreateDirectoryDialog_get_currentDirectory)(C(CreateDirectoryDialog) c);

extern C(Property) * PROPERTY(FileDialog, type);
extern void (* FileDialog_set_type)(C(FileDialog) f, C(FileDialogType) value);
extern C(FileDialogType) (* FileDialog_get_type)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, filePath);
extern void (* FileDialog_set_filePath)(C(FileDialog) f, const char * value);
extern const char * (* FileDialog_get_filePath)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, currentDirectory);
extern void (* FileDialog_set_currentDirectory)(C(FileDialog) f, const char * value);
extern const char * (* FileDialog_get_currentDirectory)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, filters);
extern void (* FileDialog_set_filters)(C(FileDialog) f, C(FileFilter) * value);
extern C(FileFilter) * (* FileDialog_get_filters)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, types);
extern void (* FileDialog_set_types)(C(FileDialog) f, C(FileType) * value);
extern C(FileType) * (* FileDialog_get_types)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, sizeFilters);
extern void (* FileDialog_set_sizeFilters)(C(FileDialog) f, int value);
extern int (* FileDialog_get_sizeFilters)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, sizeTypes);
extern void (* FileDialog_set_sizeTypes)(C(FileDialog) f, int value);
extern int (* FileDialog_get_sizeTypes)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, filter);
extern void (* FileDialog_set_filter)(C(FileDialog) f, int value);
extern int (* FileDialog_get_filter)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, fileType);
extern void (* FileDialog_set_fileType)(C(FileDialog) f, int value);
extern int (* FileDialog_get_fileType)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, mayNotExist);
extern void (* FileDialog_set_mayNotExist)(C(FileDialog) f, C(bool) value);
extern C(bool) (* FileDialog_get_mayNotExist)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, numSelections);
extern int (* FileDialog_get_numSelections)(C(FileDialog) f);

extern C(Property) * PROPERTY(FileDialog, multiFilePaths);
extern const char ** (* FileDialog_get_multiFilePaths)(C(FileDialog) f);

struct C(FileFilter)
{
   const char * name;
   const char * extensions;
};
extern C(bool) (* FileFilter_validateFileName)(C(FileFilter) * __this, const char * name);

struct C(FileName)
{
   const char * name;
   C(FileNameType) type;
   int indent;
};
extern C(FileNameType) (* FileNameType_selectByExtension)(const char * extension);

extern C(Property) * PROPERTY(FileNameType, isFolderType);
extern C(bool) (* FileNameType_get_isFolderType)(C(FileNameType) f);

extern C(Property) * PROPERTY(FileNameType, isFileType);
extern C(bool) (* FileNameType_get_isFileType)(C(FileNameType) f);

struct C(FileType)
{
   const char * name;
   const char * typeExtension;
   C(FileForceExtension) forceExtension;
};
extern C(Property) * PROPERTY(FindDialog, editBox);
extern void (* FindDialog_set_editBox)(C(FindDialog) f, C(EditBox) value);

extern C(Property) * PROPERTY(FindDialog, searchString);
extern void (* FindDialog_set_searchString)(C(FindDialog) f, const char * value);
extern const char * (* FindDialog_get_searchString)(C(FindDialog) f);

extern C(Property) * PROPERTY(FindDialog, wholeWord);
extern void (* FindDialog_set_wholeWord)(C(FindDialog) f, C(bool) value);
extern C(bool) (* FindDialog_get_wholeWord)(C(FindDialog) f);

extern C(Property) * PROPERTY(FindDialog, matchCase);
extern void (* FindDialog_set_matchCase)(C(FindDialog) f, C(bool) value);
extern C(bool) (* FindDialog_get_matchCase)(C(FindDialog) f);

extern C(Property) * PROPERTY(FindDialog, searchUp);
extern void (* FindDialog_set_searchUp)(C(FindDialog) f, C(bool) value);
extern C(bool) (* FindDialog_get_searchUp)(C(FindDialog) f);

extern C(Property) * PROPERTY(GoToDialog, line);
extern void (* GoToDialog_set_line)(C(GoToDialog) g, int value);
extern int (* GoToDialog_get_line)(C(GoToDialog) g);

extern C(Property) * PROPERTY(GoToDialog, editBox);
extern void (* GoToDialog_set_editBox)(C(GoToDialog) g, C(EditBox) value);
extern C(EditBox) (* GoToDialog_get_editBox)(C(GoToDialog) g);

extern C(Property) * PROPERTY(MessageBox, type);
extern void (* MessageBox_set_type)(C(MessageBox) m, C(MessageBoxType) value);

extern C(Property) * PROPERTY(MessageBox, contents);
extern void (* MessageBox_set_contents)(C(MessageBox) m, const char * value);

extern C(Property) * PROPERTY(ReplaceDialog, editBox);
extern void (* ReplaceDialog_set_editBox)(C(ReplaceDialog) r, C(EditBox) value);

extern C(Property) * PROPERTY(ReplaceDialog, searchString);
extern void (* ReplaceDialog_set_searchString)(C(ReplaceDialog) r, const char * value);
extern const char * (* ReplaceDialog_get_searchString)(C(ReplaceDialog) r);

extern C(Property) * PROPERTY(ReplaceDialog, replaceString);
extern void (* ReplaceDialog_set_replaceString)(C(ReplaceDialog) r, const char * value);
extern const char * (* ReplaceDialog_get_replaceString)(C(ReplaceDialog) r);

extern C(Property) * PROPERTY(ReplaceDialog, wholeWord);
extern void (* ReplaceDialog_set_wholeWord)(C(ReplaceDialog) r, C(bool) value);
extern C(bool) (* ReplaceDialog_get_wholeWord)(C(ReplaceDialog) r);

extern C(Property) * PROPERTY(ReplaceDialog, matchCase);
extern void (* ReplaceDialog_set_matchCase)(C(ReplaceDialog) r, C(bool) value);
extern C(bool) (* ReplaceDialog_get_matchCase)(C(ReplaceDialog) r);


// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||gui||controls  //////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
typedef C(Instance) C(UndoBuffer);
typedef struct C(UndoAction) C(UndoAction);
#if CPP11
enum C(TabsPlacement) : int
#else
typedef int C(TabsPlacement);
enum C(TabsPlacement)
#endif
{
   TabsPlacement_top = 0x0,
   TabsPlacement_bottom = 0x1,
   TabsPlacement_left = 0x2,
   TabsPlacement_right = 0x3
};

typedef C(Window) C(TabControl);
typedef C(Window) C(Tab);
struct CM(SyntaxColorScheme)
{
   C(Color) commentColor;
   C(Color) charLiteralColor;
   C(Color) stringLiteralColor;
   C(Color) preprocessorColor;
   C(Color) numberColor;
};
typedef C(Instance) C(SyntaxColorScheme);
typedef C(Instance) C(StatusField);
typedef C(Window) C(StatusBar);
typedef C(Window) C(Stacker);
struct CM(SelectorButton)
{
   C(Window) focusHolder;
};
typedef C(Button) C(SelectorButton);
typedef C(Stacker) C(SelectorBar);
#if CPP11
enum C(ScrollDirection) : int
#else
typedef int C(ScrollDirection);
enum C(ScrollDirection)
#endif
{
   ScrollDirection_horizontal = 0x0,
   ScrollDirection_vertical = 0x1
};

#if CPP11
enum C(ScrollBarAction) : int
#else
typedef int C(ScrollBarAction);
enum C(ScrollBarAction)
#endif
{
   ScrollBarAction_none = 0x0,
   ScrollBarAction_up = 0x1,
   ScrollBarAction_down = 0x2,
   ScrollBarAction_pageDown = 0x3,
   ScrollBarAction_pageUp = 0x4,
   ScrollBarAction_setPosition = 0x5,
   ScrollBarAction_home = 0x6,
   ScrollBarAction_end = 0x7,
   ScrollBarAction_setRange = 0x8,
   ScrollBarAction_wheelUp = 0x9,
   ScrollBarAction_wheelDown = 0xA
};

typedef C(CommonControl) C(ScrollBar);
#if CPP11
enum C(PathTypeExpected) : int
#else
typedef int C(PathTypeExpected);
enum C(PathTypeExpected)
#endif
{
   PathTypeExpected_none = 0x0,
   PathTypeExpected_any = 0x1,
   PathTypeExpected_directory = 0x2,
   PathTypeExpected_file = 0x3
};

typedef C(CommonControl) C(PathBox);
typedef C(Window) C(PaneSplitter);
typedef C(Instance) C(MenuItem);
typedef C(Instance) C(Menu);
struct CM(ListBox)
{
   byte __ecerePrivateData0[128];
   double typingTimeOut;
};
typedef C(CommonControl) C(ListBox);
typedef C(String) C(FilePath);
typedef C(SelectorButton) C(EditableSelectorButton);
typedef struct C(EditLine) C(EditLine);
typedef C(File) C(EditBoxStream);
#if CPP11
enum C(EditBoxFindResult) : int
#else
typedef int C(EditBoxFindResult);
enum C(EditBoxFindResult)
#endif
{
   EditBoxFindResult_notFound = 0x0,
   EditBoxFindResult_found = 0x1,
   EditBoxFindResult_wrapped = 0x2
};

typedef C(CommonControl) C(DropBox);
typedef C(CommonControl) C(DirectoriesBox);
typedef C(Instance) C(DataRow);
typedef C(Instance) C(DataField);
typedef C(CommonControl) C(DataBox);
typedef C(CommonControl) C(CalendarControl);
#if CPP11
enum C(ButtonState) : int
#else
typedef int C(ButtonState);
enum C(ButtonState)
#endif
{
   ButtonState_up = 0x0,
   ButtonState_down = 0x1,
   ButtonState_over = 0x2,
   ButtonState_disabled = 0x3,
   ButtonState_upChecked = 0x4,
   ButtonState_downChecked = 0x5,
   ButtonState_overChecked = 0x6,
   ButtonState_disabledChecked = 0x7
};

typedef struct C(BufferLocation) C(BufferLocation);
#if CPP11
enum C(BoxAlignment) : int
#else
typedef int C(BoxAlignment);
enum C(BoxAlignment)
#endif
{
   BoxAlignment_center = 0x0,
   BoxAlignment_left = 0x1,
   BoxAlignment_right = 0x2,
   BoxAlignment_top = 0x3,
   BoxAlignment_bottom = 0x4
};

typedef float C(Percentage);
typedef uint32 C(Modifiers);
typedef uint32 C(Key);
// end -- moved backwards outputs
typedef uint32 C(DataDisplayFlags);
typedef C(FilePath) C(DirPath);
typedef C(CommonControl) C(Label);
typedef C(MenuItem) C(MenuDivider);
typedef C(MenuItem) C(MenuPlacement);
typedef C(Instance) C(OldArray);
typedef C(CommonControl) C(Picture);
typedef C(Window) C(PopupMenu);
typedef C(CommonControl) C(ProgressBar);
typedef C(DataBox) C(SavingDataBox);
typedef C(Stacker) C(ToolBar);
typedef C(Button) C(ToolButton);
typedef C(Window) C(ToolSeparator);
typedef C(Window) C(ToolTip);
struct C(BufferLocation)
{
   C(EditLine) * line;
   int y;
   int x;
};
extern void (* BufferLocation_adjustAdd)(C(BufferLocation) * __this, C(BufferLocation) * start, C(BufferLocation) * end);

extern void (* BufferLocation_adjustDelete)(C(BufferLocation) * __this, C(BufferLocation) * start, C(BufferLocation) * end);

extern int M_VTBLID(Button, notifyClicked);
#define Button_notifyClicked(__i, __t, button, x, y, mods) \
   VMETHOD(CO(Button), Button, notifyClicked, __i, C(bool), \
      C(Window) _ARG C(Button) _ARG int _ARG int _ARG C(Modifiers), \
      __t _ARG button _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Button, notifyClicked);
extern int M_VTBLID(Button, notifyDoubleClick);
#define Button_notifyDoubleClick(__i, __t, button, x, y, mods) \
   VMETHOD(CO(Button), Button, notifyDoubleClick, __i, C(bool), \
      C(Window) _ARG C(Button) _ARG int _ARG int _ARG C(Modifiers), \
      __t _ARG button _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Button, notifyDoubleClick);
extern int M_VTBLID(Button, notifyMouseLeave);
#define Button_notifyMouseLeave(__i, __t, button, mods) \
   VMETHOD(CO(Button), Button, notifyMouseLeave, __i, C(bool), \
      C(Window) _ARG C(Button) _ARG C(Modifiers), \
      __t _ARG button _ARG mods)
extern C(Method) * METHOD(Button, notifyMouseLeave);
extern int M_VTBLID(Button, notifyMouseMove);
#define Button_notifyMouseMove(__i, __t, button, x, y, mods) \
   VMETHOD(CO(Button), Button, notifyMouseMove, __i, C(bool), \
      C(Window) _ARG C(Button) _ARG int _ARG int _ARG C(Modifiers), \
      __t _ARG button _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Button, notifyMouseMove);
extern int M_VTBLID(Button, notifyMouseOver);
#define Button_notifyMouseOver(__i, __t, button, x, y, mods) \
   VMETHOD(CO(Button), Button, notifyMouseOver, __i, C(bool), \
      C(Window) _ARG C(Button) _ARG int _ARG int _ARG C(Modifiers), \
      __t _ARG button _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Button, notifyMouseOver);
extern int M_VTBLID(Button, notifyPushed);
#define Button_notifyPushed(__i, __t, button, x, y, mods) \
   VMETHOD(CO(Button), Button, notifyPushed, __i, C(bool), \
      C(Window) _ARG C(Button) _ARG int _ARG int _ARG C(Modifiers), \
      __t _ARG button _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Button, notifyPushed);
extern int M_VTBLID(Button, notifyReleased);
#define Button_notifyReleased(__i, __t, button, x, y, mods) \
   VMETHOD(CO(Button), Button, notifyReleased, __i, C(bool), \
      C(Window) _ARG C(Button) _ARG int _ARG int _ARG C(Modifiers), \
      __t _ARG button _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Button, notifyReleased);
extern void (* Button_removeRadio)(C(Button) __this);

extern void (* Button_setColor)(C(Button) __this, C(ButtonState) state, C(Color) value);

extern void (* Button_setTextColor)(C(Button) __this, C(ButtonState) state, C(Color) value);

extern C(Property) * PROPERTY(Button, opacity);
extern void (* Button_set_opacity)(C(Button) b, C(Percentage) value);
extern C(Percentage) (* Button_get_opacity)(C(Button) b);
extern bool (* Button_isSet_opacity)(C(Button) b);

extern C(Property) * PROPERTY(Button, drawBehind);
extern void (* Button_set_drawBehind)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_drawBehind)(C(Button) b);
extern bool (* Button_isSet_drawBehind)(C(Button) b);

extern C(Property) * PROPERTY(Button, isRadio);
extern void (* Button_set_isRadio)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_isRadio)(C(Button) b);

extern C(Property) * PROPERTY(Button, isCheckbox);
extern void (* Button_set_isCheckbox)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_isCheckbox)(C(Button) b);

extern C(Property) * PROPERTY(Button, bevel);
extern void (* Button_set_bevel)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_bevel)(C(Button) b);

extern C(Property) * PROPERTY(Button, bevelOver);
extern void (* Button_set_bevelOver)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_bevelOver)(C(Button) b);

extern C(Property) * PROPERTY(Button, toggle);
extern void (* Button_set_toggle)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_toggle)(C(Button) b);

extern C(Property) * PROPERTY(Button, checked);
extern void (* Button_set_checked)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_checked)(C(Button) b);

extern C(Property) * PROPERTY(Button, alignment);
extern void (* Button_set_alignment)(C(Button) b, C(Alignment) value);
extern C(Alignment) (* Button_get_alignment)(C(Button) b);

extern C(Property) * PROPERTY(Button, bitmap);
extern void (* Button_set_bitmap)(C(Button) b, C(BitmapResource) value);
extern C(BitmapResource) (* Button_get_bitmap)(C(Button) b);

extern C(Property) * PROPERTY(Button, stayUp);
extern void (* Button_set_stayUp)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_stayUp)(C(Button) b);

extern C(Property) * PROPERTY(Button, scaleBitmap);
extern void (* Button_set_scaleBitmap)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_scaleBitmap)(C(Button) b);

extern C(Property) * PROPERTY(Button, keyRepeat);
extern void (* Button_set_keyRepeat)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_keyRepeat)(C(Button) b);

extern C(Property) * PROPERTY(Button, symbol);
extern void (* Button_set_symbol)(C(Button) b, unichar value);
extern unichar (* Button_get_symbol)(C(Button) b);

extern C(Property) * PROPERTY(Button, ellipsis);
extern void (* Button_set_ellipsis)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_ellipsis)(C(Button) b);

extern C(Property) * PROPERTY(Button, stayDown);
extern void (* Button_set_stayDown)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_stayDown)(C(Button) b);

extern C(Property) * PROPERTY(Button, offset);
extern void (* Button_set_offset)(C(Button) b, C(bool) value);
extern C(bool) (* Button_get_offset)(C(Button) b);

extern C(Property) * PROPERTY(Button, buttonState);
extern void (* Button_set_buttonState)(C(Button) b, C(ButtonState) value);
extern C(ButtonState) (* Button_get_buttonState)(C(Button) b);

extern C(Property) * PROPERTY(Button, bitmapAlignment);
extern void (* Button_set_bitmapAlignment)(C(Button) b, C(BoxAlignment) value);
extern C(BoxAlignment) (* Button_get_bitmapAlignment)(C(Button) b);

struct CM(CalendarControl)
{
   C(Date) dateValue;
   C(Month) shownMonth;
   int shownYear;
};
extern int M_VTBLID(CalendarControl, notifyChanged);
#define CalendarControl_notifyChanged(__i, __t, calendarControl, close) \
   VMETHOD(CO(CalendarControl), CalendarControl, notifyChanged, __i, void, \
      C(Window) _ARG C(CalendarControl) _ARG C(bool), \
      __t _ARG calendarControl _ARG close)
extern C(Method) * METHOD(CalendarControl, notifyChanged);
struct CM(DataBox)
{
   C(Class) * type;
   void * data;
   void * fieldData;
   C(Window) editor;
   C(bool) readOnly;
   C(bool) keepEditor;
   C(bool) autoSize;
   C(bool) needUpdate;
   C(String) stringValue;
};
extern void (* DataBox_modified)(C(DataBox) __this);

extern int M_VTBLID(DataBox, notifyChanged);
#define DataBox_notifyChanged(__i, __t, dataBox, closingDropDown) \
   VMETHOD(CO(DataBox), DataBox, notifyChanged, __i, C(bool), \
      C(Window) _ARG C(DataBox) _ARG C(bool), \
      __t _ARG dataBox _ARG closingDropDown)
extern C(Method) * METHOD(DataBox, notifyChanged);
extern int M_VTBLID(DataBox, notifyModified);
#define DataBox_notifyModified(__i, __t) \
   VMETHOD(CO(DataBox), DataBox, notifyModified, __i, C(bool), \
      C(Window), \
      __t)
extern C(Method) * METHOD(DataBox, notifyModified);
extern int M_VTBLID(DataBox, onConfigure);
#define DataBox_onConfigure(__i, editor) \
   VMETHOD(CO(DataBox), DataBox, onConfigure, __i, void, \
      C(DataBox) _ARG C(Window), \
      __i _ARG editor)
extern C(Method) * METHOD(DataBox, onConfigure);
extern void (* DataBox_refresh)(C(DataBox) __this);

extern C(bool) (* DataBox_saveData)(C(DataBox) __this);

extern int M_VTBLID(DataBox, setData);
#define DataBox_setData(__i, newData, closingDropDown) \
   VMETHOD(CO(DataBox), DataBox, setData, __i, void, \
      C(DataBox) _ARG any_object _ARG C(bool), \
      __i _ARG newData _ARG closingDropDown)
extern C(Method) * METHOD(DataBox, setData);
#define DATADISPLAYFLAGS_selected_SHIFT                  0
#define DATADISPLAYFLAGS_selected_MASK                   0x1
#define DATADISPLAYFLAGS_selected(x)                     ((((DataDisplayFlags)(x)) & DATADISPLAYFLAGS_selected_MASK) >> DATADISPLAYFLAGS_selected_SHIFT)
#define DATADISPLAYFLAGS_SET_selected(x, selected)              (x) = ((DataDisplayFlags)(x) & ~((DataDisplayFlags)DATADISPLAYFLAGS_selected_MASK)) | (((DataDisplayFlags)(selected)) << DATADISPLAYFLAGS_selected_SHIFT)
#define DATADISPLAYFLAGS_fullRow_SHIFT                   1
#define DATADISPLAYFLAGS_fullRow_MASK                    0x2
#define DATADISPLAYFLAGS_fullRow(x)                      ((((DataDisplayFlags)(x)) & DATADISPLAYFLAGS_fullRow_MASK) >> DATADISPLAYFLAGS_fullRow_SHIFT)
#define DATADISPLAYFLAGS_SET_fullRow(x, fullRow)               (x) = ((DataDisplayFlags)(x) & ~((DataDisplayFlags)DATADISPLAYFLAGS_fullRow_MASK)) | (((DataDisplayFlags)(fullRow)) << DATADISPLAYFLAGS_fullRow_SHIFT)
#define DATADISPLAYFLAGS_current_SHIFT                   2
#define DATADISPLAYFLAGS_current_MASK                    0x4
#define DATADISPLAYFLAGS_current(x)                      ((((DataDisplayFlags)(x)) & DATADISPLAYFLAGS_current_MASK) >> DATADISPLAYFLAGS_current_SHIFT)
#define DATADISPLAYFLAGS_SET_current(x, current)               (x) = ((DataDisplayFlags)(x) & ~((DataDisplayFlags)DATADISPLAYFLAGS_current_MASK)) | (((DataDisplayFlags)(current)) << DATADISPLAYFLAGS_current_SHIFT)
#define DATADISPLAYFLAGS_active_SHIFT                    3
#define DATADISPLAYFLAGS_active_MASK                     0x8
#define DATADISPLAYFLAGS_active(x)                       ((((DataDisplayFlags)(x)) & DATADISPLAYFLAGS_active_MASK) >> DATADISPLAYFLAGS_active_SHIFT)
#define DATADISPLAYFLAGS_SET_active(x, active)                (x) = ((DataDisplayFlags)(x) & ~((DataDisplayFlags)DATADISPLAYFLAGS_active_MASK)) | (((DataDisplayFlags)(active)) << DATADISPLAYFLAGS_active_SHIFT)
#define DATADISPLAYFLAGS_dropBox_SHIFT                   4
#define DATADISPLAYFLAGS_dropBox_MASK                    0x10
#define DATADISPLAYFLAGS_dropBox(x)                      ((((DataDisplayFlags)(x)) & DATADISPLAYFLAGS_dropBox_MASK) >> DATADISPLAYFLAGS_dropBox_SHIFT)
#define DATADISPLAYFLAGS_SET_dropBox(x, dropBox)               (x) = ((DataDisplayFlags)(x) & ~((DataDisplayFlags)DATADISPLAYFLAGS_dropBox_MASK)) | (((DataDisplayFlags)(dropBox)) << DATADISPLAYFLAGS_dropBox_SHIFT)
#define DATADISPLAYFLAGS_header_SHIFT                    5
#define DATADISPLAYFLAGS_header_MASK                     0x20
#define DATADISPLAYFLAGS_header(x)                       ((((DataDisplayFlags)(x)) & DATADISPLAYFLAGS_header_MASK) >> DATADISPLAYFLAGS_header_SHIFT)
#define DATADISPLAYFLAGS_SET_header(x, header)                (x) = ((DataDisplayFlags)(x) & ~((DataDisplayFlags)DATADISPLAYFLAGS_header_MASK)) | (((DataDisplayFlags)(header)) << DATADISPLAYFLAGS_header_SHIFT)
#define DATADISPLAYFLAGS_firstField_SHIFT                6
#define DATADISPLAYFLAGS_firstField_MASK                 0x40
#define DATADISPLAYFLAGS_firstField(x)                   ((((DataDisplayFlags)(x)) & DATADISPLAYFLAGS_firstField_MASK) >> DATADISPLAYFLAGS_firstField_SHIFT)
#define DATADISPLAYFLAGS_SET_firstField(x, firstField)            (x) = ((DataDisplayFlags)(x) & ~((DataDisplayFlags)DATADISPLAYFLAGS_firstField_MASK)) | (((DataDisplayFlags)(firstField)) << DATADISPLAYFLAGS_firstField_SHIFT)


extern void (* DataField_autoSize)(C(DataField) __this);

extern void (* DataField_move)(C(DataField) __this, C(DataField) after);

extern C(Property) * PROPERTY(DataField, dataType);
extern void (* DataField_set_dataType)(C(DataField) d, C(Class) * value);
extern C(Class) * (* DataField_get_dataType)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, editable);
extern void (* DataField_set_editable)(C(DataField) d, C(bool) value);

extern C(Property) * PROPERTY(DataField, fixed);
extern void (* DataField_set_fixed)(C(DataField) d, C(bool) value);
extern C(bool) (* DataField_get_fixed)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, alignment);
extern void (* DataField_set_alignment)(C(DataField) d, C(Alignment) value);
extern C(Alignment) (* DataField_get_alignment)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, width);
extern void (* DataField_set_width)(C(DataField) d, int value);
extern int (* DataField_get_width)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, index);
extern int (* DataField_get_index)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, position);
extern void (* DataField_set_position)(C(DataField) d, int value);
extern int (* DataField_get_position)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, sortOrder);
extern int (* DataField_get_sortOrder)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, header);
extern void (* DataField_set_header)(C(DataField) d, const char * value);

extern C(Property) * PROPERTY(DataField, userData);
extern void (* DataField_set_userData)(C(DataField) d, void * value);
extern void * (* DataField_get_userData)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, freeData);
extern void (* DataField_set_freeData)(C(DataField) d, C(bool) value);
extern C(bool) (* DataField_get_freeData)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, prev);
extern C(DataField) (* DataField_get_prev)(C(DataField) d);

extern C(Property) * PROPERTY(DataField, next);
extern C(DataField) (* DataField_get_next)(C(DataField) d);

extern C(DataRow) (* DataRow_addRow)(C(DataRow) __this);

extern C(DataRow) (* DataRow_addRowAfter)(C(DataRow) __this, C(DataRow) after);

extern C(DataRow) (* DataRow_addString)(C(DataRow) __this, const char * string);

extern C(DataRow) (* DataRow_addStringf)(C(DataRow) __this, const char * format, ...);

extern void (* DataRow_edit)(C(DataRow) __this, C(DataField) field);

extern C(DataRow) (* DataRow_findRow)(C(DataRow) __this, int64 tag);

extern C(DataRow) (* DataRow_findSubRow)(C(DataRow) __this, int64 tag);

extern any_object (* DataRow_getData)(C(DataRow) __this, C(DataField) field);

extern C(DataRow) (* DataRow_getNextRow)(C(DataRow) __this);

extern C(DataRow) (* DataRow_getPrevRow)(C(DataRow) __this);

extern void (* DataRow_move)(C(DataRow) __this, C(DataRow) after);

extern void * (* DataRow_setData)(C(DataRow) __this, C(DataField) field, any_object newData);

extern void (* DataRow_sortSubRows)(C(DataRow) __this, C(bool) scrollToCurrent);

extern void (* DataRow_unsetData)(C(DataRow) __this, C(DataField) field);

extern C(Property) * PROPERTY(DataRow, tag);
extern void (* DataRow_set_tag)(C(DataRow) d, int64 value);
extern int64 (* DataRow_get_tag)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, previous);
extern C(DataRow) (* DataRow_get_previous)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, next);
extern C(DataRow) (* DataRow_get_next)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, index);
extern int (* DataRow_get_index)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, string);
extern void (* DataRow_set_string)(C(DataRow) d, const char * value);
extern const char * (* DataRow_get_string)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, isHeader);
extern void (* DataRow_set_isHeader)(C(DataRow) d, C(bool) value);
extern C(bool) (* DataRow_get_isHeader)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, icon);
extern void (* DataRow_set_icon)(C(DataRow) d, C(BitmapResource) value);
extern C(BitmapResource) (* DataRow_get_icon)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, collapsed);
extern void (* DataRow_set_collapsed)(C(DataRow) d, C(bool) value);
extern C(bool) (* DataRow_get_collapsed)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, selected);
extern void (* DataRow_set_selected)(C(DataRow) d, C(bool) value);
extern C(bool) (* DataRow_get_selected)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, parent);
extern void (* DataRow_set_parent)(C(DataRow) d, C(DataRow) value);
extern C(DataRow) (* DataRow_get_parent)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, lastRow);
extern C(DataRow) (* DataRow_get_lastRow)(C(DataRow) d);

extern C(Property) * PROPERTY(DataRow, firstRow);
extern C(DataRow) (* DataRow_get_firstRow)(C(DataRow) d);

struct CM(DirectoriesBox)
{
   byte __ecerePrivateData0[16];
   C(bool) browsing;
   C(Button) add;
   C(Button) remove;
   C(RepButton) up;
   C(RepButton) down;
   C(ListBox) list;
   C(DataField) dirField;
};
extern int M_VTBLID(DirectoriesBox, notifyModified);
#define DirectoriesBox_notifyModified(__i, __t, dirsBox) \
   VMETHOD(CO(DirectoriesBox), DirectoriesBox, notifyModified, __i, C(bool), \
      C(Window) _ARG C(DirectoriesBox), \
      __t _ARG dirsBox)
extern C(Method) * METHOD(DirectoriesBox, notifyModified);
extern int M_VTBLID(DirectoriesBox, notifyPathBoxModified);
#define DirectoriesBox_notifyPathBoxModified(__i, __t, dirsBox, pathBox) \
   VMETHOD(CO(DirectoriesBox), DirectoriesBox, notifyPathBoxModified, __i, C(bool), \
      C(Window) _ARG C(DirectoriesBox) _ARG C(PathBox), \
      __t _ARG dirsBox _ARG pathBox)
extern C(Method) * METHOD(DirectoriesBox, notifyPathBoxModified);
extern int M_VTBLID(DirectoriesBox, onBrowsedDir);
#define DirectoriesBox_onBrowsedDir(__i, directory) \
   VMETHOD(CO(DirectoriesBox), DirectoriesBox, onBrowsedDir, __i, C(bool), \
      C(DirectoriesBox) _ARG char **, \
      __i _ARG directory)
extern C(Method) * METHOD(DirectoriesBox, onBrowsedDir);
extern int M_VTBLID(DirectoriesBox, onChangedDir);
#define DirectoriesBox_onChangedDir(__i, directory) \
   VMETHOD(CO(DirectoriesBox), DirectoriesBox, onChangedDir, __i, C(bool), \
      C(DirectoriesBox) _ARG char **, \
      __i _ARG directory)
extern C(Method) * METHOD(DirectoriesBox, onChangedDir);
extern int M_VTBLID(DirectoriesBox, onPrepareBrowseDir);
#define DirectoriesBox_onPrepareBrowseDir(__i, directory) \
   VMETHOD(CO(DirectoriesBox), DirectoriesBox, onPrepareBrowseDir, __i, C(bool), \
      C(DirectoriesBox) _ARG char **, \
      __i _ARG directory)
extern C(Method) * METHOD(DirectoriesBox, onPrepareBrowseDir);
extern C(Property) * PROPERTY(DirectoriesBox, strings);
extern void (* DirectoriesBox_set_strings)(C(DirectoriesBox) d, C(Array) value);
extern C(Array) (* DirectoriesBox_get_strings)(C(DirectoriesBox) d);

extern C(Property) * PROPERTY(DirectoriesBox, browseDialog);
extern void (* DirectoriesBox_set_browseDialog)(C(DirectoriesBox) d, C(FileDialog) value);
extern C(FileDialog) (* DirectoriesBox_get_browseDialog)(C(DirectoriesBox) d);

extern C(Property) * PROPERTY(DirectoriesBox, baseBrowsePath);
extern void (* DirectoriesBox_set_baseBrowsePath)(C(DirectoriesBox) d, C(String) value);
extern C(String) (* DirectoriesBox_get_baseBrowsePath)(C(DirectoriesBox) d);

struct CM(DropBox)
{
   C(Button) button;
};
extern void (* DropBox_addField)(C(DropBox) __this, C(DataField) field);

extern C(DataRow) (* DropBox_addRow)(C(DropBox) __this);

extern C(DataRow) (* DropBox_addRowAfter)(C(DropBox) __this, C(DataRow) after);

extern C(DataRow) (* DropBox_addString)(C(DropBox) __this, const char * string);

extern C(DataRow) (* DropBox_addStringf)(C(DropBox) __this, const char * format, ...);

extern void (* DropBox_clear)(C(DropBox) __this);

extern void (* DropBox_deleteRow)(C(DropBox) __this, C(DataRow) row);

extern C(DataRow) (* DropBox_findRow)(C(DropBox) __this, int64 tag);

extern C(DataRow) (* DropBox_findSubRow)(C(DropBox) __this, int64 tag);

extern any_object (* DropBox_getData)(C(DropBox) __this, C(DataField) field);

extern int (* DropBox_getRowCount)(C(DropBox) __this);

extern int64 (* DropBox_getTag)(C(DropBox) __this);

extern int M_VTBLID(DropBox, notifyClose);
#define DropBox_notifyClose(__i, __t, dropBox) \
   VMETHOD(CO(DropBox), DropBox, notifyClose, __i, C(bool), \
      C(Window) _ARG C(DropBox), \
      __t _ARG dropBox)
extern C(Method) * METHOD(DropBox, notifyClose);
extern int M_VTBLID(DropBox, notifyHighlight);
#define DropBox_notifyHighlight(__i, __t, dropBox, row, mods) \
   VMETHOD(CO(DropBox), DropBox, notifyHighlight, __i, C(bool), \
      C(Window) _ARG C(DropBox) _ARG C(DataRow) _ARG C(Modifiers), \
      __t _ARG dropBox _ARG row _ARG mods)
extern C(Method) * METHOD(DropBox, notifyHighlight);
extern int M_VTBLID(DropBox, notifySelect);
#define DropBox_notifySelect(__i, __t, dropBox, row, mods) \
   VMETHOD(CO(DropBox), DropBox, notifySelect, __i, C(bool), \
      C(Window) _ARG C(DropBox) _ARG C(DataRow) _ARG C(Modifiers), \
      __t _ARG dropBox _ARG row _ARG mods)
extern C(Method) * METHOD(DropBox, notifySelect);
extern int M_VTBLID(DropBox, notifyTextEntry);
#define DropBox_notifyTextEntry(__i, __t, dropBox, string, confirmed) \
   VMETHOD(CO(DropBox), DropBox, notifyTextEntry, __i, C(bool), \
      C(Window) _ARG C(DropBox) _ARG const char * _ARG C(bool), \
      __t _ARG dropBox _ARG string _ARG confirmed)
extern C(Method) * METHOD(DropBox, notifyTextEntry);
extern int M_VTBLID(DropBox, onCloseDropDown);
#define DropBox_onCloseDropDown(__i, pullDown) \
   VMETHOD(CO(DropBox), DropBox, onCloseDropDown, __i, void, \
      C(DropBox) _ARG C(Window), \
      __i _ARG pullDown)
extern C(Method) * METHOD(DropBox, onCloseDropDown);
extern int M_VTBLID(DropBox, onDropDown);
#define DropBox_onDropDown(__i) \
   VMETHOD(CO(DropBox), DropBox, onDropDown, __i, C(Window), \
      C(DropBox), \
      __i)
extern C(Method) * METHOD(DropBox, onDropDown);
extern C(bool) (* DropBox_save)(C(DropBox) __this);

extern void (* DropBox_selectRow)(C(DropBox) __this, C(DataRow) row);

extern void * (* DropBox_setData)(C(DropBox) __this, C(DataField) field, any_object data);

extern void (* DropBox_sort)(C(DropBox) __this, C(DataField) field, int order);

extern C(Property) * PROPERTY(DropBox, activeStipple);
extern void (* DropBox_set_activeStipple)(C(DropBox) d, C(bool) value);
extern C(bool) (* DropBox_get_activeStipple)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, showButton);
extern void (* DropBox_set_showButton)(C(DropBox) d, C(bool) value);
extern C(bool) (* DropBox_get_showButton)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, alignment);
extern void (* DropBox_set_alignment)(C(DropBox) d, C(Alignment) value);
extern C(Alignment) (* DropBox_get_alignment)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, noHighlight);
extern void (* DropBox_set_noHighlight)(C(DropBox) d, C(bool) value);
extern C(bool) (* DropBox_get_noHighlight)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, activeColor);
extern void (* DropBox_set_activeColor)(C(DropBox) d, C(bool) value);
extern C(bool) (* DropBox_get_activeColor)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, currentRow);
extern void (* DropBox_set_currentRow)(C(DropBox) d, C(DataRow) value);
extern C(DataRow) (* DropBox_get_currentRow)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, firstRow);
extern C(DataRow) (* DropBox_get_firstRow)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, lastRow);
extern C(DataRow) (* DropBox_get_lastRow)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, contents);
extern void (* DropBox_set_contents)(C(DropBox) d, const char * value);
extern const char * (* DropBox_get_contents)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, editText);
extern void (* DropBox_set_editText)(C(DropBox) d, C(bool) value);
extern C(bool) (* DropBox_get_editText)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, editBox);
extern C(EditBox) (* DropBox_get_editBox)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, typingTimeout);
extern void (* DropBox_set_typingTimeout)(C(DropBox) d, C(Time) value);
extern C(Time) (* DropBox_get_typingTimeout)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, rowHeight);
extern void (* DropBox_set_rowHeight)(C(DropBox) d, int value);
extern int (* DropBox_get_rowHeight)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, maxShown);
extern void (* DropBox_set_maxShown)(C(DropBox) d, int value);
extern int (* DropBox_get_maxShown)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, pullDown);
extern C(Window) (* DropBox_get_pullDown)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, showNone);
extern void (* DropBox_set_showNone)(C(DropBox) d, C(bool) value);
extern C(bool) (* DropBox_get_showNone)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, selectionColor);
extern void (* DropBox_set_selectionColor)(C(DropBox) d, C(Color) value);
extern C(Color) (* DropBox_get_selectionColor)(C(DropBox) d);
extern bool (* DropBox_isSet_selectionColor)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, selectionText);
extern void (* DropBox_set_selectionText)(C(DropBox) d, C(Color) value);
extern C(Color) (* DropBox_get_selectionText)(C(DropBox) d);
extern bool (* DropBox_isSet_selectionText)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, changeContents);
extern void (* DropBox_set_changeContents)(C(DropBox) d, C(bool) value);
extern C(bool) (* DropBox_get_changeContents)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, listBox);
extern C(ListBox) (* DropBox_get_listBox)(C(DropBox) d);

extern C(Property) * PROPERTY(DropBox, rowCount);
extern int (* DropBox_get_rowCount)(C(DropBox) d);

extern C(bool) (* EditBox_addCh)(C(EditBox) __this, unichar ch);

extern C(bool) (* EditBox_addS)(C(EditBox) __this, const char * string);

extern void (* EditBox_backSpace)(C(EditBox) __this);

extern void (* EditBox_centerOnCursor)(C(EditBox) __this);

extern void (* EditBox_clear)(C(EditBox) __this);

extern void (* EditBox_clearLine)(C(EditBox) __this);

extern void (* EditBox_copy)(C(EditBox) __this);

extern void (* EditBox_cut)(C(EditBox) __this);

extern void (* EditBox_delete)(C(EditBox) __this, C(EditLine) * line1, int y1, int x1, C(EditLine) * line2, int y2, int x2);

extern void (* EditBox_deleteSelection)(C(EditBox) __this);

extern void (* EditBox_deselect)(C(EditBox) __this);

extern void (* EditBox_end)(C(EditBox) __this);

extern C(EditBoxFindResult) (* EditBox_find)(C(EditBox) __this, const char * text, C(bool) matchWord, C(bool) matchCase, C(bool) isSearchDown);

extern C(EditBoxFindResult) (* EditBox_findInSelection)(C(EditBox) __this, const char * text, C(bool) matchWord, C(bool) matchCase, C(EditLine) * l2, int y2, int x2);

extern void (* EditBox_getSel)(C(EditBox) __this, char * text, C(bool) addCr);

extern void (* EditBox_getSelPos)(C(EditBox) __this, C(EditLine) * l1, int * y1, int * x1, C(EditLine) * l2, int * y2, int * x2, C(bool) reorder);

extern int (* EditBox_getText)(C(EditBox) __this, char * text, C(EditLine) * _l1, int _y1, int _x1, C(EditLine) * _l2, int _y2, int _x2, C(bool) addCr, C(bool) addSpaces);

extern C(bool) (* EditBox_goToLineNum)(C(EditBox) __this, int lineNum);

extern C(bool) (* EditBox_goToPosition)(C(EditBox) __this, C(EditLine) * line, int y, int x);

extern void (* EditBox_home)(C(EditBox) __this);

extern void (* EditBox_lineDown)(C(EditBox) __this);

extern void (* EditBox_lineUp)(C(EditBox) __this);

extern void (* EditBox_load)(C(EditBox) __this, C(File) f);

extern void (* EditBox_modified)(C(EditBox) __this);

extern int M_VTBLID(EditBox, notifyCaretMove);
#define EditBox_notifyCaretMove(__i, __t, editBox, line, charPos) \
   VMETHOD(CO(EditBox), EditBox, notifyCaretMove, __i, void, \
      C(Window) _ARG C(EditBox) _ARG int _ARG int, \
      __t _ARG editBox _ARG line _ARG charPos)
extern C(Method) * METHOD(EditBox, notifyCaretMove);
extern int M_VTBLID(EditBox, notifyCharsAdded);
#define EditBox_notifyCharsAdded(__i, __t, editBox, before, after, pasteOperation) \
   VMETHOD(CO(EditBox), EditBox, notifyCharsAdded, __i, C(bool), \
      C(Window) _ARG C(EditBox) _ARG C(BufferLocation) * _ARG C(BufferLocation) * _ARG C(bool), \
      __t _ARG editBox _ARG before _ARG after _ARG pasteOperation)
extern C(Method) * METHOD(EditBox, notifyCharsAdded);
extern int M_VTBLID(EditBox, notifyCharsDeleted);
#define EditBox_notifyCharsDeleted(__i, __t, editBox, beforeLoc, after, pasteOperation) \
   VMETHOD(CO(EditBox), EditBox, notifyCharsDeleted, __i, C(bool), \
      C(Window) _ARG C(EditBox) _ARG C(BufferLocation) * _ARG C(BufferLocation) * _ARG C(bool), \
      __t _ARG editBox _ARG beforeLoc _ARG after _ARG pasteOperation)
extern C(Method) * METHOD(EditBox, notifyCharsDeleted);
extern int M_VTBLID(EditBox, notifyDoubleClick);
#define EditBox_notifyDoubleClick(__i, __t, editBox, line, mods) \
   VMETHOD(CO(EditBox), EditBox, notifyDoubleClick, __i, C(bool), \
      C(Window) _ARG C(EditBox) _ARG C(EditLine) * _ARG C(Modifiers), \
      __t _ARG editBox _ARG line _ARG mods)
extern C(Method) * METHOD(EditBox, notifyDoubleClick);
extern int M_VTBLID(EditBox, notifyDropped);
#define EditBox_notifyDropped(__i, __t, editBox, x, y) \
   VMETHOD(CO(EditBox), EditBox, notifyDropped, __i, C(bool), \
      C(Window) _ARG C(EditBox) _ARG int _ARG int, \
      __t _ARG editBox _ARG x _ARG y)
extern C(Method) * METHOD(EditBox, notifyDropped);
extern int M_VTBLID(EditBox, notifyKeyDown);
#define EditBox_notifyKeyDown(__i, __t, editBox, key, ch) \
   VMETHOD(CO(EditBox), EditBox, notifyKeyDown, __i, C(bool), \
      C(Window) _ARG C(EditBox) _ARG C(Key) _ARG unichar, \
      __t _ARG editBox _ARG key _ARG ch)
extern C(Method) * METHOD(EditBox, notifyKeyDown);
extern int M_VTBLID(EditBox, notifyModified);
#define EditBox_notifyModified(__i, __t, editBox) \
   VMETHOD(CO(EditBox), EditBox, notifyModified, __i, C(bool), \
      C(Window) _ARG C(EditBox), \
      __t _ARG editBox)
extern C(Method) * METHOD(EditBox, notifyModified);
extern int M_VTBLID(EditBox, notifyOvrToggle);
#define EditBox_notifyOvrToggle(__i, __t, editBox, overwrite) \
   VMETHOD(CO(EditBox), EditBox, notifyOvrToggle, __i, void, \
      C(Window) _ARG C(EditBox) _ARG C(bool), \
      __t _ARG editBox _ARG overwrite)
extern C(Method) * METHOD(EditBox, notifyOvrToggle);
extern int M_VTBLID(EditBox, notifyUnsetModified);
#define EditBox_notifyUnsetModified(__i, __t, editBox) \
   VMETHOD(CO(EditBox), EditBox, notifyUnsetModified, __i, C(bool), \
      C(Window) _ARG C(EditBox), \
      __t _ARG editBox)
extern C(Method) * METHOD(EditBox, notifyUnsetModified);
extern int M_VTBLID(EditBox, notifyUpdate);
#define EditBox_notifyUpdate(__i, __t, editBox) \
   VMETHOD(CO(EditBox), EditBox, notifyUpdate, __i, void, \
      C(Window) _ARG C(EditBox), \
      __t _ARG editBox)
extern C(Method) * METHOD(EditBox, notifyUpdate);
extern void (* EditBox_pageDown)(C(EditBox) __this);

extern void (* EditBox_pageUp)(C(EditBox) __this);

extern void (* EditBox_paste)(C(EditBox) __this);

extern void (* EditBox_printf)(C(EditBox) __this, const char * format, ...);

extern void (* EditBox_putCh)(C(EditBox) __this, unichar ch);

extern void (* EditBox_putS)(C(EditBox) __this, const char * string);

extern void (* EditBox_record)(C(EditBox) __this, C(UndoAction) * action);

extern void (* EditBox_redo)(C(EditBox) __this);

extern void (* EditBox_save)(C(EditBox) __this, C(File) f, C(bool) cr);

extern uint (* EditBox_selSize)(C(EditBox) __this);

extern void (* EditBox_select)(C(EditBox) __this, C(EditLine) * line1, int y1, int x1, C(EditLine) * line2, int y2, int x2);

extern void (* EditBox_selectAll)(C(EditBox) __this);

extern void (* EditBox_setContents)(C(EditBox) __this, const char * format, ...);

extern void (* EditBox_setCursorToView)(C(EditBox) __this);

extern void (* EditBox_setModified)(C(EditBox) __this, C(bool) flag);

extern void (* EditBox_setSelPos)(C(EditBox) __this, C(EditLine) * l1, int y1, int x1, C(EditLine) * l2, int y2, int x2);

extern void (* EditBox_setViewToCursor)(C(EditBox) __this, C(bool) setCaret);

extern void (* EditBox_undo)(C(EditBox) __this);

extern C(Property) * PROPERTY(EditBox, textHorzScroll);
extern void (* EditBox_set_textHorzScroll)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_textHorzScroll)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, textVertScroll);
extern void (* EditBox_set_textVertScroll)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_textVertScroll)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, readOnly);
extern void (* EditBox_set_readOnly)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_readOnly)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, multiLine);
extern void (* EditBox_set_multiLine)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_multiLine)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, freeCaret);
extern void (* EditBox_set_freeCaret)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_freeCaret)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, tabKey);
extern void (* EditBox_set_tabKey)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_tabKey)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, tabSize);
extern void (* EditBox_set_tabSize)(C(EditBox) e, int value);
extern int (* EditBox_get_tabSize)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, tabSelection);
extern void (* EditBox_set_tabSelection)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_tabSelection)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, smartHome);
extern void (* EditBox_set_smartHome)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_smartHome)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, autoEmpty);
extern void (* EditBox_set_autoEmpty)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_autoEmpty)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, noCaret);
extern void (* EditBox_set_noCaret)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_noCaret)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, maxLineSize);
extern void (* EditBox_set_maxLineSize)(C(EditBox) e, int value);
extern int (* EditBox_get_maxLineSize)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, maxNumLines);
extern void (* EditBox_set_maxNumLines)(C(EditBox) e, int value);
extern int (* EditBox_get_maxNumLines)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, useTab);
extern void (* EditBox_set_useTab)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_useTab)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, syntaxHighlighting);
extern void (* EditBox_set_syntaxHighlighting)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_syntaxHighlighting)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, noSelect);
extern void (* EditBox_set_noSelect)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_noSelect)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, allCaps);
extern void (* EditBox_set_allCaps)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_allCaps)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, autoSize);
extern void (* EditBox_set_autoSize)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_autoSize)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, wrap);
extern void (* EditBox_set_wrap)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_wrap)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, numLines);
extern int (* EditBox_get_numLines)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, lineNumber);
extern int (* EditBox_get_lineNumber)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, column);
extern int (* EditBox_get_column)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, charPos);
extern int (* EditBox_get_charPos)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, firstLine);
extern C(EditLine) * (* EditBox_get_firstLine)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, lastLine);
extern C(EditLine) * (* EditBox_get_lastLine)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, line);
extern C(EditLine) * (* EditBox_get_line)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, contents);
extern void (* EditBox_set_contents)(C(EditBox) e, const char * value);
extern const char * (* EditBox_get_contents)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, overwrite);
extern C(bool) (* EditBox_get_overwrite)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, caretFollowsScrolling);
extern void (* EditBox_set_caretFollowsScrolling)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_caretFollowsScrolling)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, multiLineContents);
extern char * (* EditBox_get_multiLineContents)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, selectionColor);
extern void (* EditBox_set_selectionColor)(C(EditBox) e, C(Color) value);
extern C(Color) (* EditBox_get_selectionColor)(C(EditBox) e);
extern bool (* EditBox_isSet_selectionColor)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, selectionText);
extern void (* EditBox_set_selectionText)(C(EditBox) e, C(Color) value);
extern C(Color) (* EditBox_get_selectionText)(C(EditBox) e);
extern bool (* EditBox_isSet_selectionText)(C(EditBox) e);

extern C(Property) * PROPERTY(EditBox, syntaxColorScheme);
extern void (* EditBox_set_syntaxColorScheme)(C(EditBox) e, C(SyntaxColorScheme) value);

extern C(Property) * PROPERTY(EditBox, recordUndoEvent);
extern void (* EditBox_set_recordUndoEvent)(C(EditBox) e, C(bool) value);
extern C(bool) (* EditBox_get_recordUndoEvent)(C(EditBox) e);

extern void (* EditBoxStream_deleteBytes)(C(EditBoxStream) __this, uint count);

extern C(Property) * PROPERTY(EditBoxStream, editBox);
extern void (* EditBoxStream_set_editBox)(C(EditBoxStream) e, C(EditBox) value);
extern C(EditBox) (* EditBoxStream_get_editBox)(C(EditBoxStream) e);

extern C(Property) * PROPERTY(EditLine, text);
extern void (* EditLine_set_text)(C(EditLine) * e, const char * value);
extern const char * (* EditLine_get_text)(C(EditLine) * e);

extern C(Property) * PROPERTY(EditLine, prev);
extern C(EditLine) * (* EditLine_get_prev)(C(EditLine) * e);

extern C(Property) * PROPERTY(EditLine, next);
extern C(EditLine) * (* EditLine_get_next)(C(EditLine) * e);

extern C(Property) * PROPERTY(EditLine, count);
extern int (* EditLine_get_count)(C(EditLine) * e);

extern int M_VTBLID(EditableSelectorButton, onRename);
#define EditableSelectorButton_onRename(__i, __t, button, oldName, newName) \
   VMETHOD(CO(EditableSelectorButton), EditableSelectorButton, onRename, __i, C(bool), \
      C(Window) _ARG C(EditableSelectorButton) _ARG char ** _ARG char **, \
      __t _ARG button _ARG oldName _ARG newName)
extern C(Method) * METHOD(EditableSelectorButton, onRename);
extern C(Property) * PROPERTY(EditableSelectorButton, renameable);
extern void (* EditableSelectorButton_set_renameable)(C(EditableSelectorButton) e, C(bool) value);
extern C(bool) (* EditableSelectorButton_get_renameable)(C(EditableSelectorButton) e);

extern C(Property) * PROPERTY(EditableSelectorButton, editBox);
extern C(EditBox) (* EditableSelectorButton_get_editBox)(C(EditableSelectorButton) e);

extern C(Property) * PROPERTY(Label, labeledWindow);
extern void (* Label_set_labeledWindow)(C(Label) l, C(Window) value);
extern C(Window) (* Label_get_labeledWindow)(C(Label) l);

extern C(Property) * PROPERTY(Label, isGroupBox);
extern void (* Label_set_isGroupBox)(C(Label) l, C(bool) value);
extern C(bool) (* Label_get_isGroupBox)(C(Label) l);

extern void (* ListBox_addField)(C(ListBox) __this, C(DataField) addedField);

extern C(DataRow) (* ListBox_addRow)(C(ListBox) __this);

extern C(DataRow) (* ListBox_addRowAfter)(C(ListBox) __this, C(DataRow) after);

extern C(DataRow) (* ListBox_addRowNone)(C(ListBox) __this);

extern C(DataRow) (* ListBox_addString)(C(ListBox) __this, const char * string);

extern C(DataRow) (* ListBox_addStringf)(C(ListBox) __this, const char * format, ...);

extern void (* ListBox_clear)(C(ListBox) __this);

extern void (* ListBox_clearFields)(C(ListBox) __this);

extern void (* ListBox_deleteRow)(C(ListBox) __this, C(DataRow) row);

extern C(DataRow) (* ListBox_findRow)(C(ListBox) __this, int64 tag);

extern C(DataRow) (* ListBox_findString)(C(ListBox) __this, const char * searchedString);

extern C(DataRow) (* ListBox_findSubRow)(C(ListBox) __this, int64 tag);

extern C(DataRow) (* ListBox_findSubString)(C(ListBox) __this, const char * subString);

extern C(DataRow) (* ListBox_findSubStringAfter)(C(ListBox) __this, C(DataRow) after, const char * subString);

extern C(DataRow) (* ListBox_findSubStringi)(C(ListBox) __this, const char * subString);

extern any_object (* ListBox_getData)(C(ListBox) __this, C(DataField) field);

extern void (* ListBox_getMultiSelection)(C(ListBox) __this, C(OldList) * list);

extern int64 (* ListBox_getTag)(C(ListBox) __this);

extern int M_VTBLID(ListBox, notifyChanged);
#define ListBox_notifyChanged(__i, __t, listBox, row) \
   VMETHOD(CO(ListBox), ListBox, notifyChanged, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow), \
      __t _ARG listBox _ARG row)
extern C(Method) * METHOD(ListBox, notifyChanged);
extern int M_VTBLID(ListBox, notifyCollapse);
#define ListBox_notifyCollapse(__i, __t, listBox, row, collapsed) \
   VMETHOD(CO(ListBox), ListBox, notifyCollapse, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow) _ARG C(bool), \
      __t _ARG listBox _ARG row _ARG collapsed)
extern C(Method) * METHOD(ListBox, notifyCollapse);
extern int M_VTBLID(ListBox, notifyDoubleClick);
#define ListBox_notifyDoubleClick(__i, __t, listBox, x, y, mods) \
   VMETHOD(CO(ListBox), ListBox, notifyDoubleClick, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG int _ARG int _ARG C(Modifiers), \
      __t _ARG listBox _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(ListBox, notifyDoubleClick);
extern int M_VTBLID(ListBox, notifyEditDone);
#define ListBox_notifyEditDone(__i, __t, listBox, row) \
   VMETHOD(CO(ListBox), ListBox, notifyEditDone, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow), \
      __t _ARG listBox _ARG row)
extern C(Method) * METHOD(ListBox, notifyEditDone);
extern int M_VTBLID(ListBox, notifyEdited);
#define ListBox_notifyEdited(__i, __t, listBox, row) \
   VMETHOD(CO(ListBox), ListBox, notifyEdited, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow), \
      __t _ARG listBox _ARG row)
extern C(Method) * METHOD(ListBox, notifyEdited);
extern int M_VTBLID(ListBox, notifyEditing);
#define ListBox_notifyEditing(__i, __t, listBox, row) \
   VMETHOD(CO(ListBox), ListBox, notifyEditing, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow), \
      __t _ARG listBox _ARG row)
extern C(Method) * METHOD(ListBox, notifyEditing);
extern int M_VTBLID(ListBox, notifyHighlight);
#define ListBox_notifyHighlight(__i, __t, listBox, row, mods) \
   VMETHOD(CO(ListBox), ListBox, notifyHighlight, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow) _ARG C(Modifiers), \
      __t _ARG listBox _ARG row _ARG mods)
extern C(Method) * METHOD(ListBox, notifyHighlight);
extern int M_VTBLID(ListBox, notifyKeyDown);
#define ListBox_notifyKeyDown(__i, __t, listBox, row, key, ch) \
   VMETHOD(CO(ListBox), ListBox, notifyKeyDown, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow) _ARG C(Key) _ARG unichar, \
      __t _ARG listBox _ARG row _ARG key _ARG ch)
extern C(Method) * METHOD(ListBox, notifyKeyDown);
extern int M_VTBLID(ListBox, notifyKeyHit);
#define ListBox_notifyKeyHit(__i, __t, listBox, row, key, ch) \
   VMETHOD(CO(ListBox), ListBox, notifyKeyHit, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow) _ARG C(Key) _ARG unichar, \
      __t _ARG listBox _ARG row _ARG key _ARG ch)
extern C(Method) * METHOD(ListBox, notifyKeyHit);
extern int M_VTBLID(ListBox, notifyModified);
#define ListBox_notifyModified(__i, __t, listBox, row) \
   VMETHOD(CO(ListBox), ListBox, notifyModified, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow), \
      __t _ARG listBox _ARG row)
extern C(Method) * METHOD(ListBox, notifyModified);
extern int M_VTBLID(ListBox, notifyMove);
#define ListBox_notifyMove(__i, __t, listBox, row, mods) \
   VMETHOD(CO(ListBox), ListBox, notifyMove, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow) _ARG C(Modifiers), \
      __t _ARG listBox _ARG row _ARG mods)
extern C(Method) * METHOD(ListBox, notifyMove);
extern int M_VTBLID(ListBox, notifyMoved);
#define ListBox_notifyMoved(__i, __t, listBox, row, mods) \
   VMETHOD(CO(ListBox), ListBox, notifyMoved, __i, void, \
      C(Window) _ARG C(ListBox) _ARG C(DataRow) _ARG C(Modifiers), \
      __t _ARG listBox _ARG row _ARG mods)
extern C(Method) * METHOD(ListBox, notifyMoved);
extern int M_VTBLID(ListBox, notifyMovedField);
#define ListBox_notifyMovedField(__i, __t, listBox, field, mods) \
   VMETHOD(CO(ListBox), ListBox, notifyMovedField, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataField) _ARG C(Modifiers), \
      __t _ARG listBox _ARG field _ARG mods)
extern C(Method) * METHOD(ListBox, notifyMovedField);
extern int M_VTBLID(ListBox, notifyReclick);
#define ListBox_notifyReclick(__i, __t, listBox, row, mods) \
   VMETHOD(CO(ListBox), ListBox, notifyReclick, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow) _ARG C(Modifiers), \
      __t _ARG listBox _ARG row _ARG mods)
extern C(Method) * METHOD(ListBox, notifyReclick);
extern int M_VTBLID(ListBox, notifyResized);
#define ListBox_notifyResized(__i, __t, listBox, field, mods) \
   VMETHOD(CO(ListBox), ListBox, notifyResized, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataField) _ARG C(Modifiers), \
      __t _ARG listBox _ARG field _ARG mods)
extern C(Method) * METHOD(ListBox, notifyResized);
extern int M_VTBLID(ListBox, notifyRightClick);
#define ListBox_notifyRightClick(__i, __t, listBox, x, y, mods) \
   VMETHOD(CO(ListBox), ListBox, notifyRightClick, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG int _ARG int _ARG C(Modifiers), \
      __t _ARG listBox _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(ListBox, notifyRightClick);
extern int M_VTBLID(ListBox, notifySelect);
#define ListBox_notifySelect(__i, __t, listBox, row, mods) \
   VMETHOD(CO(ListBox), ListBox, notifySelect, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataRow) _ARG C(Modifiers), \
      __t _ARG listBox _ARG row _ARG mods)
extern C(Method) * METHOD(ListBox, notifySelect);
extern int M_VTBLID(ListBox, notifySort);
#define ListBox_notifySort(__i, __t, listBox, field, mods) \
   VMETHOD(CO(ListBox), ListBox, notifySort, __i, C(bool), \
      C(Window) _ARG C(ListBox) _ARG C(DataField) _ARG C(Modifiers), \
      __t _ARG listBox _ARG field _ARG mods)
extern C(Method) * METHOD(ListBox, notifySort);
extern void (* ListBox_removeField)(C(ListBox) __this, C(DataField) field);

extern void (* ListBox_selectRow)(C(ListBox) __this, C(DataRow) row);

extern void * (* ListBox_setData)(C(ListBox) __this, C(DataField) field, any_object data);

extern void (* ListBox_sort)(C(ListBox) __this, C(DataField) field, int order);

extern void (* ListBox_stopEditing)(C(ListBox) __this, C(bool) save);

extern C(Property) * PROPERTY(ListBox, freeSelect);
extern void (* ListBox_set_freeSelect)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_freeSelect)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, currentRow);
extern void (* ListBox_set_currentRow)(C(ListBox) l, C(DataRow) value);
extern C(DataRow) (* ListBox_get_currentRow)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, currentField);
extern void (* ListBox_set_currentField)(C(ListBox) l, C(DataField) value);
extern C(DataField) (* ListBox_get_currentField)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, rowHeight);
extern void (* ListBox_set_rowHeight)(C(ListBox) l, int value);
extern int (* ListBox_get_rowHeight)(C(ListBox) l);
extern bool (* ListBox_isSet_rowHeight)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, typingTimeout);
extern void (* ListBox_set_typingTimeout)(C(ListBox) l, C(Time) value);
extern C(Time) (* ListBox_get_typingTimeout)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, moveRows);
extern void (* ListBox_set_moveRows)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_moveRows)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, moveFields);
extern void (* ListBox_set_moveFields)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_moveFields)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, resizable);
extern void (* ListBox_set_resizable)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_resizable)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, autoScroll);
extern void (* ListBox_set_autoScroll)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_autoScroll)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, alwaysHighLight);
extern void (* ListBox_set_alwaysHighLight)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_alwaysHighLight)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, hasClearHeader);
extern void (* ListBox_set_hasClearHeader)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_hasClearHeader)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, hasHeader);
extern void (* ListBox_set_hasHeader)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_hasHeader)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, multiSelect);
extern void (* ListBox_set_multiSelect)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_multiSelect)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, alwaysEdit);
extern void (* ListBox_set_alwaysEdit)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_alwaysEdit)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, fullRowSelect);
extern void (* ListBox_set_fullRowSelect)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_fullRowSelect)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, collapseControl);
extern void (* ListBox_set_collapseControl)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_collapseControl)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, treeBranches);
extern void (* ListBox_set_treeBranches)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_treeBranches)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, rootCollapseButton);
extern void (* ListBox_set_rootCollapseButton)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_rootCollapseButton)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, sortable);
extern void (* ListBox_set_sortable)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_sortable)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, noDragging);
extern void (* ListBox_set_noDragging)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_noDragging)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, fillLastField);
extern void (* ListBox_set_fillLastField)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_fillLastField)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, numSelections);
extern int (* ListBox_get_numSelections)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, currentIndex);
extern int (* ListBox_get_currentIndex)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, lastRow);
extern C(DataRow) (* ListBox_get_lastRow)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, firstRow);
extern C(DataRow) (* ListBox_get_firstRow)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, rowCount);
extern int (* ListBox_get_rowCount)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, firstField);
extern C(DataField) (* ListBox_get_firstField)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, selectionColor);
extern void (* ListBox_set_selectionColor)(C(ListBox) l, C(Color) value);
extern C(Color) (* ListBox_get_selectionColor)(C(ListBox) l);
extern bool (* ListBox_isSet_selectionColor)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, selectionText);
extern void (* ListBox_set_selectionText)(C(ListBox) l, C(Color) value);
extern C(Color) (* ListBox_get_selectionText)(C(ListBox) l);
extern bool (* ListBox_isSet_selectionText)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, stippleColor);
extern void (* ListBox_set_stippleColor)(C(ListBox) l, C(Color) value);
extern C(Color) (* ListBox_get_stippleColor)(C(ListBox) l);

extern C(Property) * PROPERTY(ListBox, expandOnAdd);
extern void (* ListBox_set_expandOnAdd)(C(ListBox) l, C(bool) value);
extern C(bool) (* ListBox_get_expandOnAdd)(C(ListBox) l);

extern void (* Menu_addDynamic)(C(Menu) __this, C(MenuItem) addedItem, C(Window) master, C(bool) persistent);

extern void (* Menu_addItem)(C(Menu) __this, C(MenuItem) item);

extern void (* Menu_addSubMenu)(C(Menu) __this, C(Menu) subMenu);

extern void (* Menu_clean)(C(Menu) __this, C(Window) window);

extern void (* Menu_clear)(C(Menu) __this);

extern C(MenuItem) (* Menu_findItem)(C(Menu) __this, C(bool) (* notifySelect)(C(MenuItem) selection, C(Modifiers) mods), uint64 id);

extern C(Menu) (* Menu_findMenu)(C(Menu) __this, const char * name);

extern void (* Menu_merge)(C(Menu) __this, C(Menu) menuBeingMerged, C(bool) menuBar, C(Window) window);

extern void (* Menu_removeItem)(C(Menu) __this, C(MenuItem) item);

extern C(Property) * PROPERTY(Menu, parent);
extern void (* Menu_set_parent)(C(Menu) m, C(Menu) value);

extern C(Property) * PROPERTY(Menu, text);
extern void (* Menu_set_text)(C(Menu) m, const char * value);

extern C(Property) * PROPERTY(Menu, hotKey);
extern void (* Menu_set_hotKey)(C(Menu) m, C(Key) value);

extern C(Property) * PROPERTY(Menu, hasMargin);
extern void (* Menu_set_hasMargin)(C(Menu) m, C(bool) value);

extern C(Property) * PROPERTY(Menu, copyText);
extern void (* Menu_set_copyText)(C(Menu) m, C(bool) value);

extern int M_VTBLID(MenuItem, notifySelect);
#define MenuItem_notifySelect(__i, __t, selection, mods) \
   VMETHOD(CO(MenuItem), MenuItem, notifySelect, __i, C(bool), \
      C(Window) _ARG C(MenuItem) _ARG C(Modifiers), \
      __t _ARG selection _ARG mods)
extern C(Method) * METHOD(MenuItem, notifySelect);
extern C(Property) * PROPERTY(MenuItem, parent);
extern void (* MenuItem_set_parent)(C(MenuItem) m, C(Menu) value);

extern C(Property) * PROPERTY(MenuItem, text);
extern void (* MenuItem_set_text)(C(MenuItem) m, const char * value);

extern C(Property) * PROPERTY(MenuItem, hotKey);
extern void (* MenuItem_set_hotKey)(C(MenuItem) m, C(Key) value);

extern C(Property) * PROPERTY(MenuItem, accelerator);
extern void (* MenuItem_set_accelerator)(C(MenuItem) m, C(Key) value);

extern C(Property) * PROPERTY(MenuItem, checked);
extern void (* MenuItem_set_checked)(C(MenuItem) m, C(bool) value);
extern C(bool) (* MenuItem_get_checked)(C(MenuItem) m);

extern C(Property) * PROPERTY(MenuItem, disabled);
extern void (* MenuItem_set_disabled)(C(MenuItem) m, C(bool) value);

extern C(Property) * PROPERTY(MenuItem, checkable);
extern void (* MenuItem_set_checkable)(C(MenuItem) m, C(bool) value);

extern C(Property) * PROPERTY(MenuItem, isRadio);
extern void (* MenuItem_set_isRadio)(C(MenuItem) m, C(bool) value);

extern C(Property) * PROPERTY(MenuItem, id);
extern void (* MenuItem_set_id)(C(MenuItem) m, uint64 value);
extern uint64 (* MenuItem_get_id)(C(MenuItem) m);

extern C(Property) * PROPERTY(MenuItem, bitmap);
extern void (* MenuItem_set_bitmap)(C(MenuItem) m, C(BitmapResource) value);
extern C(BitmapResource) (* MenuItem_get_bitmap)(C(MenuItem) m);

extern C(Property) * PROPERTY(MenuItem, copyText);
extern void (* MenuItem_set_copyText)(C(MenuItem) m, C(bool) value);

extern C(Property) * PROPERTY(MenuItem, bold);
extern void (* MenuItem_set_bold)(C(MenuItem) m, C(bool) value);
extern C(bool) (* MenuItem_get_bold)(C(MenuItem) m);

struct CM(OldArray)
{
   C(Class) * type;
};
extern C(Property) * PROPERTY(OldArray, size);
extern void (* OldArray_set_size)(C(OldArray) o, uint value);
extern uint (* OldArray_get_size)(C(OldArray) o);

extern C(Property) * PROPERTY(OldArray, data);
extern void (* OldArray_set_data)(C(OldArray) o, void * value);

extern int M_VTBLID(PaneSplitter, notifyResized);
#define PaneSplitter_notifyResized(__i, __t, splitter) \
   VMETHOD(CO(PaneSplitter), PaneSplitter, notifyResized, __i, C(bool), \
      C(Window) _ARG C(PaneSplitter), \
      __t _ARG splitter)
extern C(Method) * METHOD(PaneSplitter, notifyResized);
extern C(Property) * PROPERTY(PaneSplitter, toolSize);
extern void (* PaneSplitter_set_toolSize)(C(PaneSplitter) p, int value);
extern int (* PaneSplitter_get_toolSize)(C(PaneSplitter) p);

extern C(Property) * PROPERTY(PaneSplitter, toolGap);
extern void (* PaneSplitter_set_toolGap)(C(PaneSplitter) p, int value);
extern int (* PaneSplitter_get_toolGap)(C(PaneSplitter) p);

extern C(Property) * PROPERTY(PaneSplitter, leftPane);
extern void (* PaneSplitter_set_leftPane)(C(PaneSplitter) p, C(Window) value);
extern C(Window) (* PaneSplitter_get_leftPane)(C(PaneSplitter) p);

extern C(Property) * PROPERTY(PaneSplitter, rightPane);
extern void (* PaneSplitter_set_rightPane)(C(PaneSplitter) p, C(Window) value);
extern C(Window) (* PaneSplitter_get_rightPane)(C(PaneSplitter) p);

extern C(Property) * PROPERTY(PaneSplitter, topPane);
extern void (* PaneSplitter_set_topPane)(C(PaneSplitter) p, C(Window) value);
extern C(Window) (* PaneSplitter_get_topPane)(C(PaneSplitter) p);

extern C(Property) * PROPERTY(PaneSplitter, bottomPane);
extern void (* PaneSplitter_set_bottomPane)(C(PaneSplitter) p, C(Window) value);
extern C(Window) (* PaneSplitter_get_bottomPane)(C(PaneSplitter) p);

extern C(Property) * PROPERTY(PaneSplitter, scaleSplit);
extern void (* PaneSplitter_set_scaleSplit)(C(PaneSplitter) p, double value);
extern double (* PaneSplitter_get_scaleSplit)(C(PaneSplitter) p);

extern C(Property) * PROPERTY(PaneSplitter, orientation);
extern void (* PaneSplitter_set_orientation)(C(PaneSplitter) p, C(ScrollDirection) value);
extern C(ScrollDirection) (* PaneSplitter_get_orientation)(C(PaneSplitter) p);

extern C(Property) * PROPERTY(PaneSplitter, split);
extern void (* PaneSplitter_set_split)(C(PaneSplitter) p, int value);
extern int (* PaneSplitter_get_split)(C(PaneSplitter) p);

extern void (* PathBox_deselect)(C(PathBox) __this);

extern void (* PathBox_end)(C(PathBox) __this);

extern void (* PathBox_home)(C(PathBox) __this);

extern int M_VTBLID(PathBox, notifyModified);
#define PathBox_notifyModified(__i, __t, pathBox) \
   VMETHOD(CO(PathBox), PathBox, notifyModified, __i, C(bool), \
      C(Window) _ARG C(PathBox), \
      __t _ARG pathBox)
extern C(Method) * METHOD(PathBox, notifyModified);
extern void (* PathBox_selectAll)(C(PathBox) __this);

extern C(Property) * PROPERTY(PathBox, editBox);
extern C(EditBox) (* PathBox_get_editBox)(C(PathBox) p);

extern C(Property) * PROPERTY(PathBox, typeExpected);
extern void (* PathBox_set_typeExpected)(C(PathBox) p, C(PathTypeExpected) value);

extern C(Property) * PROPERTY(PathBox, browseDialog);
extern void (* PathBox_set_browseDialog)(C(PathBox) p, C(FileDialog) value);
extern C(FileDialog) (* PathBox_get_browseDialog)(C(PathBox) p);

extern C(Property) * PROPERTY(PathBox, path);
extern void (* PathBox_set_path)(C(PathBox) p, constString value);
extern constString (* PathBox_get_path)(C(PathBox) p);

extern C(Property) * PROPERTY(PathBox, slashPath);
extern C(String) (* PathBox_get_slashPath)(C(PathBox) p);

extern C(Property) * PROPERTY(PathBox, systemPath);
extern C(String) (* PathBox_get_systemPath)(C(PathBox) p);

extern C(Property) * PROPERTY(PathBox, selectionColor);
extern void (* PathBox_set_selectionColor)(C(PathBox) p, C(Color) value);
extern C(Color) (* PathBox_get_selectionColor)(C(PathBox) p);

extern C(Property) * PROPERTY(PathBox, selectionText);
extern void (* PathBox_set_selectionText)(C(PathBox) p, C(Color) value);
extern C(Color) (* PathBox_get_selectionText)(C(PathBox) p);

extern C(Property) * PROPERTY(Picture, tint);
extern void (* Picture_set_tint)(C(Picture) p, C(Color) value);

extern C(Property) * PROPERTY(Picture, image);
extern void (* Picture_set_image)(C(Picture) p, C(BitmapResource) value);
extern C(BitmapResource) (* Picture_get_image)(C(Picture) p);

extern C(Property) * PROPERTY(Picture, filter);
extern void (* Picture_set_filter)(C(Picture) p, C(bool) value);
extern C(bool) (* Picture_get_filter)(C(Picture) p);

extern C(Property) * PROPERTY(Picture, bitmapImage);
extern void (* Picture_set_bitmapImage)(C(Picture) p, C(Bitmap) value);

extern C(Property) * PROPERTY(PopupMenu, menu);
extern void (* PopupMenu_set_menu)(C(PopupMenu) p, C(Menu) value);
extern C(Menu) (* PopupMenu_get_menu)(C(PopupMenu) p);

extern C(Property) * PROPERTY(PopupMenu, isMenuBar);
extern void (* PopupMenu_set_isMenuBar)(C(PopupMenu) p, C(bool) value);

extern C(Property) * PROPERTY(PopupMenu, focus);
extern C(bool) (* PopupMenu_get_focus)(C(PopupMenu) p);

extern C(Property) * PROPERTY(ProgressBar, progress);
extern void (* ProgressBar_set_progress)(C(ProgressBar) p, uint value);
extern uint (* ProgressBar_get_progress)(C(ProgressBar) p);

extern C(Property) * PROPERTY(ProgressBar, range);
extern void (* ProgressBar_set_range)(C(ProgressBar) p, uint value);
extern uint (* ProgressBar_get_range)(C(ProgressBar) p);

struct CM(ScrollBar)
{
   byte __ecerePrivateData0[24];
   C(Button) downBtn;
   C(Button) upBtn;
   C(Button) thumb;
   byte __ecerePrivateData1[12];
   int thumbSize;
};
extern C(bool) (* ScrollBar_action)(C(ScrollBar) __this, C(ScrollBarAction) action, int newPosition, C(Key) key);

extern int M_VTBLID(ScrollBar, notifyScrolling);
#define ScrollBar_notifyScrolling(__i, __t, scrollBar, action, position, key) \
   VMETHOD(CO(ScrollBar), ScrollBar, notifyScrolling, __i, void, \
      C(Window) _ARG C(ScrollBar) _ARG C(ScrollBarAction) _ARG int _ARG C(Key), \
      __t _ARG scrollBar _ARG action _ARG position _ARG key)
extern C(Method) * METHOD(ScrollBar, notifyScrolling);
extern C(Property) * PROPERTY(ScrollBar, direction);
extern void (* ScrollBar_set_direction)(C(ScrollBar) s, C(ScrollDirection) value);
extern C(ScrollDirection) (* ScrollBar_get_direction)(C(ScrollBar) s);

extern C(Property) * PROPERTY(ScrollBar, windowOwned);
extern void (* ScrollBar_set_windowOwned)(C(ScrollBar) s, C(bool) value);

extern C(Property) * PROPERTY(ScrollBar, snap);
extern void (* ScrollBar_set_snap)(C(ScrollBar) s, C(bool) value);
extern C(bool) (* ScrollBar_get_snap)(C(ScrollBar) s);

extern C(Property) * PROPERTY(ScrollBar, range);
extern void (* ScrollBar_set_range)(C(ScrollBar) s, int value);
extern int (* ScrollBar_get_range)(C(ScrollBar) s);

extern C(Property) * PROPERTY(ScrollBar, seen);
extern void (* ScrollBar_set_seen)(C(ScrollBar) s, int value);
extern int (* ScrollBar_get_seen)(C(ScrollBar) s);

extern C(Property) * PROPERTY(ScrollBar, total);
extern void (* ScrollBar_set_total)(C(ScrollBar) s, int value);
extern int (* ScrollBar_get_total)(C(ScrollBar) s);

extern C(Property) * PROPERTY(ScrollBar, lineStep);
extern void (* ScrollBar_set_lineStep)(C(ScrollBar) s, int value);
extern int (* ScrollBar_get_lineStep)(C(ScrollBar) s);

extern C(Property) * PROPERTY(ScrollBar, pageStep);
extern void (* ScrollBar_set_pageStep)(C(ScrollBar) s, int value);
extern int (* ScrollBar_get_pageStep)(C(ScrollBar) s);

extern C(Property) * PROPERTY(ScrollBar, thumbPosition);
extern void (* ScrollBar_set_thumbPosition)(C(ScrollBar) s, int value);
extern int (* ScrollBar_get_thumbPosition)(C(ScrollBar) s);

extern void (* SelectorBar_addButton)(C(SelectorBar) __this, C(SelectorButton) button);

extern void (* SelectorBar_clear)(C(SelectorBar) __this);

extern C(SelectorButton) (* SelectorBar_findButtonByID)(C(SelectorBar) __this, int64 id);

extern void (* SelectorBar_removeButton)(C(SelectorBar) __this, C(SelectorButton) button);

extern void (* SelectorBar_select)(C(SelectorBar) __this, C(SelectorButton) button);

extern C(Property) * PROPERTY(SelectorBar, selectedButton);
extern C(SelectorButton) (* SelectorBar_get_selectedButton)(C(SelectorBar) s);

extern void (* Stacker_destroyChildren)(C(Stacker) __this);

extern C(Window) (* Stacker_getNextStackedItem)(C(Stacker) __this, C(Window) current, C(bool) previous, C(Class) * filter);

extern void (* Stacker_makeControlVisible)(C(Stacker) __this, C(Window) control);

extern C(Property) * PROPERTY(Stacker, direction);
extern void (* Stacker_set_direction)(C(Stacker) s, C(ScrollDirection) value);
extern C(ScrollDirection) (* Stacker_get_direction)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, gap);
extern void (* Stacker_set_gap)(C(Stacker) s, int value);
extern int (* Stacker_get_gap)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, reverse);
extern void (* Stacker_set_reverse)(C(Stacker) s, C(bool) value);
extern C(bool) (* Stacker_get_reverse)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, scrollable);
extern void (* Stacker_set_scrollable)(C(Stacker) s, C(bool) value);
extern C(bool) (* Stacker_get_scrollable)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, controls);
extern C(Array) (* Stacker_get_controls)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, flipper);
extern void (* Stacker_set_flipper)(C(Stacker) s, C(Window) value);
extern C(Window) (* Stacker_get_flipper)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, flipSpring);
extern void (* Stacker_set_flipSpring)(C(Stacker) s, C(bool) value);
extern C(bool) (* Stacker_get_flipSpring)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, autoSize);
extern void (* Stacker_set_autoSize)(C(Stacker) s, C(bool) value);
extern C(bool) (* Stacker_get_autoSize)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, margin);
extern void (* Stacker_set_margin)(C(Stacker) s, int value);
extern int (* Stacker_get_margin)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, endButtons);
extern void (* Stacker_set_endButtons)(C(Stacker) s, C(bool) value);
extern C(bool) (* Stacker_get_endButtons)(C(Stacker) s);

extern C(Property) * PROPERTY(Stacker, hoverScroll);
extern void (* Stacker_set_hoverScroll)(C(Stacker) s, C(bool) value);
extern C(bool) (* Stacker_get_hoverScroll)(C(Stacker) s);

extern void (* StatusBar_addField)(C(StatusBar) __this, C(StatusField) field);

extern void (* StatusBar_clear)(C(StatusBar) __this);

extern void (* StatusBar_removeField)(C(StatusBar) __this, C(StatusField) field);

extern C(Property) * PROPERTY(StatusBar, minInfoWidth);
extern void (* StatusBar_set_minInfoWidth)(C(StatusBar) s, int value);
extern int (* StatusBar_get_minInfoWidth)(C(StatusBar) s);

extern void (* StatusField_setTextf)(C(StatusField) __this, const char * format, ...);

extern C(Property) * PROPERTY(StatusField, statusBar);
extern void (* StatusField_set_statusBar)(C(StatusField) s, C(StatusBar) value);

extern C(Property) * PROPERTY(StatusField, color);
extern void (* StatusField_set_color)(C(StatusField) s, C(Color) value);

extern C(Property) * PROPERTY(StatusField, backColor);
extern void (* StatusField_set_backColor)(C(StatusField) s, C(ColorAlpha) value);

extern C(Property) * PROPERTY(StatusField, bold);
extern void (* StatusField_set_bold)(C(StatusField) s, C(bool) value);

extern C(Property) * PROPERTY(StatusField, text);
extern void (* StatusField_set_text)(C(StatusField) s, const char * value);

extern C(Property) * PROPERTY(StatusField, width);
extern void (* StatusField_set_width)(C(StatusField) s, int value);

extern C(Property) * PROPERTY(SyntaxColorScheme, keywordColors);
extern void (* SyntaxColorScheme_set_keywordColors)(C(SyntaxColorScheme) s, C(Container) value);
extern C(Container) (* SyntaxColorScheme_get_keywordColors)(C(SyntaxColorScheme) s);

extern void (* Tab_selectTab)(C(Tab) __this);

extern C(Property) * PROPERTY(Tab, tabControl);
extern void (* Tab_set_tabControl)(C(Tab) t, C(TabControl) value);
extern C(TabControl) (* Tab_get_tabControl)(C(Tab) t);

extern C(Property) * PROPERTY(Tab, isAdded);
extern C(bool) (* Tab_get_isAdded)(C(Tab) t);

extern void (* TabControl_addTab)(C(TabControl) __this, C(Tab) tab);

extern void (* TabControl_removeTab)(C(TabControl) __this, C(Tab) tab);

extern C(Property) * PROPERTY(TabControl, placement);
extern void (* TabControl_set_placement)(C(TabControl) t, C(TabsPlacement) value);
extern C(TabsPlacement) (* TabControl_get_placement)(C(TabControl) t);

extern C(Property) * PROPERTY(TabControl, buttonsOffset);
extern void (* TabControl_set_buttonsOffset)(C(TabControl) t, int value);
extern int (* TabControl_get_buttonsOffset)(C(TabControl) t);

extern C(Property) * PROPERTY(TabControl, curTab);
extern void (* TabControl_set_curTab)(C(TabControl) t, C(Tab) value);
extern C(Tab) (* TabControl_get_curTab)(C(TabControl) t);

extern C(Property) * PROPERTY(ToolButton, menuItemPtr);
extern void (* ToolButton_set_menuItemPtr)(C(ToolButton) t, C(MenuItem) * value);

extern C(Property) * PROPERTY(ToolButton, menuItem);
extern C(MenuItem) (* ToolButton_get_menuItem)(C(ToolButton) t);

extern C(Property) * PROPERTY(ToolTip, tip);
extern void (* ToolTip_set_tip)(C(ToolTip) t, constString value);
extern constString (* ToolTip_get_tip)(C(ToolTip) t);

struct C(UndoAction)
{
   subclass(UndoAction) type;
   C(bool) continued;
};
extern int M_VTBLID(UndoAction, redo);
#define UndoAction_redo(__i, data) \
   VMETHOD(CO(UndoAction), UndoAction, redo, __i, void, \
      C(UndoAction) * _ARG void *, \
      __i _ARG data)
extern C(Method) * METHOD(UndoAction, redo);
extern int M_VTBLID(UndoAction, undo);
#define UndoAction_undo(__i, data) \
   VMETHOD(CO(UndoAction), UndoAction, undo, __i, void, \
      C(UndoAction) * _ARG void *, \
      __i _ARG data)
extern C(Method) * METHOD(UndoAction, undo);
struct CM(UndoBuffer)
{
   byte __ecerePrivateData0[8];
   int count;
   int curAction;
   void * data;
   int dontRecord;
   C(bool) insideRedo;
   C(bool) recordAsOne;
   C(bool) firstEvent;
};
extern void (* UndoBuffer_clear)(C(UndoBuffer) __this);

extern void (* UndoBuffer_record)(C(UndoBuffer) __this, C(UndoAction) * action);

extern void (* UndoBuffer_redo)(C(UndoBuffer) __this);

extern void (* UndoBuffer_undo)(C(UndoBuffer) __this);


// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||gui  ////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
#if CPP11
enum C(WindowState) : int
#else
typedef int C(WindowState);
enum C(WindowState)
#endif
{
   WindowState_normal = 0x0,
   WindowState_minimized = 0x1,
   WindowState_maximized = 0x2
};

struct CM(WindowController)
{
   int (** windowVTbl)();
};
typedef C(Instance) C(WindowController);
#if CPP11
enum C(TouchPointerEvent) : int
#else
typedef int C(TouchPointerEvent);
enum C(TouchPointerEvent)
#endif
{
   TouchPointerEvent_move = 0x0,
   TouchPointerEvent_up = 0x1,
   TouchPointerEvent_down = 0x2,
   TouchPointerEvent_pointerUp = 0x3,
   TouchPointerEvent_pointerDown = 0x4
};

#if CPP11
enum C(SystemCursor) : int
#else
typedef int C(SystemCursor);
enum C(SystemCursor)
#endif
{
   SystemCursor_arrow = 0x0,
   SystemCursor_iBeam = 0x1,
   SystemCursor_cross = 0x2,
   SystemCursor_moving = 0x3,
   SystemCursor_sizeNESW = 0x4,
   SystemCursor_sizeNS = 0x5,
   SystemCursor_sizeNWSE = 0x6,
   SystemCursor_sizeWE = 0x7,
   SystemCursor_hand = 0x8
};

#if CPP11
enum C(SkinBitmap) : int
#else
typedef int C(SkinBitmap);
enum C(SkinBitmap)
#endif
{
   SkinBitmap_minimize = 0x0,
   SkinBitmap_maximize = 0x1,
   SkinBitmap_restore = 0x2,
   SkinBitmap_close = 0x3
};

struct C(SizeAnchor)
{
   C(Size) size;
   C(bool) isClientW;
   C(bool) isClientH;
};
typedef struct C(SizeAnchor) C(SizeAnchor);
typedef uint32 C(MouseButtons);
#if CPP11
enum C(AnchorValueType) : int
#else
typedef int C(AnchorValueType);
enum C(AnchorValueType)
#endif
{
   AnchorValueType_none = 0x0,
   AnchorValueType_offset = 0x1,
   AnchorValueType_relative = 0x2,
   AnchorValueType_middleRelative = 0x3,
   AnchorValueType_cascade = 0x4,
   AnchorValueType_vTiled = 0x5,
   AnchorValueType_hTiled = 0x6
};

struct C(MiddleAnchorValue)
{
   C(AnchorValueType) type;
   union
   {
      int distance;
      float percent;
   };
};
typedef struct C(MiddleAnchorValue) C(MiddleAnchorValue);
typedef struct C(Joystick) C(Joystick);
typedef C(Application) C(GuiApplication);
#if CPP11
enum C(DialogResult) : int64
#else
typedef int64 C(DialogResult);
enum C(DialogResult)
#endif
{
   DialogResult_cancel = 0x0,
   DialogResult_yes = 0x1,
   DialogResult_no = 0x2,
   DialogResult_ok = 0x3
};

typedef C(Instance) C(Cursor);
#if CPP11
enum C(CreationActivationOption) : int
#else
typedef int C(CreationActivationOption);
enum C(CreationActivationOption)
#endif
{
   CreationActivationOption_activate = 0x0,
   CreationActivationOption_flash = 0x1,
   CreationActivationOption_doNothing = 0x2
};

typedef struct C(ClipBoard) C(ClipBoard);
typedef uint32 C(BorderBits);
#if CPP11
enum C(BorderStyle) : uint
#else
typedef C(BorderBits) C(BorderStyle);
enum C(BorderStyle)
#endif
{
   BorderStyle_none = 0x0,
   BorderStyle_contour = 0x1,
   BorderStyle_fixed = 0x3,
   BorderStyle_sizable = 0x7,
   BorderStyle_thin = 0x23,
   BorderStyle_sizableThin = 0x27,
   BorderStyle_deep = 0x8,
   BorderStyle_bevel = 0x10,
   BorderStyle_sizableDeep = 0xF,
   BorderStyle_sizableBevel = 0x17,
   BorderStyle_fixedDeep = 0xB,
   BorderStyle_fixedBevel = 0x13,
   BorderStyle_deepContour = 0x9
};

struct C(AnchorValue)
{
   C(AnchorValueType) type;
   union
   {
      int distance;
      float percent;
   };
};
typedef struct C(AnchorValue) C(AnchorValue);
struct C(Anchor)
{
   union
   {
      C(AnchorValue) left;
      C(MiddleAnchorValue) horz;
   };
   union
   {
      C(AnchorValue) top;
      C(MiddleAnchorValue) vert;
   };
   C(AnchorValue) right;
   C(AnchorValue) bottom;
};
typedef struct C(Anchor) C(Anchor);
// end -- moved backwards outputs
typedef C(Window) C(ControllableWindow);
typedef C(Instance) C(Interface);
#if CPP11
enum C(KeyCode) : uint
#else
typedef C(Key) C(KeyCode);
enum C(KeyCode)
#endif
{
   KeyCode_escape = 0x1,
   KeyCode_k1 = 0x2,
   KeyCode_bang = 0x2,
   KeyCode_k2 = 0x3,
   KeyCode_commercial = 0x3,
   KeyCode_k3 = 0x4,
   KeyCode_pound = 0x4,
   KeyCode_k4 = 0x5,
   KeyCode_dollar = 0x5,
   KeyCode_k5 = 0x6,
   KeyCode_percent = 0x6,
   KeyCode_k6 = 0x7,
   KeyCode_circumflex = 0x7,
   KeyCode_k7 = 0x8,
   KeyCode_ampersand = 0x8,
   KeyCode_k8 = 0x9,
   KeyCode_star = 0x9,
   KeyCode_k9 = 0xA,
   KeyCode_leftParanthesis = 0xA,
   KeyCode_k0 = 0xB,
   KeyCode_rightParanthesis = 0xA,
   KeyCode_minus = 0xC,
   KeyCode_underscore = 0xC,
   KeyCode_equal = 0xD,
   KeyCode_plus = 0xD,
   KeyCode_backSpace = 0xE,
   KeyCode_tab = 0xF,
   KeyCode_q = 0x10,
   KeyCode_w = 0x11,
   KeyCode_e = 0x12,
   KeyCode_r = 0x13,
   KeyCode_t = 0x14,
   KeyCode_y = 0x15,
   KeyCode_u = 0x16,
   KeyCode_i = 0x17,
   KeyCode_o = 0x18,
   KeyCode_p = 0x19,
   KeyCode_leftBracket = 0x1A,
   KeyCode_rightBracket = 0x1B,
   KeyCode_enter = 0x1C,
   KeyCode_leftControl = 0x1D,
   KeyCode_a = 0x1E,
   KeyCode_s = 0x1F,
   KeyCode_d = 0x20,
   KeyCode_f = 0x21,
   KeyCode_g = 0x22,
   KeyCode_h = 0x23,
   KeyCode_j = 0x24,
   KeyCode_k = 0x25,
   KeyCode_l = 0x26,
   KeyCode_semicolon = 0x27,
   KeyCode_colon = 0x27,
   KeyCode_quote = 0x28,
   KeyCode_doubleQuote = 0x28,
   KeyCode_tilde = 0x29,
   KeyCode_backQuote = 0x29,
   KeyCode_leftShift = 0x2A,
   KeyCode_backSlash = 0x2B,
   KeyCode_pipe = 0x2B,
   KeyCode_z = 0x2C,
   KeyCode_x = 0x2D,
   KeyCode_c = 0x2E,
   KeyCode_v = 0x2F,
   KeyCode_b = 0x30,
   KeyCode_n = 0x31,
   KeyCode_m = 0x32,
   KeyCode_comma = 0x33,
   KeyCode_smallerThan = 0x33,
   KeyCode_period = 0x34,
   KeyCode_greaterThan = 0x34,
   KeyCode_slash = 0x35,
   KeyCode_questionMark = 0x35,
   KeyCode_rightShift = 0x36,
   KeyCode_keyPadStar = 0x37,
   KeyCode_leftAlt = 0x38,
   KeyCode_space = 0x39,
   KeyCode_capsLock = 0x3A,
   KeyCode_f1 = 0x3B,
   KeyCode_f2 = 0x3C,
   KeyCode_f3 = 0x3D,
   KeyCode_f4 = 0x3E,
   KeyCode_f5 = 0x3F,
   KeyCode_f6 = 0x40,
   KeyCode_f7 = 0x41,
   KeyCode_f8 = 0x42,
   KeyCode_f9 = 0x43,
   KeyCode_f10 = 0x44,
   KeyCode_numLock = 0x45,
   KeyCode_scrollLock = 0x46,
   KeyCode_keyPadHome = 0x47,
   KeyCode_keyPad7 = 0x47,
   KeyCode_keyPadUp = 0x48,
   KeyCode_keyPad8 = 0x48,
   KeyCode_keyPadPageUp = 0x49,
   KeyCode_keyPad9 = 0x49,
   KeyCode_keyPadMinus = 0x4A,
   KeyCode_keyPadLeft = 0x4B,
   KeyCode_keyPad4 = 0x4B,
   KeyCode_keyPad5 = 0x4C,
   KeyCode_keyPadRight = 0x4D,
   KeyCode_keyPad6 = 0x4D,
   KeyCode_keyPadPlus = 0x4E,
   KeyCode_keyPadEnd = 0x4F,
   KeyCode_keyPad1 = 0x4F,
   KeyCode_keyPadDown = 0x50,
   KeyCode_keyPad2 = 0x50,
   KeyCode_keyPadPageDown = 0x51,
   KeyCode_keyPad3 = 0x51,
   KeyCode_keyPadInsert = 0x52,
   KeyCode_keyPad0 = 0x52,
   KeyCode_keyPadDelete = 0x53,
   KeyCode_f11 = 0x57,
   KeyCode_f12 = 0x58,
   KeyCode_keyPadEnter = 0x60,
   KeyCode_rightControl = 0x61,
   KeyCode_keyPadSlash = 0x62,
   KeyCode_printScreen = 0x63,
   KeyCode_rightAlt = 0x64,
   KeyCode_pauseBreak = 0x65,
   KeyCode_home = 0x66,
   KeyCode_up = 0x67,
   KeyCode_pageUp = 0x68,
   KeyCode_left = 0x69,
   KeyCode_right = 0x6A,
   KeyCode_end = 0x6B,
   KeyCode_down = 0x6C,
   KeyCode_pageDown = 0x6D,
   KeyCode_insert = 0x6E,
   KeyCode_del = 0x6F,
   KeyCode_shift = 0x100,
   KeyCode_alt = 0x101,
   KeyCode_control = 0x102,
   KeyCode_wheelUp = 0x103,
   KeyCode_wheelDown = 0x104,
   KeyCode_hotKey = 0x105,
   KeyCode_defaultKey = 0x106,
   KeyCode_capsState = 0x107,
   KeyCode_numState = 0x108,
   KeyCode_scrollState = 0x109,
   KeyCode_play = 0x201,
   KeyCode_record = 0x202,
   KeyCode_pause = 0x203,
   KeyCode_rewind = 0x204,
   KeyCode_fastForward = 0x205,
   KeyCode_previousTrack = 0x206,
   KeyCode_nextTrack = 0x207,
   KeyCode_stop = 0x208,
   KeyCode_eject = 0x209,
   KeyCode_volumeUp = 0x20A,
   KeyCode_volumeDown = 0x20B,
   KeyCode_mute = 0x20C,
   KeyCode_remoteHome = 0x213,
   KeyCode_back = 0x3B,
   KeyCode_menu1 = 0x3C,
   KeyCode_menu2 = 0x3D,
   KeyCode_menu3 = 0x3E,
   KeyCode_menu4 = 0x3F,
   KeyCode_select = 0x1C
};

typedef C(String) C(MultiLineString);
#if CPP11
enum C(PredefinedKey) : uint
#else
typedef C(Key) C(PredefinedKey);
enum C(PredefinedKey)
#endif
{
   PredefinedKey_alt0 = 0x4000B,
   PredefinedKey_alt1 = 0x40002,
   PredefinedKey_alt2 = 0x40003,
   PredefinedKey_alt3 = 0x40004,
   PredefinedKey_alt4 = 0x40005,
   PredefinedKey_alt5 = 0x40006,
   PredefinedKey_alt6 = 0x40007,
   PredefinedKey_alt7 = 0x40008,
   PredefinedKey_alt8 = 0x40009,
   PredefinedKey_alt9 = 0x4000A,
   PredefinedKey_altA = 0x4001E,
   PredefinedKey_altB = 0x40030,
   PredefinedKey_altC = 0x4002E,
   PredefinedKey_altD = 0x40020,
   PredefinedKey_altE = 0x40012,
   PredefinedKey_altF = 0x40021,
   PredefinedKey_altG = 0x40022,
   PredefinedKey_altH = 0x40023,
   PredefinedKey_altI = 0x40017,
   PredefinedKey_altJ = 0x40024,
   PredefinedKey_altK = 0x40025,
   PredefinedKey_altL = 0x40026,
   PredefinedKey_altM = 0x40032,
   PredefinedKey_altN = 0x40031,
   PredefinedKey_altO = 0x40018,
   PredefinedKey_altP = 0x40019,
   PredefinedKey_altQ = 0x40010,
   PredefinedKey_altR = 0x40013,
   PredefinedKey_altS = 0x4001F,
   PredefinedKey_altT = 0x40014,
   PredefinedKey_altU = 0x40016,
   PredefinedKey_altV = 0x4002F,
   PredefinedKey_altW = 0x40011,
   PredefinedKey_altX = 0x4002D,
   PredefinedKey_altY = 0x40015,
   PredefinedKey_altZ = 0x4002C,
   PredefinedKey_altF1 = 0x4003B,
   PredefinedKey_altF2 = 0x4003C,
   PredefinedKey_altF3 = 0x4003D,
   PredefinedKey_altF4 = 0x4003E,
   PredefinedKey_altF5 = 0x4003F,
   PredefinedKey_altF6 = 0x40040,
   PredefinedKey_altF7 = 0x40041,
   PredefinedKey_altF8 = 0x40042,
   PredefinedKey_altF9 = 0x40043,
   PredefinedKey_altF10 = 0x40044,
   PredefinedKey_altF11 = 0x40057,
   PredefinedKey_altF12 = 0x40058,
   PredefinedKey_altLeft = 0x40069,
   PredefinedKey_altRight = 0x4006A,
   PredefinedKey_altUp = 0x40067,
   PredefinedKey_altDown = 0x4006C,
   PredefinedKey_altEnter = 0x4001C,
   PredefinedKey_altKeyPadEnter = 0x40060,
   PredefinedKey_altHome = 0x40066,
   PredefinedKey_altEnd = 0x4006B,
   PredefinedKey_altMinus = 0x4000C,
   PredefinedKey_altSpace = 0x40039,
   PredefinedKey_ctrl0 = 0x2000B,
   PredefinedKey_ctrl1 = 0x20002,
   PredefinedKey_ctrl2 = 0x20003,
   PredefinedKey_ctrl3 = 0x20004,
   PredefinedKey_ctrl4 = 0x20005,
   PredefinedKey_ctrl5 = 0x20006,
   PredefinedKey_ctrl6 = 0x20007,
   PredefinedKey_ctrl7 = 0x20008,
   PredefinedKey_ctrl8 = 0x20009,
   PredefinedKey_ctrl9 = 0x2000A,
   PredefinedKey_ctrlA = 0x2001E,
   PredefinedKey_ctrlB = 0x20030,
   PredefinedKey_ctrlC = 0x2002E,
   PredefinedKey_ctrlD = 0x20020,
   PredefinedKey_ctrlE = 0x20012,
   PredefinedKey_ctrlF = 0x20021,
   PredefinedKey_ctrlG = 0x20022,
   PredefinedKey_ctrlH = 0x20023,
   PredefinedKey_ctrlI = 0x20017,
   PredefinedKey_ctrlJ = 0x20024,
   PredefinedKey_ctrlK = 0x20025,
   PredefinedKey_ctrlL = 0x20026,
   PredefinedKey_ctrlM = 0x20032,
   PredefinedKey_ctrlN = 0x20031,
   PredefinedKey_ctrlO = 0x20018,
   PredefinedKey_ctrlP = 0x20019,
   PredefinedKey_ctrlQ = 0x20010,
   PredefinedKey_ctrlR = 0x20013,
   PredefinedKey_ctrlS = 0x2001F,
   PredefinedKey_ctrlT = 0x20014,
   PredefinedKey_ctrlU = 0x20016,
   PredefinedKey_ctrlV = 0x2002F,
   PredefinedKey_ctrlW = 0x20011,
   PredefinedKey_ctrlX = 0x2002D,
   PredefinedKey_ctrlY = 0x20015,
   PredefinedKey_ctrlZ = 0x2002C,
   PredefinedKey_ctrlF1 = 0x2003B,
   PredefinedKey_ctrlF2 = 0x2003C,
   PredefinedKey_ctrlF3 = 0x2003D,
   PredefinedKey_ctrlF4 = 0x2003E,
   PredefinedKey_ctrlF5 = 0x2003F,
   PredefinedKey_ctrlF6 = 0x20040,
   PredefinedKey_ctrlF7 = 0x20041,
   PredefinedKey_ctrlF8 = 0x20042,
   PredefinedKey_ctrlF9 = 0x20043,
   PredefinedKey_ctrlF10 = 0x20044,
   PredefinedKey_ctrlF11 = 0x20057,
   PredefinedKey_ctrlF12 = 0x20058,
   PredefinedKey_ctrlLeft = 0x20069,
   PredefinedKey_ctrlRight = 0x2006A,
   PredefinedKey_ctrlUp = 0x20067,
   PredefinedKey_ctrlDown = 0x2006C,
   PredefinedKey_ctrlEnter = 0x2001C,
   PredefinedKey_ctrlHome = 0x20066,
   PredefinedKey_ctrlEnd = 0x2006B,
   PredefinedKey_ctrlPageUp = 0x20068,
   PredefinedKey_ctrlPageDown = 0x2006D,
   PredefinedKey_ctrlInsert = 0x2006E,
   PredefinedKey_ctrlSpace = 0x20039,
   PredefinedKey_shiftTab = 0x1000F,
   PredefinedKey_shiftF1 = 0x1003B,
   PredefinedKey_shiftF2 = 0x1003C,
   PredefinedKey_shiftF3 = 0x1003D,
   PredefinedKey_shiftF4 = 0x1003E,
   PredefinedKey_shiftF5 = 0x1003F,
   PredefinedKey_shiftF6 = 0x10040,
   PredefinedKey_shiftF7 = 0x10041,
   PredefinedKey_shiftF8 = 0x10042,
   PredefinedKey_shiftF9 = 0x10043,
   PredefinedKey_shiftF10 = 0x10044,
   PredefinedKey_shiftF11 = 0x10057,
   PredefinedKey_shiftF12 = 0x10058,
   PredefinedKey_shiftInsert = 0x1006E,
   PredefinedKey_shiftDel = 0x1006F
};

typedef C(Instance) C(Skin);
typedef uint32 C(SmartKey);
typedef struct C(TouchPointerInfo) C(TouchPointerInfo);
typedef uint64_t TP(WindowController, V);
extern C(Property) * PROPERTY(AnchorValue, MinMaxValue);
extern void (* AnchorValue_from_MinMaxValue)(C(AnchorValue) a, C(MinMaxValue) value);
extern C(MinMaxValue) (* AnchorValue_to_MinMaxValue)(C(AnchorValue) a);

extern C(Property) * PROPERTY(AnchorValue, int);
extern void (* AnchorValue_from_int)(C(AnchorValue) a, int value);
extern int (* AnchorValue_to_int)(C(AnchorValue) a);

extern C(Property) * PROPERTY(AnchorValue, double);
extern void (* AnchorValue_from_double)(C(AnchorValue) a, double value);
extern double (* AnchorValue_to_double)(C(AnchorValue) a);

#define BORDERBITS_contour_SHIFT                         0
#define BORDERBITS_contour_MASK                          0x1
#define BORDERBITS_contour(x)                            ((((BorderBits)(x)) & BORDERBITS_contour_MASK) >> BORDERBITS_contour_SHIFT)
#define BORDERBITS_SET_contour(x, contour)                     (x) = ((BorderBits)(x) & ~((BorderBits)BORDERBITS_contour_MASK)) | (((BorderBits)(contour)) << BORDERBITS_contour_SHIFT)
#define BORDERBITS_fixed_SHIFT                           1
#define BORDERBITS_fixed_MASK                            0x2
#define BORDERBITS_fixed(x)                              ((((BorderBits)(x)) & BORDERBITS_fixed_MASK) >> BORDERBITS_fixed_SHIFT)
#define BORDERBITS_SET_fixed(x, fixed)                       (x) = ((BorderBits)(x) & ~((BorderBits)BORDERBITS_fixed_MASK)) | (((BorderBits)(fixed)) << BORDERBITS_fixed_SHIFT)
#define BORDERBITS_sizable_SHIFT                         2
#define BORDERBITS_sizable_MASK                          0x4
#define BORDERBITS_sizable(x)                            ((((BorderBits)(x)) & BORDERBITS_sizable_MASK) >> BORDERBITS_sizable_SHIFT)
#define BORDERBITS_SET_sizable(x, sizable)                     (x) = ((BorderBits)(x) & ~((BorderBits)BORDERBITS_sizable_MASK)) | (((BorderBits)(sizable)) << BORDERBITS_sizable_SHIFT)
#define BORDERBITS_deep_SHIFT                            3
#define BORDERBITS_deep_MASK                             0x8
#define BORDERBITS_deep(x)                               ((((BorderBits)(x)) & BORDERBITS_deep_MASK) >> BORDERBITS_deep_SHIFT)
#define BORDERBITS_SET_deep(x, deep)                        (x) = ((BorderBits)(x) & ~((BorderBits)BORDERBITS_deep_MASK)) | (((BorderBits)(deep)) << BORDERBITS_deep_SHIFT)
#define BORDERBITS_bevel_SHIFT                           4
#define BORDERBITS_bevel_MASK                            0x10
#define BORDERBITS_bevel(x)                              ((((BorderBits)(x)) & BORDERBITS_bevel_MASK) >> BORDERBITS_bevel_SHIFT)
#define BORDERBITS_SET_bevel(x, bevel)                       (x) = ((BorderBits)(x) & ~((BorderBits)BORDERBITS_bevel_MASK)) | (((BorderBits)(bevel)) << BORDERBITS_bevel_SHIFT)
#define BORDERBITS_thin_SHIFT                            5
#define BORDERBITS_thin_MASK                             0x20
#define BORDERBITS_thin(x)                               ((((BorderBits)(x)) & BORDERBITS_thin_MASK) >> BORDERBITS_thin_SHIFT)
#define BORDERBITS_SET_thin(x, thin)                        (x) = ((BorderBits)(x) & ~((BorderBits)BORDERBITS_thin_MASK)) | (((BorderBits)(thin)) << BORDERBITS_thin_SHIFT)


struct C(ClipBoard)
{
   char * text;
   void * handle;
};
extern C(bool) (* ClipBoard_allocate)(C(ClipBoard) * __this, uint size);

extern void (* ClipBoard_clear)(C(ClipBoard) * __this);

extern C(bool) (* ClipBoard_load)(C(ClipBoard) * __this);

extern C(bool) (* ClipBoard_save)(C(ClipBoard) * __this);

extern void (* ClipBoard_unload)(C(ClipBoard) * __this);

extern C(Property) * PROPERTY(ClipBoard, memory);
extern char * (* ClipBoard_get_memory)(C(ClipBoard) * c);

extern C(Property) * PROPERTY(CommonControl, toolTip);
extern void (* CommonControl_set_toolTip)(C(CommonControl) c, constString value);
extern constString (* CommonControl_get_toolTip)(C(CommonControl) c);

extern C(bool) (* Cursor_load)(C(Cursor) __this, const char * name, int hotSpotX, int hotSpotY, byte * paletteShades);

extern C(Property) * PROPERTY(Cursor, systemCursor);
extern void (* Cursor_set_systemCursor)(C(Cursor) c, C(SystemCursor) value);

extern void (* Extent_addBox)(C(Extent) * __this, C(Box) * box);

extern void (* Extent_copy)(C(Extent) * __this, C(Extent) * source);

extern void (* Extent_empty)(C(Extent) * __this);

extern void (* Extent_excludeBox)(C(Extent) * __this, C(Box) * box, C(Extent) * temp);

extern void (* Extent_exclusion)(C(Extent) * __this, C(Extent) * b, C(Extent) * temp);

extern void (* Extent_intersectBox)(C(Extent) * __this, C(Box) * box);

extern void (* Extent_intersection)(C(Extent) * __this, C(Extent) * b, C(Extent) * temp, C(Extent) * temp2, C(Extent) * temp3);

extern void (* Extent_offset)(C(Extent) * __this, int x, int y);

extern void (* Extent_union)(C(Extent) * __this, C(Extent) * b, C(Extent) * temp);

extern void (* Extent_unionBox)(C(Extent) * __this, C(Box) * box, C(Extent) * temp);

extern int M_VTBLID(GuiApplication, cycle);
#define GuiApplication_cycle(__i, idle) \
   VMETHOD(CO(GuiApplication), GuiApplication, cycle, __i, C(bool), \
      C(GuiApplication) _ARG C(bool), \
      __i _ARG idle)
extern C(Method) * METHOD(GuiApplication, cycle);
extern C(Cursor) (* GuiApplication_getCursor)(C(GuiApplication) __this, C(SystemCursor) cursor);

extern C(bool) (* GuiApplication_getKeyState)(C(GuiApplication) __this, C(Key) key);

extern C(bool) (* GuiApplication_getMouseState)(C(GuiApplication) __this, C(MouseButtons) * buttons, int * x, int * y);

extern int M_VTBLID(GuiApplication, init);
#define GuiApplication_init(__i) \
   VMETHOD(CO(GuiApplication), GuiApplication, init, __i, C(bool), \
      C(GuiApplication), \
      __i)
extern C(Method) * METHOD(GuiApplication, init);
extern void (* GuiApplication_lock)(C(GuiApplication) __this);

extern void (* GuiApplication_lockEx)(C(GuiApplication) __this, int count);

extern void (* GuiApplication_pauseNetworkEvents)(C(GuiApplication) __this);

extern C(bool) (* GuiApplication_processFileNotifications)(C(GuiApplication) __this);

extern C(bool) (* GuiApplication_processInput)(C(GuiApplication) __this, C(bool) useProcessAll);

extern C(bool) (* GuiApplication_processNetworkEvents)(C(GuiApplication) __this);

extern void (* GuiApplication_resumeNetworkEvents)(C(GuiApplication) __this);

extern C(bool) (* GuiApplication_setDesktopPosition)(C(GuiApplication) __this, int x, int y, int w, int h, C(bool) moveChildren);

extern void (* GuiApplication_signalEvent)(C(GuiApplication) __this);

extern C(bool) (* GuiApplication_switchMode)(C(GuiApplication) __this, C(bool) fullScreen, const char * driverName, C(Resolution) resolution, C(PixelFormat) colorDepth, int refreshRate, const char * skinName, C(bool) fallBack);

extern int M_VTBLID(GuiApplication, terminate);
#define GuiApplication_terminate(__i) \
   VMETHOD(CO(GuiApplication), GuiApplication, terminate, __i, void, \
      C(GuiApplication), \
      __i)
extern C(Method) * METHOD(GuiApplication, terminate);
extern void (* GuiApplication_unlock)(C(GuiApplication) __this);

extern int (* GuiApplication_unlockEx)(C(GuiApplication) __this);

extern void (* GuiApplication_updateDisplay)(C(GuiApplication) __this);

extern void (* GuiApplication_wait)(C(GuiApplication) __this);

extern void (* GuiApplication_waitEvent)(C(GuiApplication) __this);

extern void (* GuiApplication_waitNetworkEvent)(C(GuiApplication) __this);

extern C(Property) * PROPERTY(GuiApplication, appName);
extern void (* GuiApplication_set_appName)(C(GuiApplication) g, const char * value);
extern const char * (* GuiApplication_get_appName)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, semaphore);
extern C(Semaphore) * (* GuiApplication_get_semaphore)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, alwaysEmptyInput);
extern void (* GuiApplication_set_alwaysEmptyInput)(C(GuiApplication) g, C(bool) value);
extern C(bool) (* GuiApplication_get_alwaysEmptyInput)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, fullScreen);
extern void (* GuiApplication_set_fullScreen)(C(GuiApplication) g, C(bool) value);
extern C(bool) (* GuiApplication_get_fullScreen)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, driver);
extern void (* GuiApplication_set_driver)(C(GuiApplication) g, const char * value);
extern const char * (* GuiApplication_get_driver)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, resolution);
extern void (* GuiApplication_set_resolution)(C(GuiApplication) g, C(Resolution) value);
extern C(Resolution) (* GuiApplication_get_resolution)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, pixelFormat);
extern void (* GuiApplication_set_pixelFormat)(C(GuiApplication) g, C(PixelFormat) value);
extern C(PixelFormat) (* GuiApplication_get_pixelFormat)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, refreshRate);
extern void (* GuiApplication_set_refreshRate)(C(GuiApplication) g, int value);
extern int (* GuiApplication_get_refreshRate)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, skin);
extern void (* GuiApplication_set_skin)(C(GuiApplication) g, const char * value);
extern const char * (* GuiApplication_get_skin)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, textMode);
extern void (* GuiApplication_set_textMode)(C(GuiApplication) g, C(bool) value);
extern C(bool) (* GuiApplication_get_textMode)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, desktop);
extern C(Window) (* GuiApplication_get_desktop)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, drivers);
extern const char ** (* GuiApplication_get_drivers)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, skins);
extern const char ** (* GuiApplication_get_skins)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, currentSkin);
extern subclass(Skin) (* GuiApplication_get_currentSkin)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, numDrivers);
extern int (* GuiApplication_get_numDrivers)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, numSkins);
extern int (* GuiApplication_get_numSkins)(C(GuiApplication) g);

extern C(Property) * PROPERTY(GuiApplication, timerResolution);
extern void (* GuiApplication_set_timerResolution)(C(GuiApplication) g, uint value);

extern C(Property) * PROPERTY(GuiApplication, acquiredWindow);
extern C(Window) (* GuiApplication_get_acquiredWindow)(C(GuiApplication) g);

extern int M_VTBLID(Interface, acquireInput);
#define Interface_acquireInput(__i, window, state) \
   VMETHOD(CO(Interface), Interface, acquireInput, __i, C(bool), \
      C(Window) _ARG C(bool), \
      window _ARG state)
extern C(Method) * METHOD(Interface, acquireInput);
extern int M_VTBLID(Interface, activateRootWindow);
#define Interface_activateRootWindow(__i, window) \
   VMETHOD(CO(Interface), Interface, activateRootWindow, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, activateRootWindow);
extern int M_VTBLID(Interface, allocateClipboard);
#define Interface_allocateClipboard(__i, clipBoard, size) \
   VMETHOD(CO(Interface), Interface, allocateClipboard, __i, C(bool), \
      C(ClipBoard) * _ARG uint, \
      clipBoard _ARG size)
extern C(Method) * METHOD(Interface, allocateClipboard);
extern int M_VTBLID(Interface, clearClipboard);
#define Interface_clearClipboard(__i) \
   VMETHOD(CO(Interface), Interface, clearClipboard, __i, void, \
      , \
      )
extern C(Method) * METHOD(Interface, clearClipboard);
extern int M_VTBLID(Interface, createRootWindow);
#define Interface_createRootWindow(__i, window) \
   VMETHOD(CO(Interface), Interface, createRootWindow, __i, void *, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, createRootWindow);
extern int M_VTBLID(Interface, destroyRootWindow);
#define Interface_destroyRootWindow(__i, window) \
   VMETHOD(CO(Interface), Interface, destroyRootWindow, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, destroyRootWindow);
extern int M_VTBLID(Interface, ensureFullScreen);
#define Interface_ensureFullScreen(__i, fullScreen) \
   VMETHOD(CO(Interface), Interface, ensureFullScreen, __i, void, \
      C(bool) *, \
      fullScreen)
extern C(Method) * METHOD(Interface, ensureFullScreen);
extern int M_VTBLID(Interface, flashRootWindow);
#define Interface_flashRootWindow(__i, window) \
   VMETHOD(CO(Interface), Interface, flashRootWindow, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, flashRootWindow);
extern int M_VTBLID(Interface, getCurrentMode);
#define Interface_getCurrentMode(__i, fullScreen, resolution, colorDepth, refreshRate) \
   VMETHOD(CO(Interface), Interface, getCurrentMode, __i, void, \
      C(bool) * _ARG C(Resolution) * _ARG C(PixelFormat) * _ARG int *, \
      fullScreen _ARG resolution _ARG colorDepth _ARG refreshRate)
extern C(Method) * METHOD(Interface, getCurrentMode);
extern C(Key) (* Interface_getExtendedKey)(C(Key) key);

extern int M_VTBLID(Interface, getJoystickState);
#define Interface_getJoystickState(__i, device, joystick) \
   VMETHOD(CO(Interface), Interface, getJoystickState, __i, C(bool), \
      int _ARG C(Joystick) *, \
      device _ARG joystick)
extern C(Method) * METHOD(Interface, getJoystickState);
extern int M_VTBLID(Interface, getKeyState);
#define Interface_getKeyState(__i, key) \
   VMETHOD(CO(Interface), Interface, getKeyState, __i, C(bool), \
      C(Key), \
      key)
extern C(Method) * METHOD(Interface, getKeyState);
extern int M_VTBLID(Interface, getMousePosition);
#define Interface_getMousePosition(__i, x, y) \
   VMETHOD(CO(Interface), Interface, getMousePosition, __i, void, \
      int * _ARG int *, \
      x _ARG y)
extern C(Method) * METHOD(Interface, getMousePosition);
extern int M_VTBLID(Interface, getMouseState);
#define Interface_getMouseState(__i, buttons, x, y) \
   VMETHOD(CO(Interface), Interface, getMouseState, __i, C(bool), \
      C(MouseButtons) * _ARG int * _ARG int *, \
      buttons _ARG x _ARG y)
extern C(Method) * METHOD(Interface, getMouseState);
extern int M_VTBLID(Interface, getScreenArea);
#define Interface_getScreenArea(__i, window, box) \
   VMETHOD(CO(Interface), Interface, getScreenArea, __i, void, \
      C(Window) _ARG C(Box) *, \
      window _ARG box)
extern C(Method) * METHOD(Interface, getScreenArea);
extern int M_VTBLID(Interface, graphicsDrivers);
#define Interface_graphicsDrivers(__i, numDrivers) \
   VMETHOD(CO(Interface), Interface, graphicsDrivers, __i, const char **, \
      int *, \
      numDrivers)
extern C(Method) * METHOD(Interface, graphicsDrivers);
extern int M_VTBLID(Interface, initialize);
#define Interface_initialize(__i) \
   VMETHOD(CO(Interface), Interface, initialize, __i, C(bool), \
      , \
      )
extern C(Method) * METHOD(Interface, initialize);
extern int M_VTBLID(Interface, loadClipboard);
#define Interface_loadClipboard(__i, clipBoard) \
   VMETHOD(CO(Interface), Interface, loadClipboard, __i, C(bool), \
      C(ClipBoard) *, \
      clipBoard)
extern C(Method) * METHOD(Interface, loadClipboard);
extern int M_VTBLID(Interface, lock);
#define Interface_lock(__i, window) \
   VMETHOD(CO(Interface), Interface, lock, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, lock);
extern int M_VTBLID(Interface, offsetWindow);
#define Interface_offsetWindow(__i, window, x, y) \
   VMETHOD(CO(Interface), Interface, offsetWindow, __i, void, \
      C(Window) _ARG int * _ARG int *, \
      window _ARG x _ARG y)
extern C(Method) * METHOD(Interface, offsetWindow);
extern int M_VTBLID(Interface, orderRootWindow);
#define Interface_orderRootWindow(__i, window, topMost) \
   VMETHOD(CO(Interface), Interface, orderRootWindow, __i, void, \
      C(Window) _ARG C(bool), \
      window _ARG topMost)
extern C(Method) * METHOD(Interface, orderRootWindow);
extern int M_VTBLID(Interface, positionRootWindow);
#define Interface_positionRootWindow(__i, window, x, y, w, h, move, resize) \
   VMETHOD(CO(Interface), Interface, positionRootWindow, __i, void, \
      C(Window) _ARG int _ARG int _ARG int _ARG int _ARG C(bool) _ARG C(bool), \
      window _ARG x _ARG y _ARG w _ARG h _ARG move _ARG resize)
extern C(Method) * METHOD(Interface, positionRootWindow);
extern int M_VTBLID(Interface, processInput);
#define Interface_processInput(__i, processAll) \
   VMETHOD(CO(Interface), Interface, processInput, __i, C(bool), \
      C(bool), \
      processAll)
extern C(Method) * METHOD(Interface, processInput);
extern int M_VTBLID(Interface, saveClipboard);
#define Interface_saveClipboard(__i, clipBoard) \
   VMETHOD(CO(Interface), Interface, saveClipboard, __i, C(bool), \
      C(ClipBoard) *, \
      clipBoard)
extern C(Method) * METHOD(Interface, saveClipboard);
extern int M_VTBLID(Interface, screenMode);
#define Interface_screenMode(__i, fullScreen, resolution, colorDepth, refreshRate, textMode) \
   VMETHOD(CO(Interface), Interface, screenMode, __i, C(bool), \
      C(bool) _ARG C(Resolution) _ARG C(PixelFormat) _ARG int _ARG C(bool) *, \
      fullScreen _ARG resolution _ARG colorDepth _ARG refreshRate _ARG textMode)
extern C(Method) * METHOD(Interface, screenMode);
extern int M_VTBLID(Interface, setCaret);
#define Interface_setCaret(__i, caretX, caretY, size) \
   VMETHOD(CO(Interface), Interface, setCaret, __i, void, \
      int _ARG int _ARG int, \
      caretX _ARG caretY _ARG size)
extern C(Method) * METHOD(Interface, setCaret);
extern int M_VTBLID(Interface, setIcon);
#define Interface_setIcon(__i, window, icon) \
   VMETHOD(CO(Interface), Interface, setIcon, __i, C(bool), \
      C(Window) _ARG C(BitmapResource), \
      window _ARG icon)
extern C(Method) * METHOD(Interface, setIcon);
extern int M_VTBLID(Interface, setMouseCapture);
#define Interface_setMouseCapture(__i, window) \
   VMETHOD(CO(Interface), Interface, setMouseCapture, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, setMouseCapture);
extern int M_VTBLID(Interface, setMouseCursor);
#define Interface_setMouseCursor(__i, window, cursor) \
   VMETHOD(CO(Interface), Interface, setMouseCursor, __i, void, \
      C(Window) _ARG C(SystemCursor), \
      window _ARG cursor)
extern C(Method) * METHOD(Interface, setMouseCursor);
extern int M_VTBLID(Interface, setMousePosition);
#define Interface_setMousePosition(__i, x, y) \
   VMETHOD(CO(Interface), Interface, setMousePosition, __i, void, \
      int _ARG int, \
      x _ARG y)
extern C(Method) * METHOD(Interface, setMousePosition);
extern int M_VTBLID(Interface, setMouseRange);
#define Interface_setMouseRange(__i, window, box) \
   VMETHOD(CO(Interface), Interface, setMouseRange, __i, void, \
      C(Window) _ARG C(Box) *, \
      window _ARG box)
extern C(Method) * METHOD(Interface, setMouseRange);
extern int M_VTBLID(Interface, setRootWindowCaption);
#define Interface_setRootWindowCaption(__i, window, name) \
   VMETHOD(CO(Interface), Interface, setRootWindowCaption, __i, void, \
      C(Window) _ARG const char *, \
      window _ARG name)
extern C(Method) * METHOD(Interface, setRootWindowCaption);
extern int M_VTBLID(Interface, setRootWindowColor);
#define Interface_setRootWindowColor(__i, window) \
   VMETHOD(CO(Interface), Interface, setRootWindowColor, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, setRootWindowColor);
extern int M_VTBLID(Interface, setRootWindowState);
#define Interface_setRootWindowState(__i, window, state, visible) \
   VMETHOD(CO(Interface), Interface, setRootWindowState, __i, void, \
      C(Window) _ARG C(WindowState) _ARG C(bool), \
      window _ARG state _ARG visible)
extern C(Method) * METHOD(Interface, setRootWindowState);
extern int M_VTBLID(Interface, setTimerResolution);
#define Interface_setTimerResolution(__i, hertz) \
   VMETHOD(CO(Interface), Interface, setTimerResolution, __i, void, \
      uint, \
      hertz)
extern C(Method) * METHOD(Interface, setTimerResolution);
extern int M_VTBLID(Interface, startMoving);
#define Interface_startMoving(__i, window, x, y, fromKeyBoard) \
   VMETHOD(CO(Interface), Interface, startMoving, __i, void, \
      C(Window) _ARG int _ARG int _ARG C(bool), \
      window _ARG x _ARG y _ARG fromKeyBoard)
extern C(Method) * METHOD(Interface, startMoving);
extern int M_VTBLID(Interface, stopMoving);
#define Interface_stopMoving(__i, window) \
   VMETHOD(CO(Interface), Interface, stopMoving, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, stopMoving);
extern int M_VTBLID(Interface, terminate);
#define Interface_terminate(__i) \
   VMETHOD(CO(Interface), Interface, terminate, __i, void, \
      , \
      )
extern C(Method) * METHOD(Interface, terminate);
extern char (* Interface_translateKey)(C(Key) key, C(bool) shift);

extern int M_VTBLID(Interface, unloadClipboard);
#define Interface_unloadClipboard(__i, clipBoard) \
   VMETHOD(CO(Interface), Interface, unloadClipboard, __i, void, \
      C(ClipBoard) *, \
      clipBoard)
extern C(Method) * METHOD(Interface, unloadClipboard);
extern int M_VTBLID(Interface, unlock);
#define Interface_unlock(__i, window) \
   VMETHOD(CO(Interface), Interface, unlock, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, unlock);
extern int M_VTBLID(Interface, updateRootWindow);
#define Interface_updateRootWindow(__i, window) \
   VMETHOD(CO(Interface), Interface, updateRootWindow, __i, void, \
      C(Window), \
      window)
extern C(Method) * METHOD(Interface, updateRootWindow);
extern int M_VTBLID(Interface, wait);
#define Interface_wait(__i) \
   VMETHOD(CO(Interface), Interface, wait, __i, void, \
      , \
      )
extern C(Method) * METHOD(Interface, wait);
extern void (* Interface_writeKeyedText)(C(Surface) surface, int x, int y, const char * text, C(Key) hotKey);

extern void (* Interface_writeKeyedTextDisabled)(C(Surface) surface, int x, int y, const char * text, C(Key) hotKey, C(bool) disabled);

struct C(Joystick)
{
   int x;
   int y;
   int z;
   int rx;
   int ry;
   int rz;
   uint buttons;
};
#define KEY_code_SHIFT                                   0
#define KEY_code_MASK                                    0xFFFF
#define KEY_code(x)                                      ((((Key)(x)) & KEY_code_MASK) >> KEY_code_SHIFT)
#define KEY_SET_code(x, code)                               (x) = ((Key)(x) & ~((Key)KEY_code_MASK)) | (((Key)(code)) << KEY_code_SHIFT)
#define KEY_shift_SHIFT                                  16
#define KEY_shift_MASK                                   0x10000
#define KEY_shift(x)                                     ((((Key)(x)) & KEY_shift_MASK) >> KEY_shift_SHIFT)
#define KEY_SET_shift(x, shift)                              (x) = ((Key)(x) & ~((Key)KEY_shift_MASK)) | (((Key)(shift)) << KEY_shift_SHIFT)
#define KEY_ctrl_SHIFT                                   17
#define KEY_ctrl_MASK                                    0x20000
#define KEY_ctrl(x)                                      ((((Key)(x)) & KEY_ctrl_MASK) >> KEY_ctrl_SHIFT)
#define KEY_SET_ctrl(x, ctrl)                               (x) = ((Key)(x) & ~((Key)KEY_ctrl_MASK)) | (((Key)(ctrl)) << KEY_ctrl_SHIFT)
#define KEY_alt_SHIFT                                    18
#define KEY_alt_MASK                                     0x40000
#define KEY_alt(x)                                       ((((Key)(x)) & KEY_alt_MASK) >> KEY_alt_SHIFT)
#define KEY_SET_alt(x, alt)                                (x) = ((Key)(x) & ~((Key)KEY_alt_MASK)) | (((Key)(alt)) << KEY_alt_SHIFT)
#define KEY_cmd_SHIFT                                    19
#define KEY_cmd_MASK                                     0x80000
#define KEY_cmd(x)                                       ((((Key)(x)) & KEY_cmd_MASK) >> KEY_cmd_SHIFT)
#define KEY_SET_cmd(x, cmd)                                (x) = ((Key)(x) & ~((Key)KEY_cmd_MASK)) | (((Key)(cmd)) << KEY_cmd_SHIFT)
#define KEY_modifiers_SHIFT                              16
#define KEY_modifiers_MASK                               0xFFFF0000
#define KEY_modifiers(x)                                 ((((Key)(x)) & KEY_modifiers_MASK) >> KEY_modifiers_SHIFT)
#define KEY_SET_modifiers(x, modifiers)                          (x) = ((Key)(x) & ~((Key)KEY_modifiers_MASK)) | (((Key)(modifiers)) << KEY_modifiers_SHIFT)


extern C(Property) * PROPERTY(Key, SmartKey);
extern C(SmartKey) (* Key_to_SmartKey)(C(Key) key);

extern C(Property) * PROPERTY(MiddleAnchorValue, MinMaxValue);
extern void (* MiddleAnchorValue_from_MinMaxValue)(C(MiddleAnchorValue) m, C(MinMaxValue) value);
extern C(MinMaxValue) (* MiddleAnchorValue_to_MinMaxValue)(C(MiddleAnchorValue) m);

extern C(Property) * PROPERTY(MiddleAnchorValue, int);
extern void (* MiddleAnchorValue_from_int)(C(MiddleAnchorValue) m, int value);
extern int (* MiddleAnchorValue_to_int)(C(MiddleAnchorValue) m);

extern C(Property) * PROPERTY(MiddleAnchorValue, double);
extern void (* MiddleAnchorValue_from_double)(C(MiddleAnchorValue) m, double value);
extern double (* MiddleAnchorValue_to_double)(C(MiddleAnchorValue) m);

#define MODIFIERS_shift_SHIFT                            0
#define MODIFIERS_shift_MASK                             0x1
#define MODIFIERS_shift(x)                               ((((Modifiers)(x)) & MODIFIERS_shift_MASK) >> MODIFIERS_shift_SHIFT)
#define MODIFIERS_SET_shift(x, shift)                        (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_shift_MASK)) | (((Modifiers)(shift)) << MODIFIERS_shift_SHIFT)
#define MODIFIERS_ctrl_SHIFT                             1
#define MODIFIERS_ctrl_MASK                              0x2
#define MODIFIERS_ctrl(x)                                ((((Modifiers)(x)) & MODIFIERS_ctrl_MASK) >> MODIFIERS_ctrl_SHIFT)
#define MODIFIERS_SET_ctrl(x, ctrl)                         (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_ctrl_MASK)) | (((Modifiers)(ctrl)) << MODIFIERS_ctrl_SHIFT)
#define MODIFIERS_alt_SHIFT                              2
#define MODIFIERS_alt_MASK                               0x4
#define MODIFIERS_alt(x)                                 ((((Modifiers)(x)) & MODIFIERS_alt_MASK) >> MODIFIERS_alt_SHIFT)
#define MODIFIERS_SET_alt(x, alt)                          (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_alt_MASK)) | (((Modifiers)(alt)) << MODIFIERS_alt_SHIFT)
#define MODIFIERS_cmd_SHIFT                              3
#define MODIFIERS_cmd_MASK                               0x8
#define MODIFIERS_cmd(x)                                 ((((Modifiers)(x)) & MODIFIERS_cmd_MASK) >> MODIFIERS_cmd_SHIFT)
#define MODIFIERS_SET_cmd(x, cmd)                          (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_cmd_MASK)) | (((Modifiers)(cmd)) << MODIFIERS_cmd_SHIFT)
#define MODIFIERS_left_SHIFT                             4
#define MODIFIERS_left_MASK                              0x10
#define MODIFIERS_left(x)                                ((((Modifiers)(x)) & MODIFIERS_left_MASK) >> MODIFIERS_left_SHIFT)
#define MODIFIERS_SET_left(x, left)                         (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_left_MASK)) | (((Modifiers)(left)) << MODIFIERS_left_SHIFT)
#define MODIFIERS_middle_SHIFT                           5
#define MODIFIERS_middle_MASK                            0x20
#define MODIFIERS_middle(x)                              ((((Modifiers)(x)) & MODIFIERS_middle_MASK) >> MODIFIERS_middle_SHIFT)
#define MODIFIERS_SET_middle(x, middle)                       (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_middle_MASK)) | (((Modifiers)(middle)) << MODIFIERS_middle_SHIFT)
#define MODIFIERS_right_SHIFT                            6
#define MODIFIERS_right_MASK                             0x40
#define MODIFIERS_right(x)                               ((((Modifiers)(x)) & MODIFIERS_right_MASK) >> MODIFIERS_right_SHIFT)
#define MODIFIERS_SET_right(x, right)                        (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_right_MASK)) | (((Modifiers)(right)) << MODIFIERS_right_SHIFT)
#define MODIFIERS_isActivate_SHIFT                       7
#define MODIFIERS_isActivate_MASK                        0x80
#define MODIFIERS_isActivate(x)                          ((((Modifiers)(x)) & MODIFIERS_isActivate_MASK) >> MODIFIERS_isActivate_SHIFT)
#define MODIFIERS_SET_isActivate(x, isActivate)                   (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_isActivate_MASK)) | (((Modifiers)(isActivate)) << MODIFIERS_isActivate_SHIFT)
#define MODIFIERS_isSideEffect_SHIFT                     8
#define MODIFIERS_isSideEffect_MASK                      0x100
#define MODIFIERS_isSideEffect(x)                        ((((Modifiers)(x)) & MODIFIERS_isSideEffect_MASK) >> MODIFIERS_isSideEffect_SHIFT)
#define MODIFIERS_SET_isSideEffect(x, isSideEffect)                 (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_isSideEffect_MASK)) | (((Modifiers)(isSideEffect)) << MODIFIERS_isSideEffect_SHIFT)
#define MODIFIERS_closingDropDown_SHIFT                  9
#define MODIFIERS_closingDropDown_MASK                   0x200
#define MODIFIERS_closingDropDown(x)                     ((((Modifiers)(x)) & MODIFIERS_closingDropDown_MASK) >> MODIFIERS_closingDropDown_SHIFT)
#define MODIFIERS_SET_closingDropDown(x, closingDropDown)              (x) = ((Modifiers)(x) & ~((Modifiers)MODIFIERS_closingDropDown_MASK)) | (((Modifiers)(closingDropDown)) << MODIFIERS_closingDropDown_SHIFT)


#define MOUSEBUTTONS_left_SHIFT                          0
#define MOUSEBUTTONS_left_MASK                           0x1
#define MOUSEBUTTONS_left(x)                             ((((MouseButtons)(x)) & MOUSEBUTTONS_left_MASK) >> MOUSEBUTTONS_left_SHIFT)
#define MOUSEBUTTONS_SET_left(x, left)                      (x) = ((MouseButtons)(x) & ~((MouseButtons)MOUSEBUTTONS_left_MASK)) | (((MouseButtons)(left)) << MOUSEBUTTONS_left_SHIFT)
#define MOUSEBUTTONS_right_SHIFT                         1
#define MOUSEBUTTONS_right_MASK                          0x2
#define MOUSEBUTTONS_right(x)                            ((((MouseButtons)(x)) & MOUSEBUTTONS_right_MASK) >> MOUSEBUTTONS_right_SHIFT)
#define MOUSEBUTTONS_SET_right(x, right)                     (x) = ((MouseButtons)(x) & ~((MouseButtons)MOUSEBUTTONS_right_MASK)) | (((MouseButtons)(right)) << MOUSEBUTTONS_right_SHIFT)
#define MOUSEBUTTONS_middle_SHIFT                        2
#define MOUSEBUTTONS_middle_MASK                         0x4
#define MOUSEBUTTONS_middle(x)                           ((((MouseButtons)(x)) & MOUSEBUTTONS_middle_MASK) >> MOUSEBUTTONS_middle_SHIFT)
#define MOUSEBUTTONS_SET_middle(x, middle)                    (x) = ((MouseButtons)(x) & ~((MouseButtons)MOUSEBUTTONS_middle_MASK)) | (((MouseButtons)(middle)) << MOUSEBUTTONS_middle_SHIFT)
#define MOUSEBUTTONS(left, right, middle)                            (((((MouseButtons)(left)) << MOUSEBUTTONS_left_SHIFT) | ((MouseButtons)(right)) << MOUSEBUTTONS_right_SHIFT) | ((MouseButtons)(middle)) << MOUSEBUTTONS_middle_SHIFT)


extern int M_VTBLID(Skin, captionFont);
#define Skin_captionFont(__i) \
   VMETHOD(CO(Skin), Skin, captionFont, __i, C(FontResource), \
      , \
      )
extern C(Method) * METHOD(Skin, captionFont);
extern int M_VTBLID(Skin, cursorsBitmaps);
#define Skin_cursorsBitmaps(__i, id, hotSpotX, hotSpotY, paletteShades) \
   VMETHOD(CO(Skin), Skin, cursorsBitmaps, __i, const char *, \
      uint _ARG int * _ARG int * _ARG byte **, \
      id _ARG hotSpotX _ARG hotSpotY _ARG paletteShades)
extern C(Method) * METHOD(Skin, cursorsBitmaps);
extern int M_VTBLID(Skin, getBitmap);
#define Skin_getBitmap(__i, ap1) \
   VMETHOD(CO(Skin), Skin, getBitmap, __i, C(BitmapResource), \
      C(SkinBitmap), \
      ap1)
extern C(Method) * METHOD(Skin, getBitmap);
extern int M_VTBLID(Skin, getDecorationsSize);
#define Skin_getDecorationsSize(__i, ap1, ap2, ap3) \
   VMETHOD(CO(Skin), Skin, getDecorationsSize, __i, void, \
      C(Window) _ARG C(MinMaxValue) * _ARG C(MinMaxValue) *, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(Skin, getDecorationsSize);
extern int M_VTBLID(Skin, horizontalSBH);
#define Skin_horizontalSBH(__i) \
   VMETHOD(CO(Skin), Skin, horizontalSBH, __i, int, \
      , \
      )
extern C(Method) * METHOD(Skin, horizontalSBH);
extern int M_VTBLID(Skin, isMouseMoving);
#define Skin_isMouseMoving(__i, ap1, ap2, ap3, ap4, ap5) \
   VMETHOD(CO(Skin), Skin, isMouseMoving, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG int _ARG int, \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4 _ARG ap5)
extern C(Method) * METHOD(Skin, isMouseMoving);
extern int M_VTBLID(Skin, isMouseResizing);
#define Skin_isMouseResizing(__i, ap1, ap2, ap3, ap4, ap5, ap6, ap7, ap8, ap9) \
   VMETHOD(CO(Skin), Skin, isMouseResizing, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG int _ARG int _ARG C(bool) * _ARG C(bool) * _ARG C(bool) * _ARG C(bool) *, \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4 _ARG ap5 _ARG ap6 _ARG ap7 _ARG ap8 _ARG ap9)
extern C(Method) * METHOD(Skin, isMouseResizing);
extern int M_VTBLID(Skin, setWindowArea);
#define Skin_setWindowArea(__i, ap1, ap2, ap3, ap4, ap5, ap6, ap7) \
   VMETHOD(CO(Skin), Skin, setWindowArea, __i, void, \
      C(Window) _ARG int * _ARG int * _ARG C(MinMaxValue) * _ARG C(MinMaxValue) * _ARG C(MinMaxValue) * _ARG C(MinMaxValue) *, \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4 _ARG ap5 _ARG ap6 _ARG ap7)
extern C(Method) * METHOD(Skin, setWindowArea);
extern int M_VTBLID(Skin, setWindowMinimum);
#define Skin_setWindowMinimum(__i, ap1, ap2, ap3) \
   VMETHOD(CO(Skin), Skin, setWindowMinimum, __i, void, \
      C(Window) _ARG C(MinMaxValue) * _ARG C(MinMaxValue) *, \
      ap1 _ARG ap2 _ARG ap3)
extern C(Method) * METHOD(Skin, setWindowMinimum);
extern int M_VTBLID(Skin, showDecorations);
#define Skin_showDecorations(__i, ap1, ap2, ap3, ap4, ap5, ap6) \
   VMETHOD(CO(Skin), Skin, showDecorations, __i, void, \
      void * _ARG C(Surface) _ARG C(Window) _ARG const char * _ARG C(bool) _ARG C(bool), \
      ap1 _ARG ap2 _ARG ap3 _ARG ap4 _ARG ap5 _ARG ap6)
extern C(Method) * METHOD(Skin, showDecorations);
extern int M_VTBLID(Skin, systemFont);
#define Skin_systemFont(__i) \
   VMETHOD(CO(Skin), Skin, systemFont, __i, C(FontResource), \
      , \
      )
extern C(Method) * METHOD(Skin, systemFont);
extern int M_VTBLID(Skin, updateNonClient);
#define Skin_updateNonClient(__i, ap1) \
   VMETHOD(CO(Skin), Skin, updateNonClient, __i, void, \
      void *, \
      ap1)
extern C(Method) * METHOD(Skin, updateNonClient);
extern int M_VTBLID(Skin, verticalSBW);
#define Skin_verticalSBW(__i) \
   VMETHOD(CO(Skin), Skin, verticalSBW, __i, int, \
      , \
      )
extern C(Method) * METHOD(Skin, verticalSBW);
#define SMARTKEY_code_SHIFT                              0
#define SMARTKEY_code_MASK                               0xFFFF
#define SMARTKEY_code(x)                                 ((((SmartKey)(x)) & SMARTKEY_code_MASK) >> SMARTKEY_code_SHIFT)
#define SMARTKEY_SET_code(x, code)                          (x) = ((SmartKey)(x) & ~((SmartKey)SMARTKEY_code_MASK)) | (((SmartKey)(code)) << SMARTKEY_code_SHIFT)
#define SMARTKEY_shift_SHIFT                             16
#define SMARTKEY_shift_MASK                              0x10000
#define SMARTKEY_shift(x)                                ((((SmartKey)(x)) & SMARTKEY_shift_MASK) >> SMARTKEY_shift_SHIFT)
#define SMARTKEY_SET_shift(x, shift)                         (x) = ((SmartKey)(x) & ~((SmartKey)SMARTKEY_shift_MASK)) | (((SmartKey)(shift)) << SMARTKEY_shift_SHIFT)
#define SMARTKEY_ctrl_SHIFT                              17
#define SMARTKEY_ctrl_MASK                               0x20000
#define SMARTKEY_ctrl(x)                                 ((((SmartKey)(x)) & SMARTKEY_ctrl_MASK) >> SMARTKEY_ctrl_SHIFT)
#define SMARTKEY_SET_ctrl(x, ctrl)                          (x) = ((SmartKey)(x) & ~((SmartKey)SMARTKEY_ctrl_MASK)) | (((SmartKey)(ctrl)) << SMARTKEY_ctrl_SHIFT)
#define SMARTKEY_alt_SHIFT                               18
#define SMARTKEY_alt_MASK                                0x40000
#define SMARTKEY_alt(x)                                  ((((SmartKey)(x)) & SMARTKEY_alt_MASK) >> SMARTKEY_alt_SHIFT)
#define SMARTKEY_SET_alt(x, alt)                           (x) = ((SmartKey)(x) & ~((SmartKey)SMARTKEY_alt_MASK)) | (((SmartKey)(alt)) << SMARTKEY_alt_SHIFT)
#define SMARTKEY_modifiers_SHIFT                         16
#define SMARTKEY_modifiers_MASK                          0xFFFF0000
#define SMARTKEY_modifiers(x)                            ((((SmartKey)(x)) & SMARTKEY_modifiers_MASK) >> SMARTKEY_modifiers_SHIFT)
#define SMARTKEY_SET_modifiers(x, modifiers)                     (x) = ((SmartKey)(x) & ~((SmartKey)SMARTKEY_modifiers_MASK)) | (((SmartKey)(modifiers)) << SMARTKEY_modifiers_SHIFT)


extern int M_VTBLID(Timer, delayExpired);
#define Timer_delayExpired(__i, __t) \
   VMETHOD(CO(Timer), Timer, delayExpired, __i, C(bool), \
      C(Class) *, \
      __t)
extern C(Method) * METHOD(Timer, delayExpired);
extern void (* Timer_start)(C(Timer) __this);

extern void (* Timer_stop)(C(Timer) __this);

extern C(Property) * PROPERTY(Timer, userData);
extern void (* Timer_set_userData)(C(Timer) t, void * value);
extern void * (* Timer_get_userData)(C(Timer) t);

extern C(Property) * PROPERTY(Timer, delay);
extern void (* Timer_set_delay)(C(Timer) t, C(Time) value);
extern C(Time) (* Timer_get_delay)(C(Timer) t);

extern C(Property) * PROPERTY(Timer, started);
extern void (* Timer_set_started)(C(Timer) t, C(bool) value);
extern C(bool) (* Timer_get_started)(C(Timer) t);

struct C(TouchPointerInfo)
{
   int id;
   C(Point) point;
   float size;
   float pressure;
};
extern C(bool) (* Window_acquireInput)(C(Window) __this, C(bool) acquired);

extern void (* Window_activate)(C(Window) __this);

extern void (* Window_addResource)(C(Window) __this, C(Resource) resource);

extern C(bool) (* Window_buttonCloseDialog)(C(Window) __this, C(Button) button, int x, int y, C(Modifiers) mods);

extern C(bool) (* Window_capture)(C(Window) __this);

extern C(bool) (* Window_closeConfirmation)(C(Window) __this, C(bool) parentClosing);

extern C(bool) (* Window_create)(C(Window) __this);

extern C(bool) (* Window_cycleChildren)(C(Window) __this, C(bool) backward, C(bool) clientOnly, C(bool) tabCycleOnly, C(bool) cycleParents);

extern void (* Window_deactivate)(C(Window) __this);

extern C(bool) (* Window_destroy)(C(Window) __this, int64 code);

extern C(DialogResult) (* Window_doModal)(C(Window) __this);

extern C(DialogResult) (* Window_doModalEnd)(C(Window) __this);

extern C(bool) (* Window_doModalLoop)(C(Window) __this);

extern void (* Window_doModalStart)(C(Window) __this);

extern void (* Window_externalPosition)(C(Window) __this, int x, int y, int w, int h);

extern void (* Window_flash)(C(Window) __this);

extern void (* Window_freeMouseRange)();

extern void (* Window_getCaretPosition)(C(Window) __this, C(Point) * caretPos);

extern int (* Window_getCaretSize)(C(Window) __this);

extern int M_VTBLID(Window, getDecorationsSize);
#define Window_getDecorationsSize(__i, w, h) \
   VMETHOD(CO(Window), Window, getDecorationsSize, __i, void, \
      C(Window) _ARG C(MinMaxValue) * _ARG C(MinMaxValue) *, \
      __i _ARG w _ARG h)
extern C(Method) * METHOD(Window, getDecorationsSize);
extern C(BitmapResource) (* Window_getIcon)(C(Window) __this, C(SkinBitmap) iconID);

extern void (* Window_getMousePosition)(C(Window) __this, int * x, int * y);

extern void (* Window_getNCMousePosition)(C(Window) __this, int * x, int * y);

extern C(bool) (* Window_grab)(C(Window) __this, C(Bitmap) bitmap, C(Box) * box, C(bool) decorations);

extern int M_VTBLID(Window, isInside);
#define Window_isInside(__i, x, y) \
   VMETHOD(CO(Window), Window, isInside, __i, C(bool), \
      C(Window) _ARG int _ARG int, \
      __i _ARG x _ARG y)
extern C(Method) * METHOD(Window, isInside);
extern int M_VTBLID(Window, isMouseMoving);
#define Window_isMouseMoving(__i, x, y, w, h) \
   VMETHOD(CO(Window), Window, isMouseMoving, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG int _ARG int, \
      __i _ARG x _ARG y _ARG w _ARG h)
extern C(Method) * METHOD(Window, isMouseMoving);
extern int M_VTBLID(Window, isMouseResizing);
#define Window_isMouseResizing(__i, x, y, w, h, resizeX, resizeY, resizeEndX, resizeEndY) \
   VMETHOD(CO(Window), Window, isMouseResizing, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG int _ARG int _ARG C(bool) * _ARG C(bool) * _ARG C(bool) * _ARG C(bool) *, \
      __i _ARG x _ARG y _ARG w _ARG h _ARG resizeX _ARG resizeY _ARG resizeEndX _ARG resizeEndY)
extern C(Method) * METHOD(Window, isMouseResizing);
extern int M_VTBLID(Window, isOpaque);
#define Window_isOpaque(__i) \
   VMETHOD(CO(Window), Window, isOpaque, __i, C(bool), \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, isOpaque);
extern void (* Window_makeActive)(C(Window) __this);

extern C(bool) (* Window_menuFileClose)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuFileExit)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuFileSave)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuFileSaveAll)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuFileSaveAs)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowArrangeIcons)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowCascade)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowClose)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowCloseAll)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowMaximize)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowMinimize)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowMove)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowNext)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowPrevious)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowRestore)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowSelectWindow)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowSize)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowStayOnTop)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowTileHorz)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowTileVert)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(bool) (* Window_menuWindowWindows)(C(Window) __this, C(MenuItem) selection, C(Modifiers) mods);

extern C(DialogResult) (* Window_modal)(C(Window) __this);

extern C(bool) (* Window_mouseMessage)(C(Window) __this, uint method, int x, int y, C(Modifiers) * mods, C(bool) consequential, C(bool) activate);

extern void (* Window_move)(C(Window) __this, int x, int y, int w, int h);

extern C(bool) (* Window_multiTouchMessage)(C(Window) __this, C(TouchPointerEvent) event, C(Array) infos, C(Modifiers) * mods, C(bool) consequential, C(bool) activate);

extern int M_VTBLID(Window, notifyActivate);
#define Window_notifyActivate(__i, __t, window, active, previous) \
   VMETHOD(CO(Window), Window, notifyActivate, __i, C(bool), \
      C(Window) _ARG C(Window) _ARG C(bool) _ARG C(Window), \
      __t _ARG window _ARG active _ARG previous)
extern C(Method) * METHOD(Window, notifyActivate);
extern int M_VTBLID(Window, notifyDestroyed);
#define Window_notifyDestroyed(__i, __t, window, result) \
   VMETHOD(CO(Window), Window, notifyDestroyed, __i, void, \
      C(Window) _ARG C(Window) _ARG C(DialogResult), \
      __t _ARG window _ARG result)
extern C(Method) * METHOD(Window, notifyDestroyed);
extern int M_VTBLID(Window, notifySaved);
#define Window_notifySaved(__i, __t, window, filePath) \
   VMETHOD(CO(Window), Window, notifySaved, __i, void, \
      C(Window) _ARG C(Window) _ARG const char *, \
      __t _ARG window _ARG filePath)
extern C(Method) * METHOD(Window, notifySaved);
extern int M_VTBLID(Window, onActivate);
#define Window_onActivate(__i, active, previous, goOnWithActivation, direct) \
   VMETHOD(CO(Window), Window, onActivate, __i, C(bool), \
      C(Window) _ARG C(bool) _ARG C(Window) _ARG C(bool) * _ARG C(bool), \
      __i _ARG active _ARG previous _ARG goOnWithActivation _ARG direct)
extern C(Method) * METHOD(Window, onActivate);
extern int M_VTBLID(Window, onActivateClient);
#define Window_onActivateClient(__i, client, previous) \
   VMETHOD(CO(Window), Window, onActivateClient, __i, void, \
      C(Window) _ARG C(Window) _ARG C(Window), \
      __i _ARG client _ARG previous)
extern C(Method) * METHOD(Window, onActivateClient);
extern int M_VTBLID(Window, onApplyGraphics);
#define Window_onApplyGraphics(__i) \
   VMETHOD(CO(Window), Window, onApplyGraphics, __i, void, \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, onApplyGraphics);
extern int M_VTBLID(Window, onChildAddedOrRemoved);
#define Window_onChildAddedOrRemoved(__i, child, removed) \
   VMETHOD(CO(Window), Window, onChildAddedOrRemoved, __i, void, \
      C(Window) _ARG C(Window) _ARG C(bool), \
      __i _ARG child _ARG removed)
extern C(Method) * METHOD(Window, onChildAddedOrRemoved);
extern int M_VTBLID(Window, onChildResized);
#define Window_onChildResized(__i, child, x, y, w, h) \
   VMETHOD(CO(Window), Window, onChildResized, __i, void, \
      C(Window) _ARG C(Window) _ARG int _ARG int _ARG int _ARG int, \
      __i _ARG child _ARG x _ARG y _ARG w _ARG h)
extern C(Method) * METHOD(Window, onChildResized);
extern int M_VTBLID(Window, onChildVisibilityToggled);
#define Window_onChildVisibilityToggled(__i, child, visible) \
   VMETHOD(CO(Window), Window, onChildVisibilityToggled, __i, void, \
      C(Window) _ARG C(Window) _ARG C(bool), \
      __i _ARG child _ARG visible)
extern C(Method) * METHOD(Window, onChildVisibilityToggled);
extern int M_VTBLID(Window, onClose);
#define Window_onClose(__i, parentClosing) \
   VMETHOD(CO(Window), Window, onClose, __i, C(bool), \
      C(Window) _ARG C(bool), \
      __i _ARG parentClosing)
extern C(Method) * METHOD(Window, onClose);
extern int M_VTBLID(Window, onCreate);
#define Window_onCreate(__i) \
   VMETHOD(CO(Window), Window, onCreate, __i, C(bool), \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, onCreate);
extern int M_VTBLID(Window, onDestroy);
#define Window_onDestroy(__i) \
   VMETHOD(CO(Window), Window, onDestroy, __i, void, \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, onDestroy);
extern int M_VTBLID(Window, onDestroyed);
#define Window_onDestroyed(__i) \
   VMETHOD(CO(Window), Window, onDestroyed, __i, void, \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, onDestroyed);
extern int M_VTBLID(Window, onDrawOverChildren);
#define Window_onDrawOverChildren(__i, surface) \
   VMETHOD(CO(Window), Window, onDrawOverChildren, __i, void, \
      C(Window) _ARG C(Surface), \
      __i _ARG surface)
extern C(Method) * METHOD(Window, onDrawOverChildren);
extern int M_VTBLID(Window, onFileModified);
#define Window_onFileModified(__i, fileChange, param) \
   VMETHOD(CO(Window), Window, onFileModified, __i, C(bool), \
      C(Window) _ARG C(FileChange) _ARG const char *, \
      __i _ARG fileChange _ARG param)
extern C(Method) * METHOD(Window, onFileModified);
extern int M_VTBLID(Window, onHScroll);
#define Window_onHScroll(__i, action, position, key) \
   VMETHOD(CO(Window), Window, onHScroll, __i, void, \
      C(Window) _ARG C(ScrollBarAction) _ARG int _ARG C(Key), \
      __i _ARG action _ARG position _ARG key)
extern C(Method) * METHOD(Window, onHScroll);
extern int M_VTBLID(Window, onKeyDown);
#define Window_onKeyDown(__i, key, ch) \
   VMETHOD(CO(Window), Window, onKeyDown, __i, C(bool), \
      C(Window) _ARG C(Key) _ARG unichar, \
      __i _ARG key _ARG ch)
extern C(Method) * METHOD(Window, onKeyDown);
extern int M_VTBLID(Window, onKeyHit);
#define Window_onKeyHit(__i, key, ch) \
   VMETHOD(CO(Window), Window, onKeyHit, __i, C(bool), \
      C(Window) _ARG C(Key) _ARG unichar, \
      __i _ARG key _ARG ch)
extern C(Method) * METHOD(Window, onKeyHit);
extern int M_VTBLID(Window, onKeyUp);
#define Window_onKeyUp(__i, key, ch) \
   VMETHOD(CO(Window), Window, onKeyUp, __i, C(bool), \
      C(Window) _ARG C(Key) _ARG unichar, \
      __i _ARG key _ARG ch)
extern C(Method) * METHOD(Window, onKeyUp);
extern int M_VTBLID(Window, onLeftButtonDown);
#define Window_onLeftButtonDown(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onLeftButtonDown, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onLeftButtonDown);
extern int M_VTBLID(Window, onLeftButtonUp);
#define Window_onLeftButtonUp(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onLeftButtonUp, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onLeftButtonUp);
extern int M_VTBLID(Window, onLeftDoubleClick);
#define Window_onLeftDoubleClick(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onLeftDoubleClick, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onLeftDoubleClick);
extern int M_VTBLID(Window, onLoadGraphics);
#define Window_onLoadGraphics(__i) \
   VMETHOD(CO(Window), Window, onLoadGraphics, __i, C(bool), \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, onLoadGraphics);
extern int M_VTBLID(Window, onMiddleButtonDown);
#define Window_onMiddleButtonDown(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onMiddleButtonDown, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onMiddleButtonDown);
extern int M_VTBLID(Window, onMiddleButtonUp);
#define Window_onMiddleButtonUp(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onMiddleButtonUp, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onMiddleButtonUp);
extern int M_VTBLID(Window, onMiddleDoubleClick);
#define Window_onMiddleDoubleClick(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onMiddleDoubleClick, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onMiddleDoubleClick);
extern int M_VTBLID(Window, onMouseCaptureLost);
#define Window_onMouseCaptureLost(__i) \
   VMETHOD(CO(Window), Window, onMouseCaptureLost, __i, void, \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, onMouseCaptureLost);
extern int M_VTBLID(Window, onMouseLeave);
#define Window_onMouseLeave(__i, mods) \
   VMETHOD(CO(Window), Window, onMouseLeave, __i, C(bool), \
      C(Window) _ARG C(Modifiers), \
      __i _ARG mods)
extern C(Method) * METHOD(Window, onMouseLeave);
extern int M_VTBLID(Window, onMouseMove);
#define Window_onMouseMove(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onMouseMove, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onMouseMove);
extern int M_VTBLID(Window, onMouseOver);
#define Window_onMouseOver(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onMouseOver, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onMouseOver);
extern int M_VTBLID(Window, onMoving);
#define Window_onMoving(__i, x, y, w, h) \
   VMETHOD(CO(Window), Window, onMoving, __i, C(bool), \
      C(Window) _ARG int * _ARG int * _ARG int _ARG int, \
      __i _ARG x _ARG y _ARG w _ARG h)
extern C(Method) * METHOD(Window, onMoving);
extern int M_VTBLID(Window, onMultiTouch);
#define Window_onMultiTouch(__i, event, infos, mods) \
   VMETHOD(CO(Window), Window, onMultiTouch, __i, C(bool), \
      C(Window) _ARG C(TouchPointerEvent) _ARG C(Array) _ARG C(Modifiers), \
      __i _ARG event _ARG infos _ARG mods)
extern C(Method) * METHOD(Window, onMultiTouch);
extern int M_VTBLID(Window, onPosition);
#define Window_onPosition(__i, x, y, width, height) \
   VMETHOD(CO(Window), Window, onPosition, __i, void, \
      C(Window) _ARG int _ARG int _ARG int _ARG int, \
      __i _ARG x _ARG y _ARG width _ARG height)
extern C(Method) * METHOD(Window, onPosition);
extern int M_VTBLID(Window, onPostCreate);
#define Window_onPostCreate(__i) \
   VMETHOD(CO(Window), Window, onPostCreate, __i, C(bool), \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, onPostCreate);
extern int M_VTBLID(Window, onRedraw);
#define Window_onRedraw(__i, surface) \
   VMETHOD(CO(Window), Window, onRedraw, __i, void, \
      C(Window) _ARG C(Surface), \
      __i _ARG surface)
extern C(Method) * METHOD(Window, onRedraw);
extern int M_VTBLID(Window, onResize);
#define Window_onResize(__i, width, height) \
   VMETHOD(CO(Window), Window, onResize, __i, void, \
      C(Window) _ARG int _ARG int, \
      __i _ARG width _ARG height)
extern C(Method) * METHOD(Window, onResize);
extern int M_VTBLID(Window, onResizing);
#define Window_onResizing(__i, width, height) \
   VMETHOD(CO(Window), Window, onResizing, __i, C(bool), \
      C(Window) _ARG int * _ARG int *, \
      __i _ARG width _ARG height)
extern C(Method) * METHOD(Window, onResizing);
extern int M_VTBLID(Window, onRightButtonDown);
#define Window_onRightButtonDown(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onRightButtonDown, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onRightButtonDown);
extern int M_VTBLID(Window, onRightButtonUp);
#define Window_onRightButtonUp(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onRightButtonUp, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onRightButtonUp);
extern int M_VTBLID(Window, onRightDoubleClick);
#define Window_onRightDoubleClick(__i, x, y, mods) \
   VMETHOD(CO(Window), Window, onRightDoubleClick, __i, C(bool), \
      C(Window) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(Window, onRightDoubleClick);
extern int M_VTBLID(Window, onSaveFile);
#define Window_onSaveFile(__i, fileName) \
   VMETHOD(CO(Window), Window, onSaveFile, __i, C(bool), \
      C(Window) _ARG const char *, \
      __i _ARG fileName)
extern C(Method) * METHOD(Window, onSaveFile);
extern int M_VTBLID(Window, onStateChange);
#define Window_onStateChange(__i, state, mods) \
   VMETHOD(CO(Window), Window, onStateChange, __i, C(bool), \
      C(Window) _ARG C(WindowState) _ARG C(Modifiers), \
      __i _ARG state _ARG mods)
extern C(Method) * METHOD(Window, onStateChange);
extern int M_VTBLID(Window, onSysKeyDown);
#define Window_onSysKeyDown(__i, key, ch) \
   VMETHOD(CO(Window), Window, onSysKeyDown, __i, C(bool), \
      C(Window) _ARG C(Key) _ARG unichar, \
      __i _ARG key _ARG ch)
extern C(Method) * METHOD(Window, onSysKeyDown);
extern int M_VTBLID(Window, onSysKeyHit);
#define Window_onSysKeyHit(__i, key, ch) \
   VMETHOD(CO(Window), Window, onSysKeyHit, __i, C(bool), \
      C(Window) _ARG C(Key) _ARG unichar, \
      __i _ARG key _ARG ch)
extern C(Method) * METHOD(Window, onSysKeyHit);
extern int M_VTBLID(Window, onSysKeyUp);
#define Window_onSysKeyUp(__i, key, ch) \
   VMETHOD(CO(Window), Window, onSysKeyUp, __i, C(bool), \
      C(Window) _ARG C(Key) _ARG unichar, \
      __i _ARG key _ARG ch)
extern C(Method) * METHOD(Window, onSysKeyUp);
extern int M_VTBLID(Window, onUnloadGraphics);
#define Window_onUnloadGraphics(__i) \
   VMETHOD(CO(Window), Window, onUnloadGraphics, __i, void, \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, onUnloadGraphics);
extern int M_VTBLID(Window, onVScroll);
#define Window_onVScroll(__i, action, position, key) \
   VMETHOD(CO(Window), Window, onVScroll, __i, void, \
      C(Window) _ARG C(ScrollBarAction) _ARG int _ARG C(Key), \
      __i _ARG action _ARG position _ARG key)
extern C(Method) * METHOD(Window, onVScroll);
extern int M_VTBLID(Window, preShowDecorations);
#define Window_preShowDecorations(__i, captionFont, surface, name, active, moving) \
   VMETHOD(CO(Window), Window, preShowDecorations, __i, void, \
      C(Window) _ARG C(Font) * _ARG C(Surface) _ARG const char * _ARG C(bool) _ARG C(bool), \
      __i _ARG captionFont _ARG surface _ARG name _ARG active _ARG moving)
extern C(Method) * METHOD(Window, preShowDecorations);
extern void (* Window_releaseCapture)(C(Window) __this);

extern void (* Window_removeResource)(C(Window) __this, C(Resource) resource);

extern void (* Window_restoreCaret)();

extern void (* Window_scroll)(C(Window) __this, int x, int y);

extern int M_VTBLID(Window, setBox);
#define Window_setBox(__i, box) \
   VMETHOD(CO(Window), Window, setBox, __i, void, \
      C(Window) _ARG C(Box) *, \
      __i _ARG box)
extern C(Method) * METHOD(Window, setBox);
extern void (* Window_setCaption)(C(Window) __this, const char * format, ...);

extern void (* Window_setCaret)(C(Window) __this, int x, int y, int size);

extern void (* Window_setMouseRange)(C(Window) __this, C(Box) * range);

extern void (* Window_setMouseRangeToClient)(C(Window) __this);

extern void (* Window_setMouseRangeToWindow)(C(Window) __this);

extern void (* Window_setScrollArea)(C(Window) __this, int width, int height, C(bool) snapToStep);

extern void (* Window_setScrollLineStep)(C(Window) __this, int stepX, int stepY);

extern void (* Window_setScrollPosition)(C(Window) __this, int x, int y);

extern void (* Window_setState)(C(Window) __this, C(WindowState) newState, C(bool) activate, C(Modifiers) mods);

extern void (* Window_setText)(C(Window) __this, const char * format, ...);

extern int M_VTBLID(Window, setWindowArea);
#define Window_setWindowArea(__i, x, y, w, h, cw, ch) \
   VMETHOD(CO(Window), Window, setWindowArea, __i, void, \
      C(Window) _ARG int * _ARG int * _ARG C(MinMaxValue) * _ARG C(MinMaxValue) * _ARG C(MinMaxValue) * _ARG C(MinMaxValue) *, \
      __i _ARG x _ARG y _ARG w _ARG h _ARG cw _ARG ch)
extern C(Method) * METHOD(Window, setWindowArea);
extern int M_VTBLID(Window, setWindowMinimum);
#define Window_setWindowMinimum(__i, mw, mh) \
   VMETHOD(CO(Window), Window, setWindowMinimum, __i, void, \
      C(Window) _ARG C(MinMaxValue) * _ARG C(MinMaxValue) *, \
      __i _ARG mw _ARG mh)
extern C(Method) * METHOD(Window, setWindowMinimum);
extern int M_VTBLID(Window, showDecorations);
#define Window_showDecorations(__i, captionFont, surface, name, active, moving) \
   VMETHOD(CO(Window), Window, showDecorations, __i, void, \
      C(Window) _ARG C(Font) * _ARG C(Surface) _ARG const char * _ARG C(bool) _ARG C(bool), \
      __i _ARG captionFont _ARG surface _ARG name _ARG active _ARG moving)
extern C(Method) * METHOD(Window, showDecorations);
extern void (* Window_showSysMenu)(C(Window) __this, int x, int y);

extern void (* Window_softActivate)(C(Window) __this);

extern void (* Window_update)(C(Window) __this, C(Box) * region);

extern void (* Window_updateDisplay)(C(Window) __this);

extern int M_VTBLID(Window, updateNonClient);
#define Window_updateNonClient(__i) \
   VMETHOD(CO(Window), Window, updateNonClient, __i, void, \
      C(Window), \
      __i)
extern C(Method) * METHOD(Window, updateNonClient);
extern void (* Window_writeCaption)(C(Window) __this, C(Surface) surface, int x, int y);

extern C(Property) * PROPERTY(Window, parent);
extern void (* Window_set_parent)(C(Window) w, C(Window) value);
extern C(Window) (* Window_get_parent)(C(Window) w);

extern C(Property) * PROPERTY(Window, master);
extern void (* Window_set_master)(C(Window) w, C(Window) value);
extern C(Window) (* Window_get_master)(C(Window) w);

extern C(Property) * PROPERTY(Window, caption);
extern void (* Window_set_caption)(C(Window) w, const char * value);
extern const char * (* Window_get_caption)(C(Window) w);

extern C(Property) * PROPERTY(Window, hotKey);
extern void (* Window_set_hotKey)(C(Window) w, C(Key) value);
extern C(Key) (* Window_get_hotKey)(C(Window) w);

extern C(Property) * PROPERTY(Window, background);
extern void (* Window_set_background)(C(Window) w, C(Color) value);
extern C(Color) (* Window_get_background)(C(Window) w);

extern C(Property) * PROPERTY(Window, opacity);
extern void (* Window_set_opacity)(C(Window) w, C(Percentage) value);
extern C(Percentage) (* Window_get_opacity)(C(Window) w);

extern C(Property) * PROPERTY(Window, foreground);
extern void (* Window_set_foreground)(C(Window) w, C(Color) value);
extern C(Color) (* Window_get_foreground)(C(Window) w);

extern C(Property) * PROPERTY(Window, borderStyle);
extern void (* Window_set_borderStyle)(C(Window) w, C(BorderStyle) value);
extern C(BorderStyle) (* Window_get_borderStyle)(C(Window) w);

extern C(Property) * PROPERTY(Window, minClientSize);
extern void (* Window_set_minClientSize)(C(Window) w, const C(Size) * value);
extern void (* Window_get_minClientSize)(C(Window) w, C(Size) * value);

extern C(Property) * PROPERTY(Window, maxClientSize);
extern void (* Window_set_maxClientSize)(C(Window) w, const C(Size) * value);
extern void (* Window_get_maxClientSize)(C(Window) w, C(Size) * value);

extern C(Property) * PROPERTY(Window, hasMaximize);
extern void (* Window_set_hasMaximize)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_hasMaximize)(C(Window) w);

extern C(Property) * PROPERTY(Window, hasMinimize);
extern void (* Window_set_hasMinimize)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_hasMinimize)(C(Window) w);

extern C(Property) * PROPERTY(Window, hasClose);
extern void (* Window_set_hasClose)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_hasClose)(C(Window) w);

extern C(Property) * PROPERTY(Window, nonClient);
extern void (* Window_set_nonClient)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_nonClient)(C(Window) w);

extern C(Property) * PROPERTY(Window, inactive);
extern void (* Window_set_inactive)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_inactive)(C(Window) w);

extern C(Property) * PROPERTY(Window, clickThrough);
extern void (* Window_set_clickThrough)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_clickThrough)(C(Window) w);

extern C(Property) * PROPERTY(Window, isRemote);
extern void (* Window_set_isRemote)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_isRemote)(C(Window) w);

extern C(Property) * PROPERTY(Window, noCycle);
extern void (* Window_set_noCycle)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_noCycle)(C(Window) w);

extern C(Property) * PROPERTY(Window, isModal);
extern void (* Window_set_isModal)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_isModal)(C(Window) w);

extern C(Property) * PROPERTY(Window, interim);
extern void (* Window_set_interim)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_interim)(C(Window) w);

extern C(Property) * PROPERTY(Window, tabCycle);
extern void (* Window_set_tabCycle)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_tabCycle)(C(Window) w);

extern C(Property) * PROPERTY(Window, isDefault);
extern void (* Window_set_isDefault)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_isDefault)(C(Window) w);

extern C(Property) * PROPERTY(Window, drawBehind);
extern void (* Window_set_drawBehind)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_drawBehind)(C(Window) w);

extern C(Property) * PROPERTY(Window, hasMenuBar);
extern void (* Window_set_hasMenuBar)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_hasMenuBar)(C(Window) w);

extern C(Property) * PROPERTY(Window, hasStatusBar);
extern void (* Window_set_hasStatusBar)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_hasStatusBar)(C(Window) w);

extern C(Property) * PROPERTY(Window, stayOnTop);
extern void (* Window_set_stayOnTop)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_stayOnTop)(C(Window) w);

extern C(Property) * PROPERTY(Window, menu);
extern void (* Window_set_menu)(C(Window) w, C(Menu) value);
extern C(Menu) (* Window_get_menu)(C(Window) w);

extern C(Property) * PROPERTY(Window, font);
extern void (* Window_set_font)(C(Window) w, C(FontResource) value);
extern C(FontResource) (* Window_get_font)(C(Window) w);
extern bool (* Window_isSet_font)(C(Window) w);

extern C(Property) * PROPERTY(Window, sizeAnchor);
extern void (* Window_set_sizeAnchor)(C(Window) w, const C(SizeAnchor) * value);
extern void (* Window_get_sizeAnchor)(C(Window) w, C(SizeAnchor) * value);
extern bool (* Window_isSet_sizeAnchor)(C(Window) w);

extern C(Property) * PROPERTY(Window, size);
extern void (* Window_set_size)(C(Window) w, const C(Size) * value);
extern void (* Window_get_size)(C(Window) w, C(Size) * value);
extern bool (* Window_isSet_size)(C(Window) w);

extern C(Property) * PROPERTY(Window, clientSize);
extern void (* Window_set_clientSize)(C(Window) w, const C(Size) * value);
extern void (* Window_get_clientSize)(C(Window) w, C(Size) * value);
extern bool (* Window_isSet_clientSize)(C(Window) w);

extern C(Property) * PROPERTY(Window, initSize);
extern void (* Window_get_initSize)(C(Window) w, C(Size) * value);

extern C(Property) * PROPERTY(Window, anchor);
extern void (* Window_set_anchor)(C(Window) w, const C(Anchor) * value);
extern void (* Window_get_anchor)(C(Window) w, C(Anchor) * value);
extern bool (* Window_isSet_anchor)(C(Window) w);

extern C(Property) * PROPERTY(Window, position);
extern void (* Window_set_position)(C(Window) w, const C(Point) * value);
extern void (* Window_get_position)(C(Window) w, C(Point) * value);

extern C(Property) * PROPERTY(Window, disabled);
extern void (* Window_set_disabled)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_disabled)(C(Window) w);

extern C(Property) * PROPERTY(Window, isEnabled);
extern C(bool) (* Window_get_isEnabled)(C(Window) w);

extern C(Property) * PROPERTY(Window, state);
extern void (* Window_set_state)(C(Window) w, C(WindowState) value);
extern C(WindowState) (* Window_get_state)(C(Window) w);

extern C(Property) * PROPERTY(Window, visible);
extern void (* Window_set_visible)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_visible)(C(Window) w);

extern C(Property) * PROPERTY(Window, isDocument);
extern void (* Window_set_isDocument)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_isDocument)(C(Window) w);

extern C(Property) * PROPERTY(Window, mergeMenus);
extern void (* Window_set_mergeMenus)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_mergeMenus)(C(Window) w);

extern C(Property) * PROPERTY(Window, hasHorzScroll);
extern void (* Window_set_hasHorzScroll)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_hasHorzScroll)(C(Window) w);

extern C(Property) * PROPERTY(Window, hasVertScroll);
extern void (* Window_set_hasVertScroll)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_hasVertScroll)(C(Window) w);

extern C(Property) * PROPERTY(Window, dontHideScroll);
extern void (* Window_set_dontHideScroll)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_dontHideScroll)(C(Window) w);

extern C(Property) * PROPERTY(Window, dontScrollVert);
extern void (* Window_set_dontScrollVert)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_dontScrollVert)(C(Window) w);

extern C(Property) * PROPERTY(Window, dontScrollHorz);
extern void (* Window_set_dontScrollHorz)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_dontScrollHorz)(C(Window) w);

extern C(Property) * PROPERTY(Window, snapVertScroll);
extern void (* Window_set_snapVertScroll)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_snapVertScroll)(C(Window) w);

extern C(Property) * PROPERTY(Window, snapHorzScroll);
extern void (* Window_set_snapHorzScroll)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_snapHorzScroll)(C(Window) w);

extern C(Property) * PROPERTY(Window, scroll);
extern void (* Window_set_scroll)(C(Window) w, const C(Point) * value);
extern void (* Window_get_scroll)(C(Window) w, C(Point) * value);

extern C(Property) * PROPERTY(Window, modifyVirtualArea);
extern void (* Window_set_modifyVirtualArea)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_modifyVirtualArea)(C(Window) w);

extern C(Property) * PROPERTY(Window, dontAutoScrollArea);
extern void (* Window_set_dontAutoScrollArea)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_dontAutoScrollArea)(C(Window) w);

extern C(Property) * PROPERTY(Window, fileName);
extern void (* Window_set_fileName)(C(Window) w, const char * value);
extern const char * (* Window_get_fileName)(C(Window) w);

extern C(Property) * PROPERTY(Window, id);
extern void (* Window_set_id)(C(Window) w, int64 value);
extern int64 (* Window_get_id)(C(Window) w);

extern C(Property) * PROPERTY(Window, modifiedDocument);
extern void (* Window_set_modifiedDocument)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_modifiedDocument)(C(Window) w);

extern C(Property) * PROPERTY(Window, showInTaskBar);
extern void (* Window_set_showInTaskBar)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_showInTaskBar)(C(Window) w);

extern C(Property) * PROPERTY(Window, saveDialog);
extern void (* Window_set_saveDialog)(C(Window) w, C(FileDialog) value);

extern C(Property) * PROPERTY(Window, isActiveClient);
extern void (* Window_set_isActiveClient)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_isActiveClient)(C(Window) w);

extern C(Property) * PROPERTY(Window, cursor);
extern void (* Window_set_cursor)(C(Window) w, C(Cursor) value);
extern C(Cursor) (* Window_get_cursor)(C(Window) w);

extern C(Property) * PROPERTY(Window, name);
extern void (* Window_set_name)(C(Window) w, const char * value);
extern const char * (* Window_get_name)(C(Window) w);

extern C(Property) * PROPERTY(Window, displayDriver);
extern void (* Window_set_displayDriver)(C(Window) w, const char * value);
extern const char * (* Window_get_displayDriver)(C(Window) w);

extern C(Property) * PROPERTY(Window, autoCreate);
extern void (* Window_set_autoCreate)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_autoCreate)(C(Window) w);

extern C(Property) * PROPERTY(Window, scrollArea);
extern void (* Window_set_scrollArea)(C(Window) w, const C(Size) * value);
extern void (* Window_get_scrollArea)(C(Window) w, C(Size) * value);
extern bool (* Window_isSet_scrollArea)(C(Window) w);

extern C(Property) * PROPERTY(Window, is3D);
extern void (* Window_set_is3D)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_is3D)(C(Window) w);

extern C(Property) * PROPERTY(Window, fontObject);
extern C(Font) * (* Window_get_fontObject)(C(Window) w);

extern C(Property) * PROPERTY(Window, clientStart);
extern void (* Window_get_clientStart)(C(Window) w, C(Point) * value);

extern C(Property) * PROPERTY(Window, absPosition);
extern void (* Window_get_absPosition)(C(Window) w, C(Point) * value);

extern C(Property) * PROPERTY(Window, normalAnchor);
extern void (* Window_get_normalAnchor)(C(Window) w, C(Anchor) * value);

extern C(Property) * PROPERTY(Window, normalSizeAnchor);
extern void (* Window_get_normalSizeAnchor)(C(Window) w, C(SizeAnchor) * value);

extern C(Property) * PROPERTY(Window, active);
extern C(bool) (* Window_get_active)(C(Window) w);

extern C(Property) * PROPERTY(Window, created);
extern C(bool) (* Window_get_created)(C(Window) w);

extern C(Property) * PROPERTY(Window, destroyed);
extern C(bool) (* Window_get_destroyed)(C(Window) w);

extern C(Property) * PROPERTY(Window, firstSlave);
extern C(Window) (* Window_get_firstSlave)(C(Window) w);

extern C(Property) * PROPERTY(Window, firstChild);
extern C(Window) (* Window_get_firstChild)(C(Window) w);

extern C(Property) * PROPERTY(Window, lastChild);
extern C(Window) (* Window_get_lastChild)(C(Window) w);

extern C(Property) * PROPERTY(Window, activeClient);
extern C(Window) (* Window_get_activeClient)(C(Window) w);

extern C(Property) * PROPERTY(Window, activeChild);
extern C(Window) (* Window_get_activeChild)(C(Window) w);

extern C(Property) * PROPERTY(Window, display);
extern C(Display) (* Window_get_display)(C(Window) w);

extern C(Property) * PROPERTY(Window, displaySystem);
extern C(DisplaySystem) (* Window_get_displaySystem)(C(Window) w);

extern C(Property) * PROPERTY(Window, horzScroll);
extern C(ScrollBar) (* Window_get_horzScroll)(C(Window) w);

extern C(Property) * PROPERTY(Window, vertScroll);
extern C(ScrollBar) (* Window_get_vertScroll)(C(Window) w);

extern C(Property) * PROPERTY(Window, statusBar);
extern C(StatusBar) (* Window_get_statusBar)(C(Window) w);

extern C(Property) * PROPERTY(Window, rootWindow);
extern C(Window) (* Window_get_rootWindow)(C(Window) w);

extern C(Property) * PROPERTY(Window, closing);
extern void (* Window_set_closing)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_closing)(C(Window) w);

extern C(Property) * PROPERTY(Window, documentID);
extern int (* Window_get_documentID)(C(Window) w);

extern C(Property) * PROPERTY(Window, previous);
extern C(Window) (* Window_get_previous)(C(Window) w);

extern C(Property) * PROPERTY(Window, next);
extern C(Window) (* Window_get_next)(C(Window) w);

extern C(Property) * PROPERTY(Window, nextSlave);
extern C(Window) (* Window_get_nextSlave)(C(Window) w);

extern C(Property) * PROPERTY(Window, menuBar);
extern C(PopupMenu) (* Window_get_menuBar)(C(Window) w);

extern C(Property) * PROPERTY(Window, sbv);
extern C(ScrollBar) (* Window_get_sbv)(C(Window) w);

extern C(Property) * PROPERTY(Window, sbh);
extern C(ScrollBar) (* Window_get_sbh)(C(Window) w);

extern C(Property) * PROPERTY(Window, fullRender);
extern void (* Window_set_fullRender)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_fullRender)(C(Window) w);

extern C(Property) * PROPERTY(Window, systemHandle);
extern void * (* Window_get_systemHandle)(C(Window) w);

extern C(Property) * PROPERTY(Window, minimizeButton);
extern C(Button) (* Window_get_minimizeButton)(C(Window) w);

extern C(Property) * PROPERTY(Window, maximizeButton);
extern C(Button) (* Window_get_maximizeButton)(C(Window) w);

extern C(Property) * PROPERTY(Window, closeButton);
extern C(Button) (* Window_get_closeButton)(C(Window) w);

extern C(Property) * PROPERTY(Window, icon);
extern void (* Window_set_icon)(C(Window) w, C(BitmapResource) value);
extern C(BitmapResource) (* Window_get_icon)(C(Window) w);

extern C(Property) * PROPERTY(Window, moveable);
extern void (* Window_set_moveable)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_moveable)(C(Window) w);

extern C(Property) * PROPERTY(Window, alphaBlend);
extern void (* Window_set_alphaBlend)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_alphaBlend)(C(Window) w);

extern C(Property) * PROPERTY(Window, useSharedMemory);
extern void (* Window_set_useSharedMemory)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_useSharedMemory)(C(Window) w);

extern C(Property) * PROPERTY(Window, glCapabilities);
extern void (* Window_set_glCapabilities)(C(Window) w, C(GLCapabilities) value);
extern C(GLCapabilities) (* Window_get_glCapabilities)(C(Window) w);

extern C(Property) * PROPERTY(Window, creationActivation);
extern void (* Window_set_creationActivation)(C(Window) w, C(CreationActivationOption) value);
extern C(CreationActivationOption) (* Window_get_creationActivation)(C(Window) w);

extern C(Property) * PROPERTY(Window, nativeDecorations);
extern void (* Window_set_nativeDecorations)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_nativeDecorations)(C(Window) w);
extern bool (* Window_isSet_nativeDecorations)(C(Window) w);

extern C(Property) * PROPERTY(Window, manageDisplay);
extern void (* Window_set_manageDisplay)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_manageDisplay)(C(Window) w);

extern C(Property) * PROPERTY(Window, text);
extern void (* Window_set_text)(C(Window) w, const char * value);
extern const char * (* Window_get_text)(C(Window) w);

extern C(Property) * PROPERTY(Window, controller);
extern void (* Window_set_controller)(C(Window) w, C(WindowController) value);
extern C(WindowController) (* Window_get_controller)(C(Window) w);

extern C(Property) * PROPERTY(Window, noConsequential);
extern void (* Window_set_noConsequential)(C(Window) w, C(bool) value);
extern C(bool) (* Window_get_noConsequential)(C(Window) w);

extern int M_VTBLID(WindowController, onCreate);
#define WindowController_onCreate(__i, controller) \
   VMETHOD(CO(WindowController), WindowController, onCreate, __i, C(bool), \
      C(WindowController) _ARG C(WindowController), \
      __i _ARG controller)
extern C(Method) * METHOD(WindowController, onCreate);
extern int M_VTBLID(WindowController, onKeyDown);
#define WindowController_onKeyDown(__i, controller, key, ch) \
   VMETHOD(CO(WindowController), WindowController, onKeyDown, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG C(Key) _ARG unichar, \
      __i _ARG controller _ARG key _ARG ch)
extern C(Method) * METHOD(WindowController, onKeyDown);
extern int M_VTBLID(WindowController, onKeyHit);
#define WindowController_onKeyHit(__i, controller, key, ch) \
   VMETHOD(CO(WindowController), WindowController, onKeyHit, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG C(Key) _ARG unichar, \
      __i _ARG controller _ARG key _ARG ch)
extern C(Method) * METHOD(WindowController, onKeyHit);
extern int M_VTBLID(WindowController, onKeyUp);
#define WindowController_onKeyUp(__i, controller, key, ch) \
   VMETHOD(CO(WindowController), WindowController, onKeyUp, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG C(Key) _ARG unichar, \
      __i _ARG controller _ARG key _ARG ch)
extern C(Method) * METHOD(WindowController, onKeyUp);
extern int M_VTBLID(WindowController, onLeftButtonDown);
#define WindowController_onLeftButtonDown(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onLeftButtonDown, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onLeftButtonDown);
extern int M_VTBLID(WindowController, onLeftButtonUp);
#define WindowController_onLeftButtonUp(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onLeftButtonUp, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onLeftButtonUp);
extern int M_VTBLID(WindowController, onLeftDoubleClick);
#define WindowController_onLeftDoubleClick(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onLeftDoubleClick, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onLeftDoubleClick);
extern int M_VTBLID(WindowController, onLoadGraphics);
#define WindowController_onLoadGraphics(__i, controller) \
   VMETHOD(CO(WindowController), WindowController, onLoadGraphics, __i, C(bool), \
      C(WindowController) _ARG C(WindowController), \
      __i _ARG controller)
extern C(Method) * METHOD(WindowController, onLoadGraphics);
extern int M_VTBLID(WindowController, onMiddleButtonDown);
#define WindowController_onMiddleButtonDown(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onMiddleButtonDown, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onMiddleButtonDown);
extern int M_VTBLID(WindowController, onMiddleButtonUp);
#define WindowController_onMiddleButtonUp(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onMiddleButtonUp, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onMiddleButtonUp);
extern int M_VTBLID(WindowController, onMiddleDoubleClick);
#define WindowController_onMiddleDoubleClick(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onMiddleDoubleClick, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onMiddleDoubleClick);
extern int M_VTBLID(WindowController, onMouseMove);
#define WindowController_onMouseMove(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onMouseMove, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onMouseMove);
extern int M_VTBLID(WindowController, onMultiTouch);
#define WindowController_onMultiTouch(__i, controller, event, infos, mods) \
   VMETHOD(CO(WindowController), WindowController, onMultiTouch, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG C(TouchPointerEvent) _ARG C(Array) _ARG C(Modifiers), \
      __i _ARG controller _ARG event _ARG infos _ARG mods)
extern C(Method) * METHOD(WindowController, onMultiTouch);
extern int M_VTBLID(WindowController, onRedraw);
#define WindowController_onRedraw(__i, controller, surface) \
   VMETHOD(CO(WindowController), WindowController, onRedraw, __i, void, \
      C(WindowController) _ARG C(WindowController) _ARG C(Surface), \
      __i _ARG controller _ARG surface)
extern C(Method) * METHOD(WindowController, onRedraw);
extern int M_VTBLID(WindowController, onResize);
#define WindowController_onResize(__i, controller, width, height) \
   VMETHOD(CO(WindowController), WindowController, onResize, __i, void, \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int, \
      __i _ARG controller _ARG width _ARG height)
extern C(Method) * METHOD(WindowController, onResize);
extern int M_VTBLID(WindowController, onRightButtonDown);
#define WindowController_onRightButtonDown(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onRightButtonDown, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onRightButtonDown);
extern int M_VTBLID(WindowController, onRightButtonUp);
#define WindowController_onRightButtonUp(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onRightButtonUp, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onRightButtonUp);
extern int M_VTBLID(WindowController, onRightDoubleClick);
#define WindowController_onRightDoubleClick(__i, controller, x, y, mods) \
   VMETHOD(CO(WindowController), WindowController, onRightDoubleClick, __i, C(bool), \
      C(WindowController) _ARG C(WindowController) _ARG int _ARG int _ARG C(Modifiers), \
      __i _ARG controller _ARG x _ARG y _ARG mods)
extern C(Method) * METHOD(WindowController, onRightDoubleClick);
extern int M_VTBLID(WindowController, onUnloadGraphics);
#define WindowController_onUnloadGraphics(__i, controller) \
   VMETHOD(CO(WindowController), WindowController, onUnloadGraphics, __i, void, \
      C(WindowController) _ARG C(WindowController), \
      __i _ARG controller)
extern C(Method) * METHOD(WindowController, onUnloadGraphics);
extern C(Property) * PROPERTY(WindowController, window);
extern C(Window) (* WindowController_get_window)(C(WindowController) w);

extern C(Property) * PROPERTY(WindowController, controlled);
extern void (* WindowController_set_controlled)(C(WindowController) w, TP(WindowController, V) value);
extern TP(WindowController, V) (* WindowController_get_controlled)(C(WindowController) w);

extern void (* applySkin)(C(Class) * c, const char * name, void ** vTbl);
extern C(bool) (* desktop3DFullScreen)(C(Window) window);
extern void (* desktop3DGetClipBox)(C(Box) * box);
extern C(Window) (* desktop3DGetClippedWindow)(void);
extern void * (* desktop3DGetWindowHandle)(C(Window) window);
extern void (* desktop3DInitialize)(C(Window) window, void (* setup)(C(Window) window, int w, int h), void (* update)(C(Window) window, C(Box) * box));
extern C(bool) (* desktop3DMouseMessage)(C(Window) window, uint method, int x, int y, C(Modifiers) * mods, C(bool) consequential, C(bool) activate);
extern void (* desktop3DSetDesktopDirty)(void);
extern C(bool) (* desktop3DTitleBarClicked)(C(Window) clickedWindow, int x, int y);
extern C(bool) (* desktop3DUpdateDisplay)(void);
extern void (* unapplySkin)(C(Class) * c);

// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||gui||skins  /////////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


typedef C(Window) C(TVisionSkin_Window);
typedef C(Button) C(WindowsSkin_Button);
typedef C(Window) C(WindowsSkin_Window);

// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// ////////  ecere||net  ////////////////////////////////////////////// ////////////////////////////////
// namespace /////////////// //////////////////////////////////////////////////////////////////// ////////////////////////////////


// start -- moved backwards outputs
typedef C(Instance) C(Socket);
typedef C(Instance) C(Service);
typedef C(Socket) C(SSLSocket);
typedef struct C(Packet) C(Packet);
typedef C(File) C(NetworkClientFile);
typedef C(File) C(HTTPFile);
typedef C(Socket) C(FileServerConnection);
#if CPP11
enum C(DisconnectCode) : int
#else
typedef int C(DisconnectCode);
enum C(DisconnectCode)
#endif
{
   DisconnectCode_remoteLost = 0x1,
   DisconnectCode_remoteClosed = 0x2,
   DisconnectCode_resolveFailed = 0x3,
   DisconnectCode_connectFailed = 0x4
};

typedef C(Service) C(DCOMService);
typedef C(Socket) C(DCOMServerSocket);
typedef C(Instance) C(DCOMServerObject);
typedef C(Instance) C(DCOMSendControl);
typedef C(Socket) C(DCOMClientObject);
// end -- moved backwards outputs
#if CPP11
enum C(SocketType) : int
#else
typedef int C(SocketType);
enum C(SocketType)
#endif
{
   SocketType_tcp = 0x0,
   SocketType_udp = 0x1
};

struct CM(DCOMClientObject)
{
   uint objectID;
   C(bool) answered;
   C(SerialBuffer) __ecereBuffer;
   C(List) acks;
   int nextCallID;
};
extern C(bool) (* DCOMClientObject_callMethod)(C(DCOMClientObject) __this, uint methodID);

extern int M_VTBLID(DCOMClientObject, callVirtualMethod);
#define DCOMClientObject_callVirtualMethod(__i, __ecereMethodID, __ecereBuffer) \
   VMETHOD(CO(DCOMClientObject), DCOMClientObject, callVirtualMethod, __i, void, \
      C(DCOMClientObject) _ARG uint _ARG C(SerialBuffer), \
      __i _ARG __ecereMethodID _ARG __ecereBuffer)
extern C(Method) * METHOD(DCOMClientObject, callVirtualMethod);
extern C(bool) (* DCOMClientObject_connect)(C(DCOMClientObject) __this, const char * server, int port);

extern void (* DCOMSendControl_resume)(C(DCOMSendControl) __this);

extern void (* DCOMSendControl_stop)(C(DCOMSendControl) __this);

struct CM(DCOMServerObject)
{
   C(Instance) instance;
   C(DCOMServerSocket) serverSocket;
   uint id;
   C(SerialBuffer) argsBuffer;
   C(SerialBuffer) returnBuffer;
   C(List) acks;
   C(Mutex) * mutex;
   int nextCallID;
};
extern int M_VTBLID(DCOMServerObject, callMethod);
#define DCOMServerObject_callMethod(__i, __ecereMethodID, __ecereBuffer) \
   VMETHOD(CO(DCOMServerObject), DCOMServerObject, callMethod, __i, void, \
      C(DCOMServerObject) _ARG uint _ARG C(SerialBuffer), \
      __i _ARG __ecereMethodID _ARG __ecereBuffer)
extern C(Method) * METHOD(DCOMServerObject, callMethod);
extern C(bool) (* DCOMServerObject_callVirtualMethod)(C(DCOMServerObject) __this, uint methodID, C(bool) hasReturnValue);

extern C(bool) (* DCOMService_start)(C(DCOMService) __this);

extern C(bool) (* DCOMService_stop)(C(DCOMService) __this);

extern C(NetworkClientFile) (* FileServerConnection_open)(C(FileServerConnection) __this, const char * fileName, C(FileOpenMode) mode);

extern C(bool) (* HTTPFile_openURL)(C(HTTPFile) __this, const char * name, const char * referer, char * relocation);

extern C(Property) * PROPERTY(HTTPFile, reuseConnection);
extern void (* HTTPFile_set_reuseConnection)(C(HTTPFile) h, C(bool) value);
extern C(bool) (* HTTPFile_get_reuseConnection)(C(HTTPFile) h);

extern C(Property) * PROPERTY(HTTPFile, contentType);
extern C(String) (* HTTPFile_get_contentType)(C(HTTPFile) h);

extern C(Property) * PROPERTY(HTTPFile, contentDisposition);
extern C(String) (* HTTPFile_get_contentDisposition)(C(HTTPFile) h);

struct C(Packet)
{
   uint size;
};
extern C(bool) (* SSLSocket_establishConnection)(C(SSLSocket) __this);

extern C(Property) * PROPERTY(SSLSocket, autoEstablish);
extern void (* SSLSocket_set_autoEstablish)(C(SSLSocket) s, C(bool) value);
extern C(bool) (* SSLSocket_get_autoEstablish)(C(SSLSocket) s);

extern int M_VTBLID(Service, onAccept);
#define Service_onAccept(__i) \
   VMETHOD(CO(Service), Service, onAccept, __i, void, \
      C(Service), \
      __i)
extern C(Method) * METHOD(Service, onAccept);
extern C(bool) (* Service_process)(C(Service) __this);

extern C(bool) (* Service_processTimeOut)(C(Service) __this, C(Time) timeOut);

extern C(bool) (* Service_start)(C(Service) __this);

extern C(bool) (* Service_stop)(C(Service) __this);

extern C(Property) * PROPERTY(Service, port);
extern void (* Service_set_port)(C(Service) s, int value);
extern int (* Service_get_port)(C(Service) s);

extern C(Property) * PROPERTY(Service, firstClient);
extern C(Socket) (* Service_get_firstClient)(C(Service) s);

extern C(Property) * PROPERTY(Service, processAlone);
extern void (* Service_set_processAlone)(C(Service) s, C(bool) value);
extern C(bool) (* Service_get_processAlone)(C(Service) s);

extern C(bool) (* Socket_connect)(C(Socket) __this, const char * address, int port);

extern C(bool) (* Socket_datagramConnect)(C(Socket) __this, const char * sendAddress, int port);

extern C(bool) (* Socket_datagramHost)(C(Socket) __this, int port);

extern void (* Socket_disconnect)(C(Socket) __this, C(DisconnectCode) code);

extern int M_VTBLID(Socket, onConnect);
#define Socket_onConnect(__i) \
   VMETHOD(CO(Socket), Socket, onConnect, __i, void, \
      C(Socket), \
      __i)
extern C(Method) * METHOD(Socket, onConnect);
extern int M_VTBLID(Socket, onDisconnect);
#define Socket_onDisconnect(__i, code) \
   VMETHOD(CO(Socket), Socket, onDisconnect, __i, void, \
      C(Socket) _ARG int, \
      __i _ARG code)
extern C(Method) * METHOD(Socket, onDisconnect);
extern int M_VTBLID(Socket, onEstablishConnection);
#define Socket_onEstablishConnection(__i, s) \
   VMETHOD(CO(Socket), Socket, onEstablishConnection, __i, C(bool), \
      C(Socket) _ARG int, \
      __i _ARG s)
extern C(Method) * METHOD(Socket, onEstablishConnection);
extern int M_VTBLID(Socket, onReceive);
#define Socket_onReceive(__i, buffer, count) \
   VMETHOD(CO(Socket), Socket, onReceive, __i, uint, \
      C(Socket) _ARG const byte * _ARG uint, \
      __i _ARG buffer _ARG count)
extern C(Method) * METHOD(Socket, onReceive);
extern int M_VTBLID(Socket, onReceivePacket);
#define Socket_onReceivePacket(__i, packet) \
   VMETHOD(CO(Socket), Socket, onReceivePacket, __i, void, \
      C(Socket) _ARG C(Packet) *, \
      __i _ARG packet)
extern C(Method) * METHOD(Socket, onReceivePacket);
extern C(bool) (* Socket_process)(C(Socket) __this);

extern C(bool) (* Socket_processTimeOut)(C(Socket) __this, C(Time) timeOut);

extern int M_VTBLID(Socket, receiveData);
#define Socket_receiveData(__i, buffer, count, flags) \
   VMETHOD(CO(Socket), Socket, receiveData, __i, int, \
      C(Socket) _ARG byte * _ARG int _ARG uint, \
      __i _ARG buffer _ARG count _ARG flags)
extern C(Method) * METHOD(Socket, receiveData);
extern C(bool) (* Socket_send)(C(Socket) __this, const void * buffer, int size);

extern int M_VTBLID(Socket, sendData);
#define Socket_sendData(__i, buffer, count, flags) \
   VMETHOD(CO(Socket), Socket, sendData, __i, int, \
      C(Socket) _ARG const byte * _ARG int _ARG uint, \
      __i _ARG buffer _ARG count _ARG flags)
extern C(Method) * METHOD(Socket, sendData);
extern C(bool) (* Socket_sendPacket)(C(Socket) __this, C(Packet) * packet);

extern C(bool) (* Socket_sendString)(C(Socket) __this, const char * string);

extern C(bool) (* Socket_sendf)(C(Socket) __this, const char * format, ...);

extern void (* Socket_safeDecRef)(C(Socket) __this);

extern void (* Socket_safeIncRef)(C(Socket) __this);

extern C(Property) * PROPERTY(Socket, service);
extern void (* Socket_set_service)(C(Socket) s, C(Service) value);
extern C(Service) (* Socket_get_service)(C(Socket) s);

extern C(Property) * PROPERTY(Socket, inetAddress);
extern const char * (* Socket_get_inetAddress)(C(Socket) s);

extern C(Property) * PROPERTY(Socket, inetPort);
extern int (* Socket_get_inetPort)(C(Socket) s);

extern C(Property) * PROPERTY(Socket, next);
extern C(Socket) (* Socket_get_next)(C(Socket) s);

extern C(Property) * PROPERTY(Socket, connected);
extern C(bool) (* Socket_get_connected)(C(Socket) s);

extern C(Property) * PROPERTY(Socket, processAlone);
extern void (* Socket_set_processAlone)(C(Socket) s, C(bool) value);
extern C(bool) (* Socket_get_processAlone)(C(Socket) s);

extern C(FileServerConnection) (* connectToFileServer)(const char * hostName, int port);
extern C(HTTPFile) (* fileOpenURL)(const char * name);
extern C(bool) (* getAddressFromName)(const char * hostName, char * inetAddress);
extern C(bool) (* getHostName)(char * hostName, int size);
extern C(bool) (* getNameFromAddress)(const char * inetAddress, char * hostName);
extern C(Class) * CO(Archive);
extern C(Class) * CO(ArchiveAddMode);
extern C(Class) * CO(ArchiveDir);
extern C(Class) * CO(ArchiveOpenFlags);
extern C(Class) * CO(Box);
extern C(Class) * CO(BufferedFile);
extern C(Class) * CO(Centimeters);
extern C(Class) * CO(CharCategories);
extern C(Class) * CO(CharCategory);
extern C(Class) * CO(Condition);
extern C(Class) * CO(ConsoleFile);
extern C(Class) * CO(Date);
extern C(Class) * CO(DateTime);
extern C(Class) * CO(DayOfTheWeek);
extern C(Class) * CO(Degrees);
extern C(Class) * CO(Distance);
extern C(Class) * CO(DualPipe);
extern C(Class) * CO(ECONGlobalSettings);
extern C(Class) * CO(ECONParser);
extern C(Class) * CO(ErrorCode);
extern C(Class) * CO(ErrorLevel);
extern C(Class) * CO(Feet);
extern C(Class) * CO(File);
extern C(Class) * CO(FileAttribs);
extern C(Class) * CO(FileChange);
extern C(Class) * CO(FileListing);
extern C(Class) * CO(FileLock);
extern C(Class) * CO(FileMonitor);
extern C(Class) * CO(FileOpenMode);
extern C(Class) * CO(FileSeekMode);
extern C(Class) * CO(FileSize);
extern C(Class) * CO(FileSize64);
extern C(Class) * CO(FileStats);
extern C(Class) * CO(GlobalAppSettings);
extern C(Class) * CO(GlobalSettingType);
extern C(Class) * CO(GlobalSettings);
extern C(Class) * CO(GlobalSettingsData);
extern C(Class) * CO(GlobalSettingsDriver);
extern C(Class) * CO(GuiErrorCode);
extern C(Class) * CO(JSONGlobalSettings);
extern C(Class) * CO(JSONParser);
extern C(Class) * CO(JSONResult);
extern C(Class) * CO(LoggingMode);
extern C(Class) * CO(Meters);
extern C(Class) * CO(MinMaxValue);
extern C(Class) * CO(Month);
extern C(Class) * CO(MoveFileOptions);
extern C(Class) * CO(PipeOpenMode);
extern C(Class) * CO(Point);
extern C(Class) * CO(Pointf);
extern C(Class) * CO(PredefinedCharCategories);
extern C(Class) * CO(Radians);
extern C(Class) * CO(RepButton);
extern C(Class) * CO(SecSince1970);
extern C(Class) * CO(Seconds);
extern C(Class) * CO(Semaphore);
extern C(Class) * CO(SetBool);
extern C(Class) * CO(SettingsIOResult);
extern C(Class) * CO(Size);
extern C(Class) * CO(SysErrorCode);
extern C(Class) * CO(TempFile);
extern C(Class) * CO(Thread);
extern C(Class) * CO(ThreadPriority);
extern C(Class) * CO(Time);
extern C(Class) * CO(TimeStamp);
extern C(Class) * CO(TimeStamp32);
extern C(Class) * CO(Camera);
extern C(Class) * CO(CameraType);
extern C(Class) * CO(ClippingPlane);
extern C(Class) * CO(Euler);
extern C(Class) * CO(FovDirection);
extern C(Class) * CO(FrameKey);
extern C(Class) * CO(FrameTrack);
extern C(Class) * CO(FrameTrackBits);
extern C(Class) * CO(FrameTrackType);
extern C(Class) * CO(FrustumPlacement);
extern C(Class) * CO(Line);
extern C(Class) * CO(Material);
extern C(Class) * CO(MaterialFlags);
extern C(Class) * CO(Matrix);
extern C(Class) * CO(Mesh);
extern C(Class) * CO(MeshFeatures);
extern C(Class) * CO(Object);
extern C(Class) * CO(ObjectFlags);
extern C(Class) * CO(ObjectFormat);
extern C(Class) * CO(Plane);
extern C(Class) * CO(PrimitiveGroup);
extern C(Class) * CO(PrimitiveGroupType);
extern C(Class) * CO(PrimitiveSingle);
extern C(Class) * CO(Quaternion);
extern C(Class) * CO(RenderPrimitiveType);
extern C(Class) * CO(Transform);
extern C(Class) * CO(Vector3D);
extern C(Class) * CO(Vector3Df);
extern C(Class) * CO(AlphaWriteMode);
extern C(Class) * CO(Bitmap);
extern C(Class) * CO(BitmapFormat);
extern C(Class) * CO(BitmapResource);
extern C(Class) * CO(ClearType);
extern C(Class) * CO(Color);
extern C(Class) * CO(Color444);
extern C(Class) * CO(Color555);
extern C(Class) * CO(Color565);
extern C(Class) * CO(ColorAlpha);
extern C(Class) * CO(ColorCMYK);
extern C(Class) * CO(ColorHSV);
extern C(Class) * CO(ColorKey);
extern C(Class) * CO(ColorLab);
extern C(Class) * CO(ColorRGB);
extern C(Class) * CO(ColorRGBA);
extern C(Class) * CO(ColorRGBAf);
extern C(Class) * CO(CubeMap);
extern C(Class) * CO(DefinedColor);
extern C(Class) * CO(Display);
extern C(Class) * CO(DisplayDriver);
extern C(Class) * CO(DisplayFlags);
extern C(Class) * CO(DisplaySystem);
extern C(Class) * CO(DisplaySystemResPtr);
extern C(Class) * CO(DrawManager);
extern C(Class) * CO(FMFont);
extern C(Class) * CO(FMPathDraw);
extern C(Class) * CO(FMTextAlignment);
extern C(Class) * CO(FMVerticalAlignment);
extern C(Class) * CO(FaceInfo);
extern C(Class) * CO(FillModeValue);
extern C(Class) * CO(Font);
extern C(Class) * CO(FontFlags);
extern C(Class) * CO(FontInfo);
extern C(Class) * CO(FontManager);
extern C(Class) * CO(FontManagerRenderer);
extern C(Class) * CO(FontRenderer);
extern C(Class) * CO(FontResource);
extern C(Class) * CO(GLCapabilities);
extern C(Class) * CO(GradientDirection);
extern C(Class) * CO(HitRecord);
extern C(Class) * CO(Light);
extern C(Class) * CO(LightFlags);
extern C(Class) * CO(PixelFormat);
extern C(Class) * CO(RenderState);
extern C(Class) * CO(RenderStateFloat);
extern C(Class) * CO(Resolution);
extern C(Class) * CO(Resource);
extern C(Class) * CO(Surface);
extern C(Class) * CO(SystemColor);
extern C(Class) * CO(CompiledDefaultShader);
extern C(Class) * CO(CompiledShader);
extern C(Class) * CO(DefaultShader);
extern C(Class) * CO(DefaultShaderBits);
extern C(Class) * CO(GLAB);
extern C(Class) * CO(GLBufferContents);
extern C(Class) * CO(GLBufferUsage);
extern C(Class) * CO(GLEAB);
extern C(Class) * CO(GLIMTKMode);
extern C(Class) * CO(GLMSWhatToGet);
extern C(Class) * CO(LFBDisplay);
extern C(Class) * CO(LFBDisplayDriver);
extern C(Class) * CO(LFBSurface);
extern C(Class) * CO(LFBSystem);
extern C(Class) * CO(LightMode);
extern C(Class) * CO(MatrixMode);
extern C(Class) * CO(Shader);
extern C(Class) * CO(SwizzleMode);
extern C(Class) * CO(Cube);
extern C(Class) * CO(SkyBox);
extern C(Class) * CO(Sphere);
extern C(Class) * CO(ColorPicker);
extern C(Class) * CO(CreateDirectoryDialog);
extern C(Class) * CO(FileDialog);
extern C(Class) * CO(FileDialogType);
extern C(Class) * CO(FileFilter);
extern C(Class) * CO(FileForceExtension);
extern C(Class) * CO(FileName);
extern C(Class) * CO(FileNameType);
extern C(Class) * CO(FileType);
extern C(Class) * CO(FindDialog);
extern C(Class) * CO(GoToDialog);
extern C(Class) * CO(MessageBox);
extern C(Class) * CO(MessageBoxType);
extern C(Class) * CO(ReplaceDialog);
extern C(Class) * CO(WindowList);
extern C(Class) * CO(BoxAlignment);
extern C(Class) * CO(BufferLocation);
extern C(Class) * CO(Button);
extern C(Class) * CO(ButtonState);
extern C(Class) * CO(CalendarControl);
extern C(Class) * CO(DataBox);
extern C(Class) * CO(DataDisplayFlags);
extern C(Class) * CO(DataField);
extern C(Class) * CO(DataRow);
extern C(Class) * CO(DirPath);
extern C(Class) * CO(DirectoriesBox);
extern C(Class) * CO(DropBox);
extern C(Class) * CO(EditBox);
extern C(Class) * CO(EditBoxFindResult);
extern C(Class) * CO(EditBoxStream);
extern C(Class) * CO(EditLine);
extern C(Class) * CO(EditableSelectorButton);
extern C(Class) * CO(FilePath);
extern C(Class) * CO(Label);
extern C(Class) * CO(ListBox);
extern C(Class) * CO(Menu);
extern C(Class) * CO(MenuDivider);
extern C(Class) * CO(MenuItem);
extern C(Class) * CO(MenuPlacement);
extern C(Class) * CO(OldArray);
extern C(Class) * CO(PaneSplitter);
extern C(Class) * CO(PathBox);
extern C(Class) * CO(PathTypeExpected);
extern C(Class) * CO(Picture);
extern C(Class) * CO(PopupMenu);
extern C(Class) * CO(ProgressBar);
extern C(Class) * CO(SavingDataBox);
extern C(Class) * CO(ScrollBar);
extern C(Class) * CO(ScrollBarAction);
extern C(Class) * CO(ScrollDirection);
extern C(Class) * CO(SelectorBar);
extern C(Class) * CO(SelectorButton);
extern C(Class) * CO(Stacker);
extern C(Class) * CO(StatusBar);
extern C(Class) * CO(StatusField);
extern C(Class) * CO(SyntaxColorScheme);
extern C(Class) * CO(Tab);
extern C(Class) * CO(TabControl);
extern C(Class) * CO(TabsPlacement);
extern C(Class) * CO(ToolBar);
extern C(Class) * CO(ToolButton);
extern C(Class) * CO(ToolSeparator);
extern C(Class) * CO(ToolTip);
extern C(Class) * CO(UndoAction);
extern C(Class) * CO(UndoBuffer);
extern C(Class) * CO(Anchor);
extern C(Class) * CO(AnchorValue);
extern C(Class) * CO(AnchorValueType);
extern C(Class) * CO(BorderBits);
extern C(Class) * CO(BorderStyle);
extern C(Class) * CO(ClipBoard);
extern C(Class) * CO(CommonControl);
extern C(Class) * CO(ControllableWindow);
extern C(Class) * CO(CreationActivationOption);
extern C(Class) * CO(Cursor);
extern C(Class) * CO(DialogResult);
extern C(Class) * CO(Extent);
extern C(Class) * CO(GuiApplication);
extern C(Class) * CO(Interface);
extern C(Class) * CO(Joystick);
extern C(Class) * CO(Key);
extern C(Class) * CO(KeyCode);
extern C(Class) * CO(MiddleAnchorValue);
extern C(Class) * CO(Modifiers);
extern C(Class) * CO(MouseButtons);
extern C(Class) * CO(MultiLineString);
extern C(Class) * CO(Percentage);
extern C(Class) * CO(PredefinedKey);
extern C(Class) * CO(SizeAnchor);
extern C(Class) * CO(Skin);
extern C(Class) * CO(SkinBitmap);
extern C(Class) * CO(SmartKey);
extern C(Class) * CO(SystemCursor);
extern C(Class) * CO(Timer);
extern C(Class) * CO(TouchPointerEvent);
extern C(Class) * CO(TouchPointerInfo);
extern C(Class) * CO(Window);
extern C(Class) * CO(WindowController);
extern C(Class) * CO(WindowState);
extern C(Class) * CO(TVisionSkin_Window);
extern C(Class) * CO(WindowsSkin_Button);
extern C(Class) * CO(WindowsSkin_Window);
extern C(Class) * CO(DCOMClientObject);
extern C(Class) * CO(DCOMSendControl);
extern C(Class) * CO(DCOMServerObject);
extern C(Class) * CO(DCOMServerSocket);
extern C(Class) * CO(DCOMService);
extern C(Class) * CO(DisconnectCode);
extern C(Class) * CO(FileServerConnection);
extern C(Class) * CO(HTTPFile);
extern C(Class) * CO(NetworkClientFile);
extern C(Class) * CO(Packet);
extern C(Class) * CO(SSLSocket);
extern C(Class) * CO(Service);
extern C(Class) * CO(Socket);
extern C(Class) * CO(SocketType);

C(Module) ecere_init(C(Module) fromModule);



#ifdef __cplusplus

};

#endif

#endif // !defined(__ECERE_H__)

