public enum DigitalName: Int32 {
    case D0 = 49, D1 = 48, D2 = 41, D3 = 40, D4 = 3, D5 = 2, D6 = 1, D7 = 0, D8 = 43, D9 = 42, D10 = 39, D11 = 38, D12 = 15, D13 = 14
    case D14 = 19, D15 = 18, D16 = 31, D17 = 30, D18 = 29, D19 = 28, D20 = 27, D21 = 26, D22 = 25, D23 = 24, D24 = 20, D25 = 21
    case D26 = 51, D27 = 50, D28 = 47, D29 = 46, D30 = 45, D31 = 44, D32 = 37, D33 = 36, D34 = 63, D35 = 35, D36 = 34, D37 = 33, D38 = 32
    case D39 = 59, D40 = 58, D41 = 57, D42 = 56, D43 = 55, D44 = 54, D45 = 53, D46 = 52
}

public enum OutputMode: Int32 {
	case pushPull = 0, openDrain
}

public enum InputMode: Int32 {
	case pullDown = 2, pullUp, float
}


public enum RGBLEDColor: Int32 {
	case red = 9, green = 10, blue = 11
}
