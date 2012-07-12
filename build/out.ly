
\version "2.12.3"
% automatically converted from out.xml

\header {
    encodingsoftware = "MusicXML Library v2"
    tagline = "MusicXML Library v2"
    title = "(title)_A Lesson"
    }

PartPOneVoiceOne =  \relative c'' {
    \clef "treble" \key c \major \numericTimeSignature\time 4/4 c8 e8
    g,,2 e'8 a'8 | % 2
    g,,4 d'8 d'2 e,16 f16 | % 3
    g'4 a,,8 d8 a'4 c4 | % 4
    f,2 g'4 g,8 c16 a'16 | % 5
    f,2 d4 f8 a,8 | % 6
    f'4 g,4 d''2 | % 7
    a,4 c2 c'8 d,8 | % 8
    g'4 b,4 b4 a4 | % 9
    g'4 g,4 a'8 g4 d8 | \barNumberCheck #10
    g,16 c,4 a''4 b,8 d4 f,16 | % 11
    g2 c,4 a'4 | % 12
    g'8 g8 c,8 g4 e4 g,8 | % 13
    a''8 g,16 g16 e4 b2 | % 14
    a'4 f8 d4 d'4 f,8 | % 15
    a,4 b'4 a4 e8 d8 }


% The score definition
\new Staff <<
    \set Staff.instrumentName = "(part name)"
    \context Staff << 
        \context Voice = "PartPOneVoiceOne" { \PartPOneVoiceOne }
        >>
    >>

