class van_01RearLight extends CarRearLightBase
{
	void van_01RearLight()
	{
		m_SegregatedBrakeBrightness = 1.9;
		m_SegregatedBrakeRadius = 5;
		m_SegregatedBrakeAngle = 190;
		m_SegregatedBrakeColorRGB = Vector(1, 0.6, 0.05);
		
		m_SegregatedBrightness = 1.8;
		m_SegregatedRadius = 7;
		m_SegregatedAngle = 140;
		m_SegregatedColorRGB = Vector(1.0, 1.0, 0.8);
		
		m_AggregatedBrightness = 1.9;
		m_AggregatedRadius = 9;
		m_AggregatedAngle = 140;
		m_AggregatedColorRGB = Vector(1, 0.8, 0.6);
		
		FadeIn(0.1);
		SetFadeOutTime(0.1);
		SetVisibleDuringDaylight(false);
		SetCastShadow(false);
		SetFlareVisible(false);
		
		SegregateLight();
	}
}