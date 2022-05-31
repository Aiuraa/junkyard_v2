/*
    Color-XD
    
    About:
    Useful for you who have 0 knowledge about converting your HBE value to colors
    Good for people who are watching Weponz Tutorial
    
    Credits:
    https://github.com/Aiuraa
    
    Copyright © 2022 Aiuraa
    
    Permission is hereby granted, free of charge, to any person obtaining a copy of this software
    and associated documentation files (the “Software”), to deal in the Software without 
    restriction, including without limitation the rights to use, copy, modify, merge, publish, 
    distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the 
    Software is furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in all copies or 
    substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
    BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/


// Include Guard
#if defined _inc_color_xd
    #undef _inc_color_xd
#endif

#if defined _INC_color_xd
    #endinput
#endif

#define _INC_color_xd

#if !defined string:
    #define string: 
#endif

#if !defined hex:
    #define hex:
#endif


/*
    Usage:
    #define MAX_ENERGY_COLORS 10 // if you want 10 colors per 10 value of your energy bar

    Notes:
    Add it into your gamemode before including color_xd
    Just don't mess with INTERNAL_ENERGY_COLOR_VALUE, thanks
*/
#if !defined MAX_ENERGY_COLORS
    #define MAX_ENERGY_COLORS 10
    #define INTERNAL_ENERGY_COLOR_VALUE 11
#endif

#if defined MAX_ENERGY_COLORS
    #define INTERNAL_ENERGY_COLOR_VALUE MAX_ENERGY_COLORS + 1
#endif

static stock gss_arrEnergyColors[INTERNAL_ENERGY_COLOR_VALUE] = {0xFFFFFF, ...};

/*
    Usage:
    new colors[MAX_ENERGY_COLORS + 1] = {0x00FF00, 0x00FF00, 0x00FF00, 0x00FF00, 0x00FF00, 0x00FF00, 0x00FF00, 0x00FF00, 0xFF0000, 0xFFFFFF};
    SetEnergyValueColor(colors);

    Notes:
    Always leave + 1 value.
*/
stock bool:SetEnergyValueColor(hex:colorValues[MAX_ENERGY_COLORS + 1])
{
    gss_arrEnergyColors = arrValues;
    return 1;
}

/*
    Usage:
    SetPlayerProgressBarColour(playerid, myBar, ConvertEnergyValueToColor(myEnergyValue));

    Notes:
    Only useful for this unfortunately.
*/
stock hex:ConvertEnergyValueToColor(Float:currentValue)
{
    new col = floatround(currentValue, floatround_round);

    // Fixing negative value and vale below 10 should be set as value 10 until 0
    // Because anything below 10 will be set to 0 by modulo operator (actually it's 0.5 but we're not writing floats here)
    col = ((col > MAX_ENERGY_COLORS) ? MAX_ENERGY_COLORS : ((5 <= col <= 10) ? 10 : max(col, 0)));
    return (gss_arrEnergyColors[col % 10]);
}

/*
    Usage:
    format(myTextDrawBarValueFormat, sizeof(myTextDrawBarValueFormat), "%s %d", myEnergyValue, ConvertEnergyValueToColorFormat(myEnergyValue));

    Notes:
    Sometimes, the result kinda wonky wungky, so yea what you're expecting from returning strings in pawn xd.
*/
stock string:ConvertEnergyValueToColorFormat(Float:currentValue)
{
    new col = ConvertEnergyValueToColor(currentValue), szOutput[24];
    format(szOutput, sizeof(szOutput), "{%x}", col);
    return szOutput;
}
