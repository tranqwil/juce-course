#include "Tremolo.h"

namespace tremolo {
class LfoVisualizer : public juce::Component {
    public:
    void paint (juce::Graphics& g) override {

        g.setColour(waveformColour);
        g.strokePath(line, juce::PathStrokeType(strokeWidth));
    }

    void resized() override {

        auto bounds = getLocalBounds();
        const auto halfHeight = bounds.getHeight() / 2;
        const auto amplitude = halfHeight - strokeWidth / 2;

        line.startNewSubPath(-2, halfHeight + amplitude * std::sin(0.f));

        for (const auto x : std::views::iota(-1, bounds.getWidth() + 2)) {

            switch (waveform) {
                case Tremolo::LfoWaveform::sine:
                    line.lineTo(x, halfHeight + amplitude * std::sin(0.1f * x));
                    break;
                case Tremolo::LfoWaveform::triangle:
                    line.lineTo(x, halfHeight + amplitude * Tremolo::triangle(0.1f * x));
                    break;

                default:
                    break;
            }
        }
    }

    void setLfoWaveform(Tremolo::LfoWaveform newWaveform) {
        if (newWaveform != waveform) {waveform = newWaveform;}
    }

    const float strokeWidth = 3.0f;
    juce::Path line;
    Tremolo::LfoWaveform waveform = Tremolo::LfoWaveform::triangle;
    juce::Colour waveformColour {juce::uint8{255}, juce::uint8{255}, juce::uint8{146}};

};
}