namespace tremolo {

CustomLookAndFeel::CustomLookAndFeel() : juce::LookAndFeel_V4()
{
    rotarySliderImage = juce::ImageCache::getFromMemory(assets::RotarySlider_png, assets::RotarySlider_pngSize);
    bypassOffImage = juce::ImageCache::getFromMemory(assets::BypassOff_png, assets::BypassOff_pngSize);
    bypassOnImage = juce::ImageCache::getFromMemory(assets::BypassOn_png, assets::BypassOn_pngSize);
    shapeImage = juce::ImageCache::getFromMemory(assets::Shape_png, assets::Shape_pngSize);

    setColour(juce::PopupMenu::backgroundColourId, juce::Colours::black);
    setColour(juce::PopupMenu::textColourId, colourInactive);
    setColour(juce::PopupMenu::highlightedTextColourId, juce::Colours::white);

    jassert(rotarySliderImage.isValid());
    jassert(bypassOffImage.isValid());
    jassert(bypassOnImage.isValid());
    jassert(shapeImage.isValid());


}

void CustomLookAndFeel::drawToggleButton(juce::Graphics& g, juce::ToggleButton& button,
                                       bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    g.drawImage(
        button.getToggleState() ? bypassOnImage : bypassOffImage,
        0,
        0,
        button.getWidth(),
        button.getHeight(),
        0,
        0,
        bypassOnImage.getWidth(),
        bypassOnImage.getHeight()
        );




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

void CustomLookAndFeel::drawComboBox(juce::Graphics& g, int width, int height, bool isButtonDown, int buttonX,
    int buttonY, int buttonW, int buttonH, juce::ComboBox& combo_box)
{
    g.drawImage(
        shapeImage,
        0,
        0,
        combo_box.getWidth(),
        combo_box.getHeight(),
        0,
        0,
        shapeImage.getWidth(),
        shapeImage.getHeight()
        );

}

juce::Label* CustomLookAndFeel::createComboBoxTextBox(juce::ComboBox&)
{
    struct InvisibleLabel : public juce::Label
    {
        void paint (juce::Graphics&) override {} // deliberately empty — draws nothing
    };

    auto* l = new InvisibleLabel();
    return l;
}

void CustomLookAndFeel::drawPopupMenuItem(juce::Graphics& g, const juce::Rectangle<int>& area,
                                        const bool isSeparator, const bool isActive,
                                        const bool isHighlighted, const bool isTicked,
                                        const bool hasSubMenu, const juce::String& text,
                                        const juce::String& shortcutKeyText,
                                        const juce::Drawable* icon, const juce::Colour* const textColourToUse)
{
    if (isSeparator)
    {
        auto r  = area.reduced (5, 0);
        r.removeFromTop (juce::roundToInt (((float) r.getHeight() * 0.5f) - 0.5f));

        g.setColour (findColour (juce::PopupMenu::textColourId).withAlpha (0.3f));
        g.fillRect (r.removeFromTop (1));
    }
    else
    {
        auto textColour = (textColourToUse == nullptr ? findColour (juce::PopupMenu::textColourId)
                                                      : *textColourToUse);

        auto r  = area.reduced (1);

        if (isHighlighted && isActive)
        {
            g.setColour (findColour (juce::PopupMenu::highlightedBackgroundColourId));
            g.fillRect (r);

            g.setColour (findColour (juce::PopupMenu::highlightedTextColourId));
        }
        else
        {
            g.setColour (textColour.withMultipliedAlpha (isActive ? 1.0f : 0.5f));
        }

        r.reduce (juce::jmin (5, area.getWidth() / 20), 0);

        auto font = getPopupMenuFont();

        auto maxFontHeight = (float) r.getHeight() / 1.3f;

        if (font.getHeight() > maxFontHeight)
            font.setHeight (maxFontHeight);

        g.setFont (font);

        auto iconArea = r.removeFromLeft (juce::roundToInt (maxFontHeight)).toFloat();

        if (icon != nullptr)
        {
            icon->drawWithin (g, iconArea, juce::RectanglePlacement::centred | juce::RectanglePlacement::onlyReduceInSize, 1.0f);
            r.removeFromLeft (juce::roundToInt (maxFontHeight * 0.5f));
        }
        else if (isTicked)
        {
            // // auto tick = getTickShape (1.0f);
            // // g.fillPath (tick, tick.getTransformToScaleToFit (iconArea.reduced (iconArea.getWidth() / 5, 0).toFloat(), true));
            g.setColour (colourActive);
        }

        if (hasSubMenu)
        {
            auto arrowH = 0.6f * getPopupMenuFont().getAscent();

            auto x = static_cast<float> (r.removeFromRight ((int) arrowH).getX());
            auto halfH = static_cast<float> (r.getCentreY());

            juce::Path path;
            path.startNewSubPath (x, halfH - arrowH * 0.5f);
            path.lineTo (x + arrowH * 0.6f, halfH);
            path.lineTo (x, halfH + arrowH * 0.5f);

            g.strokePath (path, juce::PathStrokeType (2.0f));
        }

        r.removeFromRight (3);
        g.drawFittedText (text, r, juce::Justification::centredLeft, 1);

        if (shortcutKeyText.isNotEmpty())
        {
            auto f2 = font;
            f2.setHeight (f2.getHeight() * 0.75f);
            f2.setHorizontalScale (0.95f);
            g.setFont (f2);

            g.drawText (shortcutKeyText, r, juce::Justification::centredRight, true);
        }
    }

}


}  // namespace tremolo
