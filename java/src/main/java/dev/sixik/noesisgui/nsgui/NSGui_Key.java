package dev.sixik.noesisgui.nsgui;

public enum NSGui_Key {

    // Специальные клавиши
    NONE(0),
    CANCEL(1),
    BACK(2),
    TAB(3),
    LINE_FEED(4),
    CLEAR(5),
    RETURN(6),
    ENTER(6),           // Псевдоним для RETURN
    PAUSE(7),
    CAPITAL(8),
    CAPS_LOCK(8),       // Псевдоним для CAPITAL

    // IME клавиши
    KANA_MODE(9),
    HANGUL_MODE(9),     // Псевдоним для KANA_MODE
    JUNJA_MODE(10),
    FINAL_MODE(11),
    HANJA_MODE(12),
    KANJI_MODE(12),     // Псевдоним для HANJA_MODE

    ESCAPE(13),

    IME_CONVERT(14),
    IME_NON_CONVERT(15),
    IME_ACCEPT(16),
    IME_MODE_CHANGE(17),

    SPACE(18),

    // Навигационные клавиши
    PRIOR(19),
    PAGE_UP(19),        // Псевдоним для PRIOR
    NEXT(20),
    PAGE_DOWN(20),      // Псевдоним для NEXT
    END(21),
    HOME(22),

    // Стрелки
    LEFT(23),
    UP(24),
    RIGHT(25),
    DOWN(26),

    // Функциональные клавиши
    SELECT(27),
    PRINT(28),
    EXECUTE(29),
    SNAPSHOT(30),
    PRINT_SCREEN(30),   // Псевдоним для SNAPSHOT
    INSERT(31),
    DELETE(32),
    HELP(33),

    // Цифровые клавиши
    D0(34),
    D1(35),
    D2(36),
    D3(37),
    D4(38),
    D5(39),
    D6(40),
    D7(41),
    D8(42),
    D9(43),

    // Буквенные клавиши
    A(44),
    B(45),
    C(46),
    D(47),
    E(48),
    F(49),
    G(50),
    H(51),
    I(52),
    J(53),
    K(54),
    L(55),
    M(56),
    N(57),
    O(58),
    P(59),
    Q(60),
    R(61),
    S(62),
    T(63),
    U(64),
    V(65),
    W(66),
    X(67),
    Y(68),
    Z(69),

    // Клавиши Windows
    L_WIN(70),
    R_WIN(71),
    APPS(72),
    SLEEP(73),

    // Цифровая клавиатура
    NUMPAD0(74),
    NUMPAD1(75),
    NUMPAD2(76),
    NUMPAD3(77),
    NUMPAD4(78),
    NUMPAD5(79),
    NUMPAD6(80),
    NUMPAD7(81),
    NUMPAD8(82),
    NUMPAD9(83),

    NUMPAD_MULTIPLY(84),
    NUMPAD_ADD(85),
    NUMPAD_SEPARATOR(86),
    NUMPAD_SUBTRACT(87),
    NUMPAD_DECIMAL(88),
    NUMPAD_DIVIDE(89),

    // Функциональные клавиши F1-F24
    F1(90),
    F2(91),
    F3(92),
    F4(93),
    F5(94),
    F6(95),
    F7(96),
    F8(97),
    F9(98),
    F10(99),
    F11(100),
    F12(101),
    F13(102),
    F14(103),
    F15(104),
    F16(105),
    F17(106),
    F18(107),
    F19(108),
    F20(109),
    F21(110),
    F22(111),
    F23(112),
    F24(113),

    NUM_LOCK(114),
    SCROLL(115),

    // Модификаторы
    LEFT_SHIFT(116),
    RIGHT_SHIFT(117),
    LEFT_CTRL(118),
    RIGHT_CTRL(119),
    LEFT_ALT(120),
    RIGHT_ALT(121),

    // Браузерные клавиши
    BROWSER_BACK(122),
    BROWSER_FORWARD(123),
    BROWSER_REFRESH(124),
    BROWSER_STOP(125),
    BROWSER_SEARCH(126),
    BROWSER_FAVORITES(127),
    BROWSER_HOME(128),

    // Медиа клавиши
    VOLUME_MUTE(129),
    VOLUME_DOWN(130),
    VOLUME_UP(131),

    MEDIA_NEXT_TRACK(132),
    MEDIA_PREVIOUS_TRACK(133),
    MEDIA_STOP(134),
    MEDIA_PLAY_PAUSE(135),

    LAUNCH_MAIL(136),
    SELECT_MEDIA(137),
    LAUNCH_APPLICATION1(138),
    LAUNCH_APPLICATION2(139),

    // OEM клавиши
    OEM1(140),
    OEM_SEMICOLON(140),     // Псевдоним для OEM1
    OEM_PLUS(141),
    OEM_COMMA(142),
    OEM_MINUS(143),
    OEM_PERIOD(144),
    OEM2(145),
    OEM_QUESTION(145),      // Псевдоним для OEM2
    OEM3(146),
    OEM_TILDE(146),         // Псевдоним для OEM3
    ABNT_C1(147),
    ABNT_C2(148),
    OEM4(149),
    OEM_OPEN_BRACKETS(149), // Псевдоним для OEM4
    OEM5(150),
    OEM_PIPE(150),          // Псевдоним для OEM5
    OEM6(151),
    OEM_CLOSE_BRACKETS(151),// Псевдоним для OEM6
    OEM7(152),
    OEM_QUOTES(152),        // Псевдоним для OEM7
    OEM8(153),
    OEM102(154),
    OEM_BACKSLASH(154),     // Псевдоним для OEM102

    IME_PROCESSED(155),
    SYSTEM(156),

    OEM_ATTN(157),
    DBE_ALPHANUMERIC(157),  // Псевдоним для OEM_ATTN
    OEM_FINISH(158),
    DBE_KATAKANA(158),      // Псевдоним для OEM_FINISH
    OEM_COPY(159),
    DBE_HIRAGANA(159),      // Псевдоним для OEM_COPY
    OEM_AUTO(160),
    DBE_SBCS_CHAR(160),     // Псевдоним для OEM_AUTO
    OEM_ENLW(161),
    DBE_DBCS_CHAR(161),     // Псевдоним для OEM_ENLW
    OEM_BACK_TAB(162),
    DBE_ROMAN(162),         // Псевдоним для OEM_BACK_TAB
    ATTN(163),
    DBE_NO_ROMAN(163),      // Псевдоним для ATTN
    CR_SEL(164),
    DBE_ENTER_WORD_REGISTER_MODE(164), // Псевдоним для CR_SEL
    EX_SEL(165),
    DBE_ENTER_IME_CONFIGURE_MODE(165), // Псевдоним для EX_SEL
    ERASE_EOF(166),
    DBE_FLUSH_STRING(166),  // Псевдоним для ERASE_EOF
    PLAY(167),
    DBE_CODE_INPUT(167),    // Псевдоним для PLAY
    ZOOM(168),
    DBE_NO_CODE_INPUT(168), // Псевдоним для ZOOM
    NO_NAME(169),
    DBE_DETERMINE_STRING(169), // Псевдоним для NO_NAME
    PA1(170),
    DBE_ENTER_DIALOG_CONVERSION_MODE(170), // Псевдоним для PA1
    OEM_CLEAR(171),
    DEAD_CHAR_PROCESSED(172),

    // Дополнительные навигационные
    PAGE_LEFT(173),
    PAGE_RIGHT(174),

    // Gamepad клавиши
    GAMEPAD_LEFT(175),
    GAMEPAD_UP(176),
    GAMEPAD_RIGHT(177),
    GAMEPAD_DOWN(178),
    GAMEPAD_ACCEPT(179),
    GAMEPAD_CANCEL(180),
    GAMEPAD_MENU(181),
    GAMEPAD_VIEW(182),
    GAMEPAD_PAGE_UP(183),
    GAMEPAD_PAGE_DOWN(184),
    GAMEPAD_PAGE_LEFT(185),
    GAMEPAD_PAGE_RIGHT(186),
    GAMEPAD_CONTEXT1(187),
    GAMEPAD_CONTEXT2(188),
    GAMEPAD_CONTEXT3(189),
    GAMEPAD_CONTEXT4(190),

    // Специальное значение - количество элементов
    COUNT(191);

    public final int value;

    NSGui_Key(int value) {
        this.value = value;
    }
}
