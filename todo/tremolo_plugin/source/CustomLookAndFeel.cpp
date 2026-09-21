namespace tremolo {

CustomLookAndFeel::CustomLookAndFeel() : juce::LookAndFeel_V4()
{
    rotarySliderImage = juce::ImageCache::getFromMemory(assets::RotarySlider_png, assets::RotarySlider_pngSize);
    jassert(rotarySliderImage.isValid());

}

void CustomLookAndFeel::drawToggleButton(juce::Graphics& g, juce::ToggleButton& button,
                                       bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{


}

void CustomLookAndFeel::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                                       const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider)
{
    const float rotationNorm = (slider.getValue()
            - slider.getMinimum())
            / (slider.getMaximum()
                - slider.getMinimum());

    const float radians = rotationNorm * (2 * juce::MathConstants<double>::pi);
    float centerX = rotarySliderImage.getWidth() / 2.0f;
    float centerY = rotarySliderImage.getHeight() / 2.0f;

    juce::AffineTransform rotation = juce::AffineTransform::rotation(radians, centerX, centerY);
    g.addTransform(rotation);
    g.drawImageAt(rotarySliderImage, x, y);











}
}  // namespace tremolo
