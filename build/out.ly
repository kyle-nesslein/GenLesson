
\version "2.14.2"
% automatically converted from out.xml

\header {
    encodingsoftware = "MusicXML Library v2"
    tagline = "MusicXML Library v2"
    title = "(title)_A Lesson"
    }

PartPOneVoiceOne =  \relative e' {
    \clef "treble" \key c \major \numericTimeSignature\time 4/4 e2 g4 a16
    d8 a,16 | % 2
    c8 e'2 c,4 f8 | % 3
    d16 b8 g'4 b,4 f'4 c16 | % 4
    f4 b,8 g'4 c4 f,8 | % 5
    b,16 g2 e'16 b'16 e4 c16 | % 6
    g16 c4 g4 c,16 b'16 c4 c16 | % 7
    g,2 c4 a''8 g,,16 g''16 | % 8
    c,8 b8 b,8 a'8 a8 b,16 e8 c16 a8 | % 9
    g''2 c,8 d,4 b'8 | \barNumberCheck #10
    d4 a,4 b'4 c,8 g'16 e'16 | % 11
    g,,2 g''4 c,16 g,8 e''16 | % 12
    f,16 b,8 e'2 b16 g,16 g'16 c8 | % 13
    a2 b,8 g'8 a4 | % 14
    c,16 a16 c'4 a'16 d,,4 g,16 a''16 d,,16 b'8 | % 15
    e16 g8 e,16 d'16 g4 c,16 g,4 c'16 e16 | % 16
    g,,4 c'2 g4 }


% The score definition
\new Staff <<
    \set Staff.instrumentName = "(part name)"
    \context Staff << 
        \context Voice = "PartPOneVoiceOne" { \PartPOneVoiceOne }
        >>
    >>

