#pragma once

namespace tremolo {
class CustomLookAndFeel : public juce::LookAndFeel_V4 {
    public:
    CustomLookAndFeel();
    void drawToggleButton(juce::Graphics&, juce::ToggleButton&, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
    void drawRotarySlider(juce::Graphics&, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, juce::Slider&) override;
    void drawComboBox(juce::Graphics&, int width, int height, bool isButtonDown, int buttonX, int buttonY, int buttonW, int buttonH, juce::ComboBox&) override;

    // returns a label class that overrides paint() with a no op method. A label that cannot draw itself
    juce::Label* createComboBoxTextBox(juce::ComboBox&) override;

    void drawPopupMenuItem(
        juce::Graphics& g, const juce::Rectangle<int>& area,
        const bool isSeparator, const bool isActive,
        const bool isHighlighted, const bool isTicked,
        const bool hasSubMenu, const juce::String& text,
        const juce::String& shortcutKeyText,
        const juce::Drawable* icon, const juce::Colour* const textColourToUse) override;

    private:
    juce::Image rotarySliderImage;
    juce::Image bypassOnImage;
    juce::Image bypassOffImage;
    juce::Image shapeImage;

    //Colours
    juce::Colour colourActive {juce::uint8{255}, juce::uint8{255}, juce::uint8{146}};
    juce::Colour colourInactive{juce::uint8{114}, juce::uint8{114}, juce::uint8{114}};
};
}  // namespace tremolo
