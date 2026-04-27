void Elastic()

{

	// Opening of the ROOT file into reading mode

	TFile *file = new TFile("Elastic.root", "READ");

	// Accesing of the specific simulated data tree

	TTree *tree = (TTree*)file->Get("SimulatedTree");

	// Creating the blank canvas to the empty canvas

	TCanvas *c1 = new TCanvas("c1", "Energy Spectrum", 1200, 600);

	// Drawing the specific energy branch

	tree->Draw("AnnularS3.fS3_Theta_E_Energy");

	// Forcing the ROOT to draw the plot into the memory first to shift the statistics box

	c1->Update();

	// Grabbing the temporary histogram created by the ROOT 

	TH1F *htemp = (TH1F*)gPad->GetPrimitive("htemp");

	// Decoration of the plot

	 if (htemp) 

{

		// Setting the main plot title

		htemp->SetTitle("Simulated Elastic Energy Spectrum");

		// Setting the X-axis title

		htemp->GetXaxis()->SetTitle("Energy (MeV)");

		// Setting the Y-axis title

		htemp->GetYaxis()->SetTitle("Counts");

		// Making the line thicker in PDF

		htemp->SetLineWidth(2) ;

		// Hiding the 'htemp' header
		
		// 1110 : 1 for "standard deviation", 1 for "Mean", 1 for Entries, 0 for "htemp" header

		gStyle->SetOptStat(1110);

		// Finding the statistic box attached with this plot

		TPaveStats *stats = (TPaveStats*)htemp->FindObject("stats");

		// Using the normalized coordinates to shift the statistics box to the left

		if (stats)
{

		// Fixing the X Coordinates

		stats->SetX1NDC(0.15); // Left edge at 15% of the screen
		stats->SetX2NDC(0.35); // Right edge at 35% of the screen

		// Fixing the Y Coordinates

		stats->SetY1NDC(0.75);
		stats->SetY2NDC(0.88);

}

	// Modification of the plot to shift the statistics box with new coordinates

		c1->Modified();
		c1->Update();

}


	// Saving the mentioned plot into Vector PDF

	c1->SaveAs("ElasticEnergy.pdf");

	// Closing of the ROOT file after work done

	file->Close();

}


