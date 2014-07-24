#!/usr/bin/env Rscript

rsdev0280 <- read.table("coh_carbon_splines_RS280_nu.txt", header=TRUE, comment.char='#');
rsdev4141 <- read.table("coh_carbon_splines_RSDEV4141_nu.txt", header=TRUE, comment.char='#');
bsdev4141 <- read.table("coh_carbon_splines_BSDEV4141_nu.txt", header=TRUE, comment.char='#');

meter <- 5.07e+15;  # 5.07e+15 / GeV
centimeter <- 0.01 * meter;
cm2 = centimeter * centimeter;
mb = 1e-31 * meter * meter;
# print(cm2);
# print(mb)

pdftitle <- sprintf("integ_comp_all.pdf");
pdf( pdftitle );
leglabels <- c(
  "RS 280",
  "RS 4141",
  "BS 4141"
  );
plot(rsdev0280$Energy, (rsdev0280$CrossSection)/cm2
  ,main="Coherent Pion Neutrino"
  ,xlab="Energy (GeV)"
  ,ylab=NA
  ,log="xy"
  ,col="red"
  ,lty=1
  ,lwd=3
  ,type="l"
  ,xlim=c(0.1,1000.0)
  ,ylim=c(1e-42,5e-38)
  );
grid();
mtext(side=2, expression(paste("Cross Section (cm"^"2)")), line=2);
lines(rsdev4141$Energy, (rsdev4141$CrossSection)/cm2
  ,col="green"
  ,lty=3
  ,lwd=3
  ,type="l"
  );
lines(bsdev4141$Energy, (bsdev4141$CrossSection)/cm2
  ,col="brown"
  ,lty=5
  ,lwd=3
  ,type="l"
  );
legend(x=0.1,y=4e-38,legend=leglabels,fill=c("red","green","brown"),lty=c(1,3,5));
dev.off();

pdftitle <- sprintf("integ_comp_all_zoom.pdf");
pdf( pdftitle );
leglabels <- c(
  "RS 280",
  "RS 4141",
  "BS 4141"
  );
plot(rsdev0280$Energy, (rsdev0280$CrossSection)/cm2
  ,main="Coherent Pion Neutrino"
  ,xlab="Energy (GeV)"
  ,ylab=NA
  ,col="red"
  ,lty=1
  ,lwd=3
  ,type="l"
  ,xlim=c(0.4,2.0)
  ,ylim=c(1e-42,30e-40)
  );
grid();
mtext(side=2, expression(paste("Cross Section (cm"^"2)")), line=2);
lines(rsdev4141$Energy, (rsdev4141$CrossSection)/cm2
  ,col="green"
  ,lty=3
  ,lwd=3
  ,type="l"
  );
lines(bsdev4141$Energy, (bsdev4141$CrossSection)/cm2
  ,col="brown"
  ,lty=5
  ,lwd=3
  ,type="l"
  );
legend(x=0.7,y=2e-39,legend=leglabels,fill=c("red","green","brown"),lty=c(1,3,5));
dev.off();

