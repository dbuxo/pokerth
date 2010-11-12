
package pokerth_protocol;
//
// This file was generated by the BinaryNotes compiler.
// See http://bnotes.sourceforge.net 
// Any modifications to this file will be lost upon recompilation of the source ASN.1. 
//

import org.bn.*;
import org.bn.annotations.*;
import org.bn.annotations.constraints.*;
import org.bn.coders.*;
import org.bn.types.*;




    @ASN1PreparedElement
    @ASN1Sequence ( name = "PlainCards", isSet = false )
    public class PlainCards implements IASN1PreparedElement {
            
        @ASN1Element ( name = "plainCard1", isOptional =  false , hasTag =  false  , hasDefaultValue =  false  )
    
	private Card plainCard1 = null;
                
  
        @ASN1Element ( name = "plainCard2", isOptional =  false , hasTag =  false  , hasDefaultValue =  false  )
    
	private Card plainCard2 = null;
                
  
        
        public Card getPlainCard1 () {
            return this.plainCard1;
        }

        

        public void setPlainCard1 (Card value) {
            this.plainCard1 = value;
        }
        
  
        
        public Card getPlainCard2 () {
            return this.plainCard2;
        }

        

        public void setPlainCard2 (Card value) {
            this.plainCard2 = value;
        }
        
  
                    
        
        public void initWithDefaults() {
            
        }

        private static IASN1PreparedElementData preparedData = CoderFactory.getInstance().newPreparedElementData(PlainCards.class);
        public IASN1PreparedElementData getPreparedData() {
            return preparedData;
        }

            
    }
            