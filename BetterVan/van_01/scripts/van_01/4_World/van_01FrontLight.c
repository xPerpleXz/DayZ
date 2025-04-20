class van_01FrontLight extends CarLightBase
{
	void van_01FrontLight()
	{
		m_SegregatedBrightness = 5;
		m_SegregatedRadius = 50;
		m_SegregatedAngle = 70;
		m_SegregatedColorRGB = Vector(1.0, 0.8, 0.8);
		
		m_AggregatedBrightness = 10;
		m_AggregatedRadius = 70;
		m_AggregatedAngle = 100;
		m_AggregatedColorRGB = Vector(1.0, 0.8, 0.8);
		
		FadeIn(0.3);
		SetFadeOutTime(0.25);
		
		SegregateLight();
	}
}